#include<stdio.h>
#include<cstdlib>
#include<iostream>
#include"bitree.h"

void SecondOptimal(BiTree &T,ElemType R[],float sw[],int low,int high)
//有有序表R[low...high]及其累计权值表sw（其中sw[0]==0）递归构造次优先查找树T。 
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
	 T->data=R[i];		//生成节点 
	 if(i==low)
	 	T->lchild=NULL;		//左子树空 
	else 
		SecondOptimal(T->rchild,R,sw,i+1,high);//构造左子树；
	if(i==high)
		T->rchild=NULL;				//右子树空 
	else
		SecondOptimal(T->rchild,R,sw,i+1,high);//构造右子树； 
 } //SecondOptimal
 Status SearchBST(BiTree T,KeyType key,BiTree f,BiTree &p0)
 //在根指针T所指二叉排序树中递归地查找其关键字等于key的数据元素，若查找成功，
 //则指针p指向该数据元素结点，并返回TRUE，否则指针p指向p指向查找路径上访问的最后一个结点并返回FALSE,指针f指向T的
 //双亲，其初始调用值为NULL 
{
 	if(!T) 			//查找不成功 
	 {
	 	p=f;
	 	return FALSE;
	  } 
	else if EQ(key,T->data.key)		//查找成功 
	{
		p=T;return TRUE； 
	 } 
	else if ELT(key,T->data.key) return SearchBST(T->lchild,key,T,p);//在左子树中继续查找
	else return SearchBST(T->rchild,key,T,p); 						//在右子树中继续查找 
} //SearchBST
  
Status InsertBST(BiTree &T,ElemType e)
  //当二叉排序树T中不存在关键字等于e.key的数据元素时，插入e并返回TRue，
  //否则返回FALSE 
{
	BiTNode *s;
  	if(!SearchBST(T,e.key,NULL,p)) 	//查找不成功 
	  {
	  	s=(BiTree)malloc(sizeof(BiTNode));
		s->data=e;
		s->lchild=s->rchild=NULL;
		if(!p) T=s;
		else if LT(e.key,p->data.key) p->lchild=s; //被插结点*s为左孩子
		else p->rhild=s; 		//被插结点*s为右孩子
		return TRUE; 
	   } 
	else return FALSE; //树中已有关键字相同的结点，不再插入   
} //Insert BST 
 
 
 
 
 
 
 
 
 
 
 
 
 

