// dfs
#include <iostream>
#include <vector>

using namespace std;

struct Node { // Node 변수형 생성
    vector<pair<int,int>> cld; // cld(pair-first는 자신의 번호, pair-second는 가는 데 드는 가중치) 생성
    bool visit; // visit(방문 체크) 생성
};

Node nd[10]; // nd(트리) 생성
int n, S = 1, D = 7, minPath = 1e9; // n(노드 수), S(시작지 번호), D(목적지 번호), minPath(최소 가중치) 생성 및 S, D, minPath 정의


void dfs (int idx, int sumWei) { // dfs(가중치 탐색 함수) 정의
    if (idx == D) { // 현재 인덱스가 목적지라면
        minPath = min(minPath, sumWei); // minPath를 가중치의 합과 최소 가중치의 최솟값으로 변경
        return; // 함수 종료
    }

    for (auto p : nd[idx].cld) { // idx의 모든 자식 노드에 대해 반복
        if (nd[p.first].visit == false) {  // 방문한 적이 없다면
            nd[p.first].visit = true; // 방문 체크
            dfs(p.first, sumWei + p.second); // 가중치에 방금 이동한 가중치를 더한 수를 2번째 인수로 dfs 호출
            nd[p.first].visit = false; // 방문 체크 해제
        }
    }
}

int main() {
    int m; // m(간선 수) 생성
    cin >> n >> m; // n, m 입력
    for (int sp, ep, w; m--; ) { // sp(시작 지점), ep(다음 지점), w(가중치) 생성, m번 반복
        cin >> sp >> ep >> w; // sp, ep, w 입력
        nd[sp].cld.push_back({ep, w}); // sp의 자식 목록에 {ep, w} 추가
    }

    nd[1].visit = true; // 1번 노드 방문 체크
    dfs(S, 0); // 시작 지점에서 누적 가중치 0으로 dfs 호출
    cout << minPath; // minPath 출력
}

// bfs
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> cld[10]; // cld(pair-first는 , pair-second는 ) 생성
int weiSum[10]; // weiSum(인덱스까지 가는 데 드는 가중치) 생성
int n, S = 1, D = 7, minPath = 1e9; // n(노드 수), S(시작지 번호), D(목적지 번호), minPath(최소 가중치) 생성 및 S, D, minPath 정의

void bfs() { // bfs(가중치 탐색 함수) 정의
    queue<int> q; // q 생성

    weiSum[S] = 0; // 시작지까지 가는데 드는 가중치를 0으로 설정
    q.push(S); // q에 시작지 추가

    while (q.size()) { // q의 크기가 0이 될 때까지 반복
        int idx = q.front(); // idx 생성, q의 첫 번쨰 값으로 정의
        q.pop(); // q의 첫 번째 값 삭제
        for (auto p : cld[idx]) { // cld의 모든 idx값에 대해 반복 
            int idx2 = p.first; // idx2 생성 및 idx의 첫 번째 값으로 정의
            int wei = p.second; // 

            if (weiSum[idx2] > weiSum[idx] + wei) {
                weiSum[idx2] = weiSum[idx] + wei;
                q.push(idx2);
            }
        }
    }
}

int main() {
    int m;
    cin >> n >> m;
    fill_n(weiSum, n + 1, 1e9);

    for (int sp, ep, w; m--; ) {
        cin >> sp >> ep >> w;
        cld[sp].push_back({ep, w});
    }

    bfs();
    cout << weiSum[D];
}
