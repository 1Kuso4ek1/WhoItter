#include "Controllers/PostsController.hpp"

#include "Models/Posts.hpp"
#include "Models/Users.hpp"

namespace Models = drogon_model::whoitter;

namespace Controllers
{

void PostsController::createPost(const HttpRequestPtr& req, Callback&& callback)
{
    const auto& body = req->getJsonObject();

    if(!body || (body && (*body)["content"].asString().empty()))
    {
        LOG_ERROR << "Invalid request body for creating a post";

        callback(HttpResponse::newHttpResponse(k400BadRequest, CT_NONE));
        return;
    }

    static auto mapper = orm::Mapper<Models::Posts>(app().getDbClient());

    const auto selfId = std::stoi(req->getParameter("user_id"));

    Models::Posts post;
    post.setUserId(selfId);
    post.setContent((*body)["content"].asString());

    try
    {
        mapper.insert(post);
    }
    catch(...)
    {
        LOG_ERROR << "Failed to create post for user: " << selfId;

        callback(HttpResponse::newHttpResponse(k500InternalServerError, CT_NONE));
        return;
    }

    callback(HttpResponse::newHttpJsonResponse(post.toJson()));
}

void PostsController::deletePost(const HttpRequestPtr& req, Callback&& callback, const int postId)
{
    static auto mapper = orm::Mapper<Models::Posts>(app().getDbClient());

    try
    {
        mapper.deleteBy(
            orm::Criteria{ "id", postId }
            && orm::Criteria{ "user_id", req->getParameter("user_id") }
        );

        callback(HttpResponse::newHttpResponse(k204NoContent, CT_NONE));
    }
    catch(...)
    {
        LOG_ERROR << "Failed to delete post: " << postId;

        callback(HttpResponse::newHttpResponse(k500InternalServerError, CT_NONE));
    }
}

void PostsController::getFeed(
    const HttpRequestPtr& req, Callback&& callback,
    const int limit, const int offset
)
{
    static const auto& dbClient = app().getDbClient();
    static auto mapper = orm::Mapper<Models::Posts>(dbClient);

    const auto selfId = std::stoi(req->getParameter("user_id"));

    try
    {
        // For the sake of simplicity, get all available posts
        const auto posts = mapper
            .orderBy("created_at", orm::SortOrder::DESC)
            .limit(limit > 0 ? limit : 20)
            .offset(offset)
            .findAll();

        Json::Value json;
        for(const auto& i : posts)
        {
            json.append(i.toJson());
            json.back()["user"] = i.getUser(dbClient).toJson();
        }

        callback(HttpResponse::newHttpJsonResponse(json));
    }
    catch(...)
    {
        LOG_ERROR << "Error getting feed posts for user: " << selfId;

        callback(HttpResponse::newHttpResponse(k500InternalServerError, CT_NONE));
    }
}

void PostsController::getUserPosts(
    const HttpRequestPtr& req, Callback&& callback,
    const int userId, const int limit, const int offset
)
{
    static auto mapper = orm::Mapper<Models::Posts>(app().getDbClient());

    try
    {
        const auto posts = mapper
            .orderBy("created_at", orm::SortOrder::DESC)
            .limit(limit > 0 ? limit : 20)
            .offset(offset)
            .findBy({ "user_id", userId });

        Json::Value json;
        for(const auto& i : posts)
            json.append(i.toJson());

        callback(HttpResponse::newHttpJsonResponse(json));
    }
    catch(...)
    {
        LOG_ERROR << "Error getting posts for user: " << userId;

        callback(HttpResponse::newHttpResponse(k500InternalServerError, CT_NONE));
    }
}

}
