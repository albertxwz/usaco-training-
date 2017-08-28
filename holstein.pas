{
ID:10179811
PROG:holstein
LANG:PASCAL
#FILE
}

var
  t,f,zans,ans:array[1..25] of longint;
  a:array[1..15,1..25] of longint;
  w,i,j,v,g,zw:longint;

function judge:boolean;					//判断符不符合条件（即每一种维他命的数量）
var
  i:longint;
  flag:boolean;
begin
  flag:=true;
  for i:=1 to v do
    if f[i]<t[i] then exit(false);
  judge:=flag;
end;

procedure dfs(i:longint);					//搜索每一种可能
var
  j,k:longint;
begin
  if judge and (zw>w) then
  begin
    zans:=ans;
	zw:=w;
	exit;
  end;
  for j:=i to g do
  begin
    for k:=1 to v do
	  f[k]:=f[k]+a[j,k];
	inc(w);
	ans[w]:=j;
	dfs(j+1);
	for k:=1 to v do
	  f[k]:=f[k]-a[j,k];
	dec(w);
  end;
end;

begin
  assign(input,'holstein.in');
  reset(input);
  assign(output,'holstein.out');
  rewrite(output);
  
  readln(v);
  for i:=1 to v do read(t[i]);
  readln(g);
  for i:=1 to g do
    for j:=1 to v do
	  read(a[i,j]);
  w:=0;
  zw:=maxlongint;
  fillchar(f,sizeof(f),0);
  dfs(1);						//搜索
  write(zw,' ');
  for i:=1 to zw-1 do
    write(zans[i],' ');
  writeln(zans[zw]);
  close(input);
  close(output);
end.