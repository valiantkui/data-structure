#include<stdio.h>
#include<cstdlib>
#include<iostream>
#include"bitree.h"

void SecondOptimal(BiTree &T,ElemType R[],float sw[],int low,int high)
//�������R[low...high]�����ۼ�Ȩֵ��sw������sw[0]==0���ݹ鹹������Ȳ�����T�� 
{
	int i;
	i=low;
	min=abs(sw[high]-sw[low]);
	dw=sw[high]+sw[low-1];
	for(j=low+1;j<=high;++j)
	{
		if(abs(dw-sw[j]-sw[j-1])<min)
		{
			i=j;
			min=abs(dw-sw[j]-sw[j-1]);
		}
	 } 
	 T=(BiTree)malloc(sizeof(BiTNode));
	 T->data=R[i];		//���ɽڵ� 
	 if(i==low)
	 	T->lchild=NULL;		//�������� 
	else 
		SecondOptimal(T->rchild,R,sw,i+1,high);//������������
	if(i==high)
		T->rchild=NULL;				//�������� 
	else
		SecondOptimal(T->rchild,R,sw,i+1,high);//������������ 
 } //SecondOptimal
 Status SearchBST(BiTree T,KeyType key,BiTree f,BiTree &p0)
 //�ڸ�ָ��T��ָ�����������еݹ�ز�����ؼ��ֵ���key������Ԫ�أ������ҳɹ���
 //��ָ��pָ�������Ԫ�ؽ�㣬������TRUE������ָ��pָ��pָ�����·���Ϸ��ʵ����һ����㲢����FALSE,ָ��fָ��T��
 //˫�ף����ʼ����ֵΪNULL 
{
 	if(!T) 			//���Ҳ��ɹ� 
	 {
	 	p=f;
	 	return FALSE;
	  } 
	else if EQ(key,T->data.key)		//���ҳɹ� 
	{
		p=T;return TRUE�� 
	 } 
	else if ELT(key,T->data.key) return SearchBST(T->lchild,key,T,p);//���������м�������
	else return SearchBST(T->rchild,key,T,p); 						//���������м������� 
} //SearchBST
  
Status InsertBST(BiTree &T,ElemType e)
  //������������T�в����ڹؼ��ֵ���e.key������Ԫ��ʱ������e������TRue��
  //���򷵻�FALSE 
{
	BiTNode *s;
  	if(!SearchBST(T,e.key,NULL,p)) 	//���Ҳ��ɹ� 
	  {
	  	s=(BiTree)malloc(sizeof(BiTNode));
		s->data=e;
		s->lchild=s->rchild=NULL;
		if(!p) T=s;
		else if LT(e.key,p->data.key) p->lchild=s; //������*sΪ����
		else p->rhild=s; 		//������*sΪ�Һ���
		return TRUE; 
	   } 
	else return FALSE; //�������йؼ�����ͬ�Ľ�㣬���ٲ���   
} //Insert BST 
 
 
 
 
 
 
 
 
 
 
 
 
 

