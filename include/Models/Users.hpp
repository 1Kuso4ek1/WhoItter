/**
 *
 *  Users.h
 *  DO NOT EDIT. This file is generated by drogon_ctl
 *
 */

#pragma once
#include <drogon/orm/Result.h>
#include <drogon/orm/Row.h>
#include <drogon/orm/Field.h>
#include <drogon/orm/SqlBinder.h>
#include <drogon/orm/Mapper.h>
#include <drogon/orm/BaseBuilder.h>
#ifdef __cpp_impl_coroutine
#include <drogon/orm/CoroMapper.h>
#endif
#include <trantor/utils/Date.h>
#include <trantor/utils/Logger.h>
#include <json/json.h>
#include <string>
#include <string_view>
#include <memory>
#include <vector>
#include <tuple>
#include <stdint.h>
#include <iostream>

namespace drogon
{
namespace orm
{
class DbClient;
using DbClientPtr = std::shared_ptr<DbClient>;
}
}
namespace drogon_model
{
namespace whoitter
{
class Follows;
class Likes;
class Posts;

class Users
{
  public:
    struct Cols
    {
        static const std::string _id;
        static const std::string _username;
        static const std::string _display_name;
        static const std::string _avatar_url;
        static const std::string _oauth_id;
    };

    static const int primaryKeyNumber;
    static const std::string tableName;
    static const bool hasPrimaryKey;
    static const std::string primaryKeyName;
    using PrimaryKeyType = int32_t;
    const PrimaryKeyType &getPrimaryKey() const;

    /**
     * @brief constructor
     * @param r One row of records in the SQL query result.
     * @param indexOffset Set the offset to -1 to access all columns by column names,
     * otherwise access all columns by offsets.
     * @note If the SQL is not a style of 'select * from table_name ...' (select all
     * columns by an asterisk), please set the offset to -1.
     */
    explicit Users(const drogon::orm::Row &r, const ssize_t indexOffset = 0) noexcept;

    /**
     * @brief constructor
     * @param pJson The json object to construct a new instance.
     */
    explicit Users(const Json::Value &pJson) noexcept(false);

    /**
     * @brief constructor
     * @param pJson The json object to construct a new instance.
     * @param pMasqueradingVector The aliases of table columns.
     */
    Users(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false);

    Users() = default;

    void updateByJson(const Json::Value &pJson) noexcept(false);
    void updateByMasqueradedJson(const Json::Value &pJson,
                                 const std::vector<std::string> &pMasqueradingVector) noexcept(false);
    static bool validateJsonForCreation(const Json::Value &pJson, std::string &err);
    static bool validateMasqueradedJsonForCreation(const Json::Value &,
                                                const std::vector<std::string> &pMasqueradingVector,
                                                    std::string &err);
    static bool validateJsonForUpdate(const Json::Value &pJson, std::string &err);
    static bool validateMasqueradedJsonForUpdate(const Json::Value &,
                                          const std::vector<std::string> &pMasqueradingVector,
                                          std::string &err);
    static bool validJsonOfField(size_t index,
                          const std::string &fieldName,
                          const Json::Value &pJson,
                          std::string &err,
                          bool isForCreation);

    /**  For column id  */
    ///Get the value of the column id, returns the default value if the column is null
    const int32_t &getValueOfId() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<int32_t> &getId() const noexcept;
    ///Set the value of the column id
    void setId(const int32_t &pId) noexcept;

    /**  For column username  */
    ///Get the value of the column username, returns the default value if the column is null
    const std::string &getValueOfUsername() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getUsername() const noexcept;
    ///Set the value of the column username
    void setUsername(const std::string &pUsername) noexcept;
    void setUsername(std::string &&pUsername) noexcept;

    /**  For column display_name  */
    ///Get the value of the column display_name, returns the default value if the column is null
    const std::string &getValueOfDisplayName() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getDisplayName() const noexcept;
    ///Set the value of the column display_name
    void setDisplayName(const std::string &pDisplayName) noexcept;
    void setDisplayName(std::string &&pDisplayName) noexcept;
    void setDisplayNameToNull() noexcept;

    /**  For column avatar_url  */
    ///Get the value of the column avatar_url, returns the default value if the column is null
    const std::string &getValueOfAvatarUrl() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getAvatarUrl() const noexcept;
    ///Set the value of the column avatar_url
    void setAvatarUrl(const std::string &pAvatarUrl) noexcept;
    void setAvatarUrl(std::string &&pAvatarUrl) noexcept;
    void setAvatarUrlToNull() noexcept;

    /**  For column oauth_id  */
    ///Get the value of the column oauth_id, returns the default value if the column is null
    const std::string &getValueOfOauthId() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getOauthId() const noexcept;
    ///Set the value of the column oauth_id
    void setOauthId(const std::string &pOauthId) noexcept;
    void setOauthId(std::string &&pOauthId) noexcept;
    void setOauthIdToNull() noexcept;


    static size_t getColumnNumber() noexcept {  return 5;  }
    static const std::string &getColumnName(size_t index) noexcept(false);

    Json::Value toJson() const;
    Json::Value toMasqueradedJson(const std::vector<std::string> &pMasqueradingVector) const;
    /// Relationship interfaces
    std::vector<Posts> getPost(const drogon::orm::DbClientPtr &clientPtr) const;
    void getPost(const drogon::orm::DbClientPtr &clientPtr,
                 const std::function<void(std::vector<Posts>)> &rcb,
                 const drogon::orm::ExceptionCallback &ecb) const;
    std::vector<Likes> getLike(const drogon::orm::DbClientPtr &clientPtr) const;
    void getLike(const drogon::orm::DbClientPtr &clientPtr,
                 const std::function<void(std::vector<Likes>)> &rcb,
                 const drogon::orm::ExceptionCallback &ecb) const;
    std::vector<Follows> getFollow(const drogon::orm::DbClientPtr &clientPtr) const;
    void getFollow(const drogon::orm::DbClientPtr &clientPtr,
                   const std::function<void(std::vector<Follows>)> &rcb,
                   const drogon::orm::ExceptionCallback &ecb) const;
    std::vector<Follows> getFollowee(const drogon::orm::DbClientPtr &clientPtr) const;
    void getFollowee(const drogon::orm::DbClientPtr &clientPtr,
                     const std::function<void(std::vector<Follows>)> &rcb,
                     const drogon::orm::ExceptionCallback &ecb) const;
  private:
    friend drogon::orm::Mapper<Users>;
    friend drogon::orm::BaseBuilder<Users, true, true>;
    friend drogon::orm::BaseBuilder<Users, true, false>;
    friend drogon::orm::BaseBuilder<Users, false, true>;
    friend drogon::orm::BaseBuilder<Users, false, false>;
#ifdef __cpp_impl_coroutine
    friend drogon::orm::CoroMapper<Users>;
#endif
    static const std::vector<std::string> &insertColumns() noexcept;
    void outputArgs(drogon::orm::internal::SqlBinder &binder) const;
    const std::vector<std::string> updateColumns() const;
    void updateArgs(drogon::orm::internal::SqlBinder &binder) const;
    ///For mysql or sqlite3
    void updateId(const uint64_t id);
    std::shared_ptr<int32_t> id_;
    std::shared_ptr<std::string> username_;
    std::shared_ptr<std::string> displayName_;
    std::shared_ptr<std::string> avatarUrl_;
    std::shared_ptr<std::string> oauthId_;
    struct MetaData
    {
        const std::string colName_;
        const std::string colType_;
        const std::string colDatabaseType_;
        const ssize_t colLength_;
        const bool isAutoVal_;
        const bool isPrimaryKey_;
        const bool notNull_;
    };
    static const std::vector<MetaData> metaData_;
    bool dirtyFlag_[5]={ false };
  public:
    static const std::string &sqlForFindingByPrimaryKey()
    {
        static const std::string sql="select * from " + tableName + " where id = $1";
        return sql;
    }

    static const std::string &sqlForDeletingByPrimaryKey()
    {
        static const std::string sql="delete from " + tableName + " where id = $1";
        return sql;
    }
    std::string sqlForInserting(bool &needSelection) const
    {
        std::string sql="insert into " + tableName + " (";
        size_t parametersCount = 0;
        needSelection = false;
            sql += "id,";
            ++parametersCount;
        if(dirtyFlag_[1])
        {
            sql += "username,";
            ++parametersCount;
        }
        if(dirtyFlag_[2])
        {
            sql += "display_name,";
            ++parametersCount;
        }
        if(dirtyFlag_[3])
        {
            sql += "avatar_url,";
            ++parametersCount;
        }
        if(dirtyFlag_[4])
        {
            sql += "oauth_id,";
            ++parametersCount;
        }
        needSelection=true;
        if(parametersCount > 0)
        {
            sql[sql.length()-1]=')';
            sql += " values (";
        }
        else
            sql += ") values (";

        int placeholder=1;
        char placeholderStr[64];
        size_t n=0;
        sql +="default,";
        if(dirtyFlag_[1])
        {
            n = snprintf(placeholderStr,sizeof(placeholderStr),"$%d,",placeholder++);
            sql.append(placeholderStr, n);
        }
        if(dirtyFlag_[2])
        {
            n = snprintf(placeholderStr,sizeof(placeholderStr),"$%d,",placeholder++);
            sql.append(placeholderStr, n);
        }
        if(dirtyFlag_[3])
        {
            n = snprintf(placeholderStr,sizeof(placeholderStr),"$%d,",placeholder++);
            sql.append(placeholderStr, n);
        }
        if(dirtyFlag_[4])
        {
            n = snprintf(placeholderStr,sizeof(placeholderStr),"$%d,",placeholder++);
            sql.append(placeholderStr, n);
        }
        if(parametersCount > 0)
        {
            sql.resize(sql.length() - 1);
        }
        if(needSelection)
        {
            sql.append(") returning *");
        }
        else
        {
            sql.append(1, ')');
        }
        LOG_TRACE << sql;
        return sql;
    }
};
} // namespace whoitter
} // namespace drogon_model
