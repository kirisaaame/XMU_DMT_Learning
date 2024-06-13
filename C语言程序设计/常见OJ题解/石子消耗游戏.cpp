void MingPick(int left, int k, int turn)
{
	
	left-=k*turn;
	if (left<=0) printf("MING!\n%d\n",turn);
	else {
		turn++;
		QiangPick(left,k,turn);
	}
	
}
void QiangPick(int left, int k, int turn)
{
	left-=k*turn;
	if (left<=0) printf("QIANG!\n%d\n",turn);
	else {
	turn++;
		MingPick(left,k,turn);
	}
}