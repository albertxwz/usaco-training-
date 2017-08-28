{
ID:1017981911
PROG:sprime
LANG:PASCAL
#FILE
}

var
  //a:array[1..1000]of longint;
  su:array[1..8]of longint;
  i,j,n,ms:longint;

function prime(n:longint):boolean;		//判断素数
var
  i:longint;
begin
  for i:=2 to trunc(sqrt(n)) do
    if n mod i=0 then exit(false);
  exit(true);
end;

procedure dfs(i:longint);
var
  j:longint;
begin
  if i=n+1 then			//n位都放完了就输出
  begin
    writeln(ms);
	exit;
  end;
  for j:=1 to 9 do		//每一位都有九种可能
    if (i<>1)or(j<>1) then
	begin
	  ms:=ms*10+j;
	  if prime(ms) then dfs(i+1);
	  ms:=ms div 10;
	end;
end;

begin
  assign(input,'sprime.in');
  reset(input);
  assign(output,'sprime.out');
  rewrite(output);
  readln(n);
  dfs(1);  //从第一位开始放数
  close(input);
  close(output);
end.
