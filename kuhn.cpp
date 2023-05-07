// !!! btoa must be a vector the size of the right part
// usage: btoa.assign(m, -1); int matchingSize = bipartiteMatching(g, btoa);
int bipartiteMatching(const vector<vector<int>>& g, vector<int>& btoa) {
	vector<int> vis;
	auto find = [&](int j, const auto& find) -> bool {
		if (btoa[j] == -1) return 1;
		vis[j] = 1; int di = btoa[j];
		for (int e : g[di])
			if (!vis[e] && find(e, find)) {
				btoa[e] = di;
				return 1;
			}
		return 0;
	};

	for(int i = 0; i < g.size(); ++i) {
		vis.assign(btoa.size(), 0);
		for (int j : g[i])
			if (find(j, find)) {
				btoa[j] = i;
				break;
			}
	}
	return btoa.size() - (int)count(btoa.begin(), btoa.end(), -1);
}
