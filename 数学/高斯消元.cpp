#include<cstdio>
#include<iostream>
using namespace std;
const int maxn = 100;
typedef double Matrix[maxn][maxn];

int gauss_elimination(Matrix &A){
	for(int i=0;i<n;i++){
		int r=i;
		//ѡһ��r���i�н�����ȡ����ֵ����һ��
		for(int j=i+1;j<m;j++)
			if(fabs(A[j][i])>fabs(A[r][i]))r=j;
		if(r!=i)for(int j=0;j<=n;j++)swap(A[r][j],A[i][j]);
		if(A[i][i]==0)return 2;//���
		//��Ԫ
		for(int k=i+1;k<m;k++){
			double f=A[k][i]/A[i][i];
			for(int j=i;j<=n;j++)A[k][j]-=f*A[i][j];
		}
	}
	for(int i=0;i<m;i++){
		bool flag=0;
		for(int j=0;j<n;j++){
			if(A[i][j]!=0){flag=1;break;}
		}
		if(!flag&&A[i][n]!=0)return 0;//�޽�
	}
	//�ش�
	for(int i=n-1;i>=0;i--){
		for(int j=i+1;j<n;j++)
			A[i][n]-=A[j][n]*A[i][j];
		A[i][n]/=A[i][i];
	}
	return 1;//��Ψһ��
}

int Gauss(int equ,int var){
	int row,col,free_num=0;
	for(row=col=0;row<equ&&col<var;row++,col++){
		int max_r=row;
		for(int i=row+1;i<equ;i++)
			if(fabs(A[i][col])>fabs(A[max_r][col]))max_r=i;

		if(A[max_r][col]==0){//���ɱ�Ԫ
			row--;
			free_x[free_num++]=col;
			continue;
		}
		if(max_r!=row)
			for(int j=col;j<=var;j++)swap(A[row][j],A[max_r][j]);
		for(int i=row+1;i<equ;i++){
			double f=A[i][col]/A[rol][col];
			for(int j=0;j<=var;j++)
				A[i][j]-=f*A[rol][j];
		}
	}

	for(int i=row;i<equ;i++)
		if(A[i][col]!=0)return -1;//ʣ���з��� �޽�

	if(row<var)return var-row;//��� �������ɱ�Ԫ����

	for(int i=var-1;i>=0;i--){
		for(int j=i+1;j<var;j++)
			A[i][n]-=A[j][n]*A[i][j];
		A[i][n]/=A[i][i];
	}
}

int XorGuass(int equ, int var) {
    int row = 0, col = 0;
    int free_var = 0; //���ɱ�Ԫ����
    while(row < equ && col < var) {
        int i;
        for(i = row; i < equ; i++) if(A[i][col] != 0) break;
        if(i == equ) { //��ǰ��Ԫ��Ϊ0�����ɱ�Ԫ+1��
            free_var++;
            col++;
            continue;
        }
        for(int j = col; j <= var; j++) swap(A[i][j], A[row][j]); //����Ԫ��Ϊ0���н������ϱ�
        for(int j = row + 1; j < equ; j++) { //�����Ԫ
            if(A[j][col]) {
                for(int k = col; k <= var; k++) A[j][k] ^= A[row][k];
            }
        }
        row++; col++;
    }
    for(int i = row; i < equ; i++) if(A[i][var]) return -1;  //�޽�
    for(int i = var - 1; i >= 0; i--) {
        ans[i] = A[i][var];
        for(int j = i + 1; j < var; j++) {
            ans[i] ^= (A[i][j] & ans[j]);
        }
    }
    return free_var;
}

