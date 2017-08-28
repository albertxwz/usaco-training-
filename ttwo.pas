{
ID:10179811
PROG:ttwo
LANG:PASCAL
#FILE
}

const
	dx:array[1..4] of integer=(-1,0,1,0);
	dy:array[1..4] of integer=(0,1,0,-1);

var
	map:array[1..10,1..10] of char;
	c,f:array[1..2] of integer;
	time,fd,cd,fstep,cstep,i,j:longint;

begin
	assign(input,'ttwo.in'); reset(input);
	assign(output,'ttwo.out'); rewrite(output);
	
	for i:=1 to 10 do
	begin
		for j:=1 to 10 do
		begin
			read(map[i,j]);
			if map[i,j]='F' then begin f[1]:=i; f[2]:=j; map[i,j]:='.' end;
			if map[i,j]='C' then begin c[1]:=i; c[2]:=j; map[i,j]:='.' end;
		end;
		readln;
	end;
	
	time:=0;
	fstep:=0;
	cstep:=0;
	fd:=1;
	cd:=1;
	while ((fstep<=400) or (cstep<=400)) and ((f[1]<>c[1]) or (f[2]<>c[2])) do
	begin
		inc(time);
		if ((f[1]+dx[fd]>0) and (f[1]+dx[fd]<=10) and (f[2]+dy[fd]>0) and (f[2]+dy[fd]<=10)) and  (map[f[1]+dx[fd],f[2]+dy[fd]]<>'*') then
		begin
			f[1]:=f[1]+dx[fd];
			f[2]:=f[2]+dy[fd];
			inc(fstep);
			//fd:=1;
		end
		else begin inc(fd); fd:=((fd-1) mod 4)+1; end;
		if ((c[1]+dx[cd]>0) and (c[1]+dx[cd]<=10) and (c[2]+dy[cd]>0) and (c[2]+dy[cd]<=10)) and (map[c[1]+dx[cd],c[2]+dy[cd]]<>'*') then
		begin
			c[1]:=c[1]+dx[cd];
			c[2]:=c[2]+dy[cd];
			inc(cstep);
			//cd:=1;
		end
		else begin inc(cd); cd:=((cd-1) mod 4)+1; end;
	end;
	
	if (f[1]=c[1]) and (f[2]=c[2]) then writeln(time)
	else writeln(0);
	
	close(input);
	close(output);
end.