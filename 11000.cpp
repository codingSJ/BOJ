#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;


int heapSize = 0;
vector<int> heap;

bool compare(pair<int,int>a,pair<int,int>b){
    if(a.second==b.second)
        return a.first < b.first;
    return a.first < b.first;
}

void insertHeap(int value){
    heap.push_back(value);
    heapSize++;

    int idx = heapSize;
    while(idx>1){
        if(heap[idx]<heap[idx/2])
            swap(heap[idx], heap[idx / 2]);
        else
            break;
        idx /= 2;
    }
}

void renewHeap(){
    int idx = 1;
    while(2*idx<=heapSize){
        if(2*idx+1<=heapSize){
            int minC = heap[2 * idx] <= heap[2 * idx + 1] ? 2 * idx : 2 * idx + 1;
            if(heap[idx]>heap[minC]) {
                swap(heap[idx], heap[minC]);
                idx = minC;
            }
            else
                break;
        }
        else{
            if(heap[idx]>heap[2*idx])
                swap(heap[idx], heap[2 * idx]);
            else
                break;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, i;
    cin >> n;
    vector<pair<int, int>> v(n);
    heap.push_back(0);

    for(i=0;i<n;i++){
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(),v.end(),compare);
    insertHeap(v[0].second);

    for(i=1;i<n;i++){
        if(v[i].first>=heap[1]){
            heap[1] = v[i].second;
            renewHeap();
        }
        else{
            insertHeap(v[i].second);
        }
    }
    cout << heapSize;
}