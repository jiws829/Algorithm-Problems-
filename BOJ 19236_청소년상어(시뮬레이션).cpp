#include<stdio.h>

int p[4][4];
int dir[4][4];
struct fish{
    int x,y;
}f[17];
int answer=-999;

void dfs(int x, int y, int size){
    //printf("%d %d %d -> %d\n",x,y,size,p[x][y]);
    if(answer < size+p[x][y]) answer=size+p[x][y];

    int dx[9]={0,-1,-1,0,1,1,1,0,-1}, dy[9]={0,0,-1,-1,-1,0,1,1,1};
    int flag;
    int i,j,k;
    int a,b;

    f[p[x][y]].x=f[p[x][y]].y=-1;
    size+=p[x][y];
    p[x][y]=0;

    /*printf("전\n");
    for(i=0;i<4;i++){
        for(j=0;j<4;j++) printf("%d(%d) ",p[i][j],dir[i][j]);
        printf("\n");
    }
    printf("\n");*/

    for(i=1;i<=16;i++){
        if(f[i].x == -1) continue;

        a=f[i].x; b=f[i].y;


        for(j=dir[a][b];;){
            if(a+dx[j]<0 || a+dx[j]>=4 || b+dy[j]<0 || b+dy[j]>=4 || (a+dx[j]==x && b+dy[j]==y)) {
                j++;
                if(j==dir[a][b]) break;
                if(j>8) j=1;
                continue;
            }

            p[a][b]=p[a+dx[j]][b+dy[j]];
            dir[a][b]=dir[a+dx[j]][b+dy[j]];

            p[a+dx[j]][b+dy[j]]=i;
            dir[a+dx[j]][b+dy[j]]=j;

            f[p[a][b]].x=a; f[p[a][b]].y=b;
            f[p[a+dx[j]][b+dy[j]]].x=a+dx[j]; f[p[a+dx[j]][b+dy[j]]].y=b+dy[j];
            break;
        }

        /*printf("%d\n",i);
        for(k=0;k<4;k++){
            for(j=0;j<4;j++) printf("%d(%d) ",p[k][j],dir[k][j]);
            printf("\n");
        }
        printf("\n");*/

    }

    /*printf("후\n");
    for(i=0;i<4;i++){
        for(j=0;j<4;j++) printf("%d(%d) ",p[i][j],dir[i][j]);
        printf("\n");
    }
    printf("--------------\n\n");*/

    int q[4][4];
    int q_dir[4][4];
    fish q_f[17];
    for(i=0;i<4;i++){
        for(j=0;j<4;j++) {
            q[i][j]=p[i][j];
            q_dir[i][j]=dir[i][j];
        }
    }
    for(i=1;i<=16;i++) q_f[i]=f[i];

    int xx,yy;
    for(k=1;k<=3;k++){
        xx= x + k*dx[dir[x][y]];
        yy= y + k*dy[dir[x][y]];

        if(xx<0 || xx>=4 || yy<0 || yy>=4 || p[xx][yy]==0) continue;

        dir[x][y]=-1;
        dfs(xx,yy,size);

        for(i=0;i<4;i++){
            for(j=0;j<4;j++) {
                p[i][j]=q[i][j];
                dir[i][j]=q_dir[i][j];
            }
        }
        for(i=1;i<=16;i++) f[i]=q_f[i];

    }
}

int main(){
    //freopen("./c++/input.txt","r",stdin);

    int i,j;

    for(i=0;i<4;i++){
        for(j=0;j<4;j++) {
            scanf("%d %d",&p[i][j],&dir[i][j]);
            f[p[i][j]].x=i; f[p[i][j]].y=j;
        }
    }

    dfs(0,0,0);

    printf("%d\n",answer);
}