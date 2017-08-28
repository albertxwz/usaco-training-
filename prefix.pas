{
ID:10179811
PROG:prefix
LANG:PASCAL
#FILE
}

var
	s:array[1..200] of string;
	//st:array[1..20000] of char;
	st,tmp:ansistring;
	f:array[0..200001] of boolean;
	len:array[1..203] of longint;
	x:char;
	n,i,j,tot:longint;

begin
	assign(input,'prefix.in');
	reset(input);
	assign(output,'prefix.out');
	rewrite(output);
	n:=1;
	x:=' ';
	fillchar(len,sizeof(len),0);
	while x<>'.' do
	begin
		read(x);
		if x in ['A'..'Z'] then 
			s[n]:=s[n]+x
		else inc(n);
		if ord(x)=13 then dec(n);
	end;
	n:=n-2;
	//readln;
	{ while not(eof) do
	begin
		read(x);
		inc(len);
		st[len]:=x;
	end;  }
	readln(st);
	while not(eof) do
	begin
		readln(tmp);
		st:=st+tmp;
	end;
	
	fillchar(f,sizeof(f),false);
	f[0]:=true;
	tot:=length(st);
	for i:=1 to n do
		len[i]:=length(s[i]);
	for i:=1 to tot do
		for j:=1 to n do
			if (len[j]<=i) and (copy(st,i-len[j]+1,len[j])=s[j]) and f[i-len[j]] then
			begin
				f[i]:=true;
				break;
			end;
	for i:=tot downto 0 do
		if f[i] then
		begin
			writeln(i);
			break;
		end;

	close(input);
	close(output);
end.