{
ID:1017981911
PROG:numtri
LANG:PASCAL
#FILE
}

var
  f,a:array[1..1000,1..1000] of longint;
  i,j,temp,n:longint;
begin
  assign(input,'numtri.in');
  reset(input);
  assign(output,'numtri.out');
  rewrite(output);
  readln(n);
  for i:=1 to n do
    for j:=1 to i do
	  read(a[i,j]);				
  f[1,1]:=a[1,1];			//金字塔的顶端
  for i:=2 to n do 			//预处理
  begin
    f[i,1]:=f[i-1,1]+a[i,1];			//因为f[i,1]只有从上到下走
	f[i,i]:=f[i-1,i-1]+a[i,i];			//f[i,i]只有从左上到右下这样走
  end;
  for i:=3 to n do				
    for j:=2 to i-1 do
	begin
	  //选择最优路径
	  temp:=f[i-1,j-1];
	  if f[i-1,j]>temp then temp:=f[i-1,j];
	  f[i,j]:=temp+a[i,j];
	end;
  //打擂台，找到最大值
  temp:=a[n,1];
  for i:=2 to n do
    if temp<f[n,i] then temp:=f[n,i];
  writeln(temp);
  close(input);
  close(output);
end.