1.
/*求整数中的所有位中1的个数*/
2.
/*在O(1)时间删除单链表的某个节点*/




1.
int numberof(int n)
{
  int count = 0;
  while(n)
  {
    ++count;
    n = (n - 1) & n;
  }
  return count;
}

2.
//(1)先把要删除的节点的后面的节点拷到要删除的节点，然后删除下面那个节点。
//(2)如果
