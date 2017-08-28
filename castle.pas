{
ID:10179811
PROG:castle
LANG:PASCAL
#FILE
}

const
  dx:array[1..4] of integer=(0,-1,0,1);			//这里需要注意的一点是按照题目的顺序比较好。
  dy:array[1..4] of integer=(-1,0,1,0);
  dir:array[1..4] of char=('E','N','E','N');

var
  flag:array[1..50,1..50,1..4] of boolean;		//这个是判断此坐标的东南西北处有无墙
  alway:array[1..50,1..50]of boolean;			//这个用来判断房间是否已被搜索
  jud:array[0..15,1..4] of boolean;				//这个可以有助于我们的预处理
  can:boolean;
  area,marea,m,n,i,j,k,l,jx,jy,d,x,num:longint;


procedure dfsFind(x,y:longint);					//寻找路径的搜索与回溯
var
  i:longint;
begin
  inc(area);									//每进入一个坐标就加1
  for i:=1 to 4 do
    if not(flag[x,y,i])and alway[x+dx[i],y+dy[i]] then		//判断是否可以走
	begin
	  alway[x+dx[i],y+dy[i]]:=false;
	  dfsFind(x+dx[i],y+dy[i]);
	end;
end;

begin
  assign(input,'castle.in');
  reset(input);
  assign(output,'castle.out');
  rewrite(output);
  readln(n,m);
  fillchar(jud,sizeof(jud),false);
  //以下的4个循环都是预处理
  for i:=0 to 1 do
    for j:=0 to 1 do
	  for k:=0 to 1 do
	    for l:=0 to 1 do
		begin
		  if i=1 then jud[i*1+j*2+k*4+l*8,1]:=true;
		  if j=1 then jud[i*1+j*2+k*4+l*8,2]:=true;
		  if k=1 then jud[i*1+j*2+k*4+l*8,3]:=true;
		  if l=1 then jud[i*1+j*2+k*4+l*8,4]:=true;
		end;
  fillchar(alway,sizeof(alway),true);
  for i:=1 to m do
    for j:=1 to n do
	begin
	  read(x);
	  flag[i,j]:=jud[x];
	end;
  num:=0;
  marea:=0;
  //搜索房间，这不用我说了吧
  for i:=1 to m do
    for j:=1 to n do
    if alway[i,j] then
	begin
	  area:=0;
	  inc(num);
	  alway[i,j]:=false;
      dfsFind(i,j);
	  if area>marea then marea:=area;
	end;
  writeln(num);
  writeln(marea);
  marea:=0;
  //我把推墙和搜索最大房间分开来写
  for j:=1 to n do
    for i:=m downto 1 do		//这两个循环为什么要这样写呢？自己想
	  for k:=1 to 4 do			//枚举四个方向的墙
	  begin
	    fillchar(alway,sizeof(alway),true);
		//推墙有限制
	    if ((i>1) or (k<>2)) and ((i<m) or (k<>4)) and ((j>1) or (k<>1)) and ((j<n) or (k<>3)) then
        begin
		  can:=false;
		  if flag[i,j,k] then
		  begin
		    flag[i,j,k]:=false;
			can:=true;
		  end
		  else continue;
		  area:=0;
		  if can then 
		  begin
		    alway[i,j]:=false;
		    dfsFind(i,j);		//再搜索房间
		  end;
		  flag[i,j,k]:=true;
		  if area>marea then
		  begin
		    marea:=area;
			jx:=i;
			jy:=j;
			d:=k;
		  end;
		end;
	  end;
  writeln(marea);
  writeln(jx,' ',jy,' ',dir[d]);
  close(input);
  close(output);
end.
