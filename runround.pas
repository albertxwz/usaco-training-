{
ID:10179811
PROG:runround
LANG:PASCAL
#FILE
}

type
	arr=array[1..10] of longint;
	
var
	flag:array[1..9] of boolean;
	m,temp,min:qword;

function test(a:arr;k:longint):boolean;		//判断循环数的条件之一就是全都走一遍
var
	i:longint;
begin
	for i:=1 to k do
		if a[i]<>1 then exit(false);
	exit(true);
end;
	
function judge(n:qword):boolean;	//判断是不是循环数
var
	a:arr;
	i,k:longint;
	s:string;
begin
	fillchar(a,sizeof(a),0);
	i:=1;
	str(n,s);
	k:=length(s);
	repeat
		i:=ord(s[i])-ord('0')+i;
		i:=((i-1) mod k)+1;
		inc(a[i]);
		if a[i]>1 then exit(false);
	until test(a,k);
	exit(true);
end;

procedure dfs;			//直接深搜
var
	j:longint;
begin
	if temp>m then
	begin
		if  judge(temp) and (min>temp) then min:=temp;
		exit;
	end;
	for j:=1 to 9 do
		if flag[j] then
		begin
			flag[j]:=false;
			temp:=temp*10+j;
			dfs;
			flag[j]:=true;
			temp:=temp div 10;
		end;
end;

begin
	assign(input,'runround.in');
	reset(input);
	assign(output,'runround.out');
	rewrite(output);
	readln(m);
	
	min:=maxlongint;
	fillchar(flag,sizeof(flag),true);
	dfs;
	writeln(min);
	
	close(input);
	close(output);
end.
