#include <stdio.h>

struct FIELD{
    int x, y;
};

struct FIELD_QUEUE{
    struct FIELD fields[100000];
    int begin, end;
};

void bfs(int[][105], int[][105], struct FIELD_QUEUE*);
int r, c;

int main()
{
    scanf("%d %d", &r, &c);
    struct FIELD_QUEUE que;
    que.begin = 0;
    que.end = 0;
    int g[105][105], dis[105][105], i, j;
    for(i = 0; i < r; i++)
        for(j = 0; j < c; j++)
            scanf("%d", &g[i][j]);
    for(i = 0; i < r; i++)
        for(j = 0; j < c; j++){
            if(i > 0 && g[i-1][j] > g[i][j])
                continue;
            if(j > 0 && g[i][j-1] > g[i][j])
                continue;
            if(i < r-1 && g[i+1][j] > g[i][j])
                continue;
            if(j < c-1 && g[i][j+1] > g[i][j])
                continue;
            que.fields[que.end].x = i;
            que.fields[que.end].y = j;
            que.end++;
            dis[i][j] = 1;
        }
    while(que.begin != que.end){
        bfs(g, dis, &que);
    }
    int max_dis = 0;
    for(i = 0; i < r; i++)
        for(j = 0; j < c; j++)
            if(dis[i][j] > max_dis)
                max_dis = dis[i][j];
    printf("%d\n", max_dis);
    return 0;
}

void bfs(int g[][105], int dis[][105], struct FIELD_QUEUE* queue)
{
    int x = queue->fields[queue->begin].x, y = queue->fields[queue->begin].y;
    queue->begin++;

    if(x > 0 && g[x-1][y] < g[x][y] && dis[x-1][y] <= dis[x][y]){
        dis[x-1][y] = dis[x][y] + 1;
        queue->fields[queue->end].x = x-1;
        queue->fields[queue->end].y = y;
        queue->end++;
    }
    if(y > 0 && g[x][y-1] < g[x][y] && dis[x][y-1] <= dis[x][y]){
        dis[x][y-1] = dis[x][y] + 1;
        queue->fields[queue->end].x = x;
        queue->fields[queue->end].y = y-1;
        queue->end++;
    }
    if(x < r-1 && g[x+1][y] < g[x][y] && dis[x+1][y] <= dis[x][y]){
        dis[x+1][y] = dis[x][y] + 1;
        queue->fields[queue->end].x = x+1;
        queue->fields[queue->end].y = y;
        queue->end++;
    }
    if(y < c-1 && g[x][y+1] < g[x][y] && dis[x][y+1] <= dis[x][y]){
        dis[x][y+1] = dis[x][y] + 1;
        queue->fields[queue->end].x = x;
        queue->fields[queue->end].y = y+1;
        queue->end++;
    }
}

