//
// Created by Kylian Lee on 2021/07/23.
//

#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> tournament);

int main(){
  int team_num;
  vector<int> tournament;
  cin >> team_num;
  for (int i = 0; i < team_num; ++i) {
    int temp;
    cin >> temp;
    tournament.push_back(temp);
  }
  cout << solution(tournament) << endl;
  return 0;
}

int solution(vector<int> tournament){
  int size = tournament.size();
  if(size == 1)
    return 0;
  int max = 0, max_idx;
  for (int i = 0; i < size; ++i) {
    if(tournament[i] > max) {
      max = tournament[i];
      max_idx = i;
    }
  }
  int ret;
  if(max_idx > 0 && max_idx < size - 1){
    tournament[max_idx - 1] > tournament[max_idx + 1] ? ret = max - tournament[max_idx - 1] : ret = max - tournament[max_idx + 1];
  }
  else if(max_idx == 0)
    ret = max - tournament[max_idx + 1];
  else
    ret = max - tournament[max_idx - 1];
  auto iter = tournament.begin();
  tournament.erase(iter + max_idx);
  return ret + solution(tournament);
}