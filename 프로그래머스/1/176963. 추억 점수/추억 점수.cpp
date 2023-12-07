#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
	vector<int> answer;

	unordered_map<string, int> Map;
	for (int i = 0; i < name.size(); ++i)
	{
		Map.emplace(name[i], yearning[i]);
	}

	for (int i = 0; i < photo.size(); ++i)
	{
		int iSum = 0;
		for (int j = 0; j < photo[i].size(); ++j)
		{
			auto iter = Map.find(photo[i][j]);
			if (iter == Map.end())
				continue;

			iSum += iter->second;

		}

		answer.push_back(iSum);

	}

	return answer;
}