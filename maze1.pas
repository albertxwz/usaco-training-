{
ID:10179811
PROG:maze1
LANG:PASCAL
#FILE
}

type
	dir=array[1..2] of integer;

const
	dx:array[1..4] of integer=(1,0,-1,0);
	dy:array[1..4] of integer=(0,1,0,-1);

var
	map:string;
	step:array[1..201,1..80] of longint;
	x,y:array[1..2] of longint;
	flag,map1:array[0..202,0..80] of boolean;
	queue:array[0..100000] of dir;
	i,j,p,w,h,max,head,tail:longint;

procedure floodfill(i,j:longint);
var
	k:integer;
begin
	head:=0;
	flag[i,j]:=true;
	queue[head,1]:=i;
	queue[head,2]:=j;
	tail:=0;
	repeat
		for k:=1 to 4 do
			if not(flag[queue[head,1]+dx[k],queue[head,2]+dy[k]]) and map1[queue[head,1]+dx[k],queue[head,2]+dy[k]] and (step[queue[head,1],queue[head,2]]+1<step[queue[head,1]+dx[k],queue[head,2]+dy[k]]) then
			begin
				inc(tail);
				queue[tail,1]:=queue[head,1]+dx[k];
				queue[tail,2]:=queue[head,2]+dy[k];
				flag[queue[tail,1],queue[tail,2]]:=true;
				step[queue[tail,1],queue[tail,2]]:=step[queue[head,1],queue[head,2]]+1;
			end;
		inc(head);
	until head>tail;
end;

begin
	
	assign(input,'maze1.in'); reset(input);
	assign(output,'maze1.out'); rewrite(output);
	
	readln(w,h);
	for i:=1 to 2*h+1 do
	begin
		readln(map);
		if (i=1) or (i=2*h+1) then
		begin
			j:=1;
			while j<=2*w+1 do
			begin
				if map[j]=' ' then
				begin
					inc(p);
					x[p]:=i;
					y[p]:=j;
				end;
				inc(j);
			end;
		end;
		if map[2*w+1]=' ' then
		begin
			inc(p);
			x[p]:=i;
			y[p]:=2*w+1;
		end;
		if map[1]=' ' then
		begin
			inc(p);
			x[p]:=i;
			y[p]:=1;
		end;
		for j:=1 to 2*w+1 do
			if map[j]=' ' then map1[i,j]:=true;
	end;
		
	fillchar(step,sizeof(step),$7f);
	step[x[1],y[1]]:=0;
	step[x[2],y[2]]:=0;
	floodfill(x[1],y[1]);
	fillchar(flag,sizeof(flag),false);
	floodfill(x[2],y[2]);
	max:=0;
	for i:=2 to 2*h do
		for j:=2 to 2*w do
			if (step[i,j]>max) and map1[i,j] and (i mod 2=0) and (j mod 2=0) then max:=step[i,j];

	writeln((max+1) div 2);
	
	close(input);
	close(output);

end.