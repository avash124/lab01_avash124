#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <random>
#include <ctime>
using namespace std;

vector<int> generateRandomVector(int n){
    vector<int> test(n);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(-1000, 1000);
    for (int i = 0; i < n; i++) {
        test[i] = dist(gen);
    }
    int a = 1;
    int b = 1;
	test.push_back(a);
	test.push_back(b);
	test.push_back(-a-b);
	return test;
}

vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> solution;
        sort(nums.begin(),nums.end());
        for (int i = 0; i<nums.size()-2;i++){
            if(i>0 && nums[i] == nums[i-1]){
                    continue;
                }
            for(int j = i+1; j<nums.size()-1;j++){
                if(j > i+1 && nums[j] == nums[j-1]){
                    continue;
                }
                for(int k = j+1;k<nums.size();k++){
                    if(k > j+1 && nums[k] == nums[k-1]){
                    continue;
                }
                    if(nums[i]+nums[j]+nums[k]==0){
                        solution.push_back({nums[i],nums[j],nums[k]});
                    }

                }
            }
        }
        return solution;
    }
int main(){

vector <int> sizes = {100,200,400,800,1600,3200,6400,8000};
for(int n: sizes){
        vector<int> nums = generateRandomVector(n);
        auto start = chrono::high_resolution_clock::now();
        vector<vector<int>> result = threeSum(nums);
        auto end = chrono::high_resolution_clock::now();
        auto time_ms = chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0;
        cout << " n is " << n  << " and ms/T(n) is " << time_ms << endl;
        }
  return 0;
}

