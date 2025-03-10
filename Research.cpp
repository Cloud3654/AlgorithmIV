// dfs
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    vector <pair<int,int>> cld; // cld(pair-first는 자신의 번호, pair-second는 가는 데 드는 가중치) 생성
    bool visit; // visit(방문 체크) 생성
};

Node nd[10]; // nd(트리) 생성
int n, S=1, D=7, minPath = 1e9; // n(노드 수), S(시작 번호), D(목적지 번호), minPath(최소 가중치) 생성, S, D 정의


void dfs(int idx, int sumWei) // dfs(가중치 탐색 함수) 정의
{
    if(idx == D) { // 현재 인덱스가 목적지라면
        minPath = min(minPath,sumWei); // minPath를 가중치의 합과 최소 가중치의 최솟값으로 변경
        return; // 함수 종료
    }

    for(auto p : nd[idx].cld) { // idx의 모든 자식 노드에 대해 반복
        if(nd[p.first].visit == false) {  // 방문한 적이 없다면
            nd[p.first].visit = true; // 방문 체크
            dfs(p.first, sumWei+p.second); // 가중치에 방금 이동한 가중치를 더한 수를 2번째 인수로 dfs 호출
            nd[p.first].visit = false; // 방문 체크 해제
        }
    }
}

int main()
{
    int m; // m(간선 수) 생성
    cin >> n >> m; // n, m 입력
    for (int sp, ep, w; m--; ) { // sp(시작 지점), ep(다음 지점), w(가중치) 생성, m번 반복
        cin >> sp >> ep >> w; // sp, ep, w 입력
        nd[sp].cld.push_back({ep,w}); // sp의 자식 목록에 {ep, w} 추가
    }

    nd[1].visit = true; // 1번 노드 방문 체크
    dfs(S,0); // 시작 지점에서 누적 가중치 0으로 dfs 호출
    cout << minPath; // minPath 출력
}


