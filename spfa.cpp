int spfa()
{
	int inq[110];
	memset(inq, 0, sizeof(inq));//当前点是否在队列里面。
	memset(dis, 0, sizeof(dis));
	dis[st] = start;
	queue<int>q;
	q.push(st);
	inq[st] = 1;
	while (!q.empty())
	{
		int t = q.front();
		q.pop();
		inq[t] = 0;
		for (int i = 1; i <= n; i++)
		{
			if (dis[i] < (dis[t] - c[t][i])*a[t][i])
			{
				dis[i] = (dis[t] - c[t][i])*a[t][i];
				if (dis[st] > start)//说明有持续增长的边。
					return 1;
				if (!inq[i])
				{
					q.push(i);
					inq[i] = 1;
				}
			}
		}
	}
	return 0;
}
