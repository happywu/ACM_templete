#include<cstdio>
#include<iostream>
using namespace std;
const int maxn = 100;
double Matrix[maxn][maxn];

//Ҫ��ϵ���������
//AΪ�������A[i][n]Ϊ��i�������ұߵĳ���bi
void gauss_elimination(Matrix A,int n){
	for(int i=0;i<n;i++){
		//ѡһ��r���i�н�����ȡ����ֵ����һ��
		int r=i;
		for(int j=i+1;j<n;j++)
			if(fabs[A[j][i]]>fabs[A[r][i]]) r=j;
		if(r!=i)for(int j=0;j<=n;j++) swap(A[r][j],A[i][j]);

		//��Ԫ
		for(int k=i+1;k<n;k++){
			double f=A[k][i]/A[i][i];
			for(int j=i;j<=n;j++)A[k][j]-=f*A[i][j];
		}
	}

	//�ش�
	for(int i=n-1;i>=0;i--){
		for(int j=i+1;j<n;j++)
			A[i][n]-=A[j][n]*A[i][j];
		A[i][n]/=A[i][i];
	}
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
