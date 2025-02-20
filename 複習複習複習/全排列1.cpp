#include <bits/stdc++.h>
using namespace std;


void BackTrack(vector<vector<int>>& result, vector<int> nums, vector<bool> used, vector<int> track){

    // static int cnt = 0;
    // cout << "cnt: " << cnt << "\n";
    // cnt ++;

    cout << "目前的track: [ ";
    for(int i = 0; i < track.size(); i++){
        cout << track[i] << " ";
    }
    cout << "]\n";

    for(int i = 0; i < nums.size(); i ++){
        if(track.size() == nums.size()){
            cout << "完成一組排列.\n";
            result.push_back(track);

            cout << "目前的result存放了" << result.size() << "組數列"  << ".\n";
            for(int i = 0; i < result.size(); i ++){
                cout << "[ ";
                for(int j = 0; j < nums.size(); j ++){
                    cout << result[i][j] << " ";
                }
                cout << "]\n";
            }
            cout << "\n";
            return ;
        }

        if(used[i]){
            continue;
        }

        track.push_back(nums[i]);
        used[i] = 1;
        BackTrack(result, nums, used, track);
        track.pop_back();
        used[i] = 0;
    }

}

int main(void){

    vector<vector<int>> result;
    vector<int> nums = {1, 2, 3};
    vector<bool> used(nums.size(), false);
    vector<int> track;

    cout << "\n";
    BackTrack(result, nums, used, track);

    cout << "\n最後的result:\n";
    for(int i = 0; i < result.size(); i ++){
        cout << "[ ";
        for(int j = 0; j < nums.size(); j ++){
            cout << result[i][j] << " ";
        }
        cout << "]\n";
    }
    cout << "\n";
    return 0;

}