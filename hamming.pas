{
ID:1017981911
PROG:hamming
LANG:PASCAL
#FILE
}

var
  a:array[1..64]of longint;
  ss:array[1..64]of string;
  i,j,n,b,d,maxn,temp:longint;

function judge(m,k:longint):boolean;			//这里我不多说了，就是比较而已，十进制转二进制
var
  ham,i,j:longint;
  flag:boolean;
begin
  ss[k]:='';
  while m<>0 do
  begin
    ss[k]:=char((m mod 2)+ord('0'))+ss[k];
	m:=m div 2;
  end;
  while length(ss[k])<b do ss[k]:='0'+ss[k];
  for i:=1 to k-1 do
  begin
    flag:=false;
	ham:=0;
    for j:=1 to b do
	begin
	  if ss[i,j]<>ss[k,j] then inc(ham);
	  if ham>=d then begin flag:=true; break; end;
	end;
	if not flag then exit(false);
  end;
  exit(true);
end;

procedure print;
var
  i,j,k:longint;
begin
  k:=0;
  for i:=1 to n div 10 do
  begin
    for j:=i*10-9 to i*10-1 do
	  write(a[j],' ');
	writeln(a[i*10]);
  end;
  if n mod 10 <> 0 then
  begin
    for i:=1 to (n mod 10)-1 do
	  write(a[10*(n div 10)+i],' ');
	writeln(a[10*(n div 10)+n mod 10]);
  end;
end;

procedure dfs(i:longint);
var
  j:longint;
begin
  if i=n+1 then
  begin
    print;
	halt;
	close(input);
	close(output);
  end;
  for j:=0 to maxn do				
    if judge(j,i) then					//符合条件否？
	begin
	  a[i]:=j;
	  dfs(i+1);
	end;
end;

begin
  assign(input,'hamming.in');
  reset(input);
  assign(output,'hamming.out');
  rewrite(output);
  readln(n,b,d);
  maxn:=0;
  for i:=b-1 downto 0 do				//算最高位最大的数
  begin
    temp:=1;
    for j:=1 to i do
	  temp:=temp*2;
	maxn:=maxn+temp;
  end;
  dfs(1);
  close(input);
  close(output);
end.
