void dfs(int v) {
    node* w;
    visited[v] = true;
    cout << v;
    for (w = graph[v]; w; w = w->link) {
        if (!visited[w->vertex]) {
            dfs(w->vertex);
        }
    }
}