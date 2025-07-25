const api = new WhoItterAPI();

async function init() {
    try {
        const user = await api.getCurrentUser();
        renderUserInfo(user);
        renderPostForm();
        loadFeed();
    } catch (error) {
        window.location.href = '/login';
    }
}

function renderUserInfo(user) {
    const userInfo = document.getElementById('user-info');
    userInfo.innerHTML = `
        <div class="user-info">
            <span>@${user.username}</span>
            <button class="logout-btn" onclick="api.logout()">Logout</button>
        </div>
    `;
}

function renderPostForm() {
    const container = document.getElementById('post-form-container');
    container.innerHTML = `
        <div class="post-form">
            <textarea id="post-content" placeholder="What's happening?"></textarea>
            <button onclick="createPost()">Post</button>
        </div>
    `;
}

async function createPost() {
    const content = document.getElementById('post-content').value.trim();
    if (content) {
        await api.createPost(content);
        document.getElementById('post-content').value = '';
        loadFeed();
    }
}

async function loadFeed() {
    const posts = await api.getFeed();
    const feed = document.getElementById('feed');
    feed.innerHTML = posts.map(post => `
        <div class="post">
            <div class="post-header">
                <div class="post-author">@${post.user.username}</div>
                <div>${new Date(post.created_at).toLocaleString()}</div>
            </div>
            <div class="post-content">${post.content}</div>
        </div>
    `).join('');
}

init();
