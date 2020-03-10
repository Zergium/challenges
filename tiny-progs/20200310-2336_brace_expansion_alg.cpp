
/////////////////////////////////// v1

class Solution {
public:
    vector<string> magicMerge(vector<vector<string>>& coms, int i) {
        if (i == coms.size() - 1)
            return coms.back();
        vector<string> res;
        auto prev = magicMerge(coms, i+1);
        for (auto & element: coms[i]) {
            for (auto & prevElement: prev)
                res.push_back(element+prevElement);
        }
        return res;
    }
    vector<string> OnMergeGroups(vector<vector<vector<string>>>& groups) {
        vector<string> res;
        for (auto & g: groups) {
            auto tomerge = magicMerge(g, 0);
            for (auto & element: tomerge)
                res.push_back(element);
        }
        return res;
    }
    vector<string> braceExpansionII(string ex) {
        //expression     = {component, component, ...} OR'ed together
        //component      = {component_part, component_part ...} CROSS'ed together
        //component_part = letters | expression
        //so we need vector<vector<vector<string>>>.
        vector<vector<vector<string>>> groups;
        // first componenet.
        groups.push_back({});
        for (int i = 0, level = 0, sta = 0; i < ex.size(); ++i) {
            if (ex[i] == '{') {
                if (level == 0)
                    sta = i + 1;
                level++;
            } else if (ex[i] == '}') {
                level--;
                if (level == 0) {
                    //new component part.
                    groups.back().push_back(braceExpansionII(ex.substr(sta, i - sta)));
                }
            } else if (ex[i] == ',' && level == 0) {
                // new component.
                groups.push_back({});
            } else if (level == 0) {
                // new component part.
                groups.back().push_back({string(1, ex[i])});
            }
        }
        // cout << ex << " " << groups.size() << endl;
        auto not_ordered = OnMergeGroups(groups);
        set<string> res(not_ordered.begin(), not_ordered.end());
        return vector<string>(res.begin(), res.end());
    }
};








/////////////////////////////  v2


class Solution {
public:
    string getWord(const string& expr, int& i) {
        string res;
        while ('a' <= expr[i] && expr[i] <= 'z')
            res.push_back(expr[i++]);
        return res;
    }

    unordered_set<string> dfs(const string& expr, int& i) {
        unordered_set<string> res;

        unordered_set<string> S;
        while (i < int(expr.length()) && expr[i] != '}') {
            if (expr[i] == ',') {
			    // union
                for (auto& it : S)
                    res.insert(it);
                S.clear();
                i++;
            }
            unordered_set<string> t;
            if (expr[i] == '{') {
                i++;
                t = dfs(expr, i);
                i++;
            } else {
                t.insert(getWord(expr, i));
            }

            if (S.empty())
                S = t;
            else {
			    // cartesian product
                unordered_set<string> S2;
                for (auto& it1 : S) {
                    for (auto& it2 : t)
                        S2.insert(it1 + it2);
                }
                swap(S, S2);
            }
        }
        // union
        for (auto& it : S)
            res.insert(it);

        return res;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;
        unordered_set<string> S = dfs(expression, i);

        vector<string> res;
        for (auto& it : S)
            res.push_back(it);
        sort(res.begin(), res.end());

        return res;
    }
};