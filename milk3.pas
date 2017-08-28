{
ID:10179811
PROG:milk3
LANG:PASCAL
#FILE
}

type
  classes=record					//把A,B,C三个瓶子封装在一个整体内
            data:array[1..3]of integer;
		  end;
var
  milk:array[0..100000] of classes;	  //队列
  poss:array[1..100000]of longint;
  a:array[1..3]of integer;
  i,h,t,n:longint;

function check(new:classes):boolean; 	//判重
var
  i,j:longint;
  flag:boolean;
begin
  for i:=0 to t do
  begin
    flag:=true;
    for j:=1 to 3 do
	  if milk[i].data[j]<>new.data[j] then
	  begin
	    flag:=false;
		break;
	  end;
	if flag then exit(false);
  end;
  exit(true);
end;

function push(p:classes;outt,inn:integer):classes;		//倒牛奶
begin
  with p do
    if data[outt]+data[inn]>=a[inn] then
    begin
	  data[outt]:=data[outt]-a[inn]+data[inn];
	  data[inn]:=a[inn];
	end
	else begin
	  data[inn]:=data[outt]+data[inn];
	  data[outt]:=0;
	end;
  push:=p;
end;

procedure bfs;				//广搜
var
  i,j:longint;
begin
  repeat
    for i:=1 to 3 do
      for j:=1 to 3 do
	    if (i<>j) and (milk[h].data[i]<>0) and (milk[h].data[j]<>a[j]) and (check(push(milk[h],i,j))) then
		begin
		  inc(t);
		  milk[t]:=push(milk[h],i,j);
		  if milk[t].data[1]=0 then
		  begin
		    inc(n);
		    poss[n]:=milk[t].data[3];
		  end;
		end;
	inc(h);
  until h>t;
end;

procedure qsort(h,t:longint);
var
  m,i,j,temp:longint;
begin
  m:=poss[(h+t) div 2];
  i:=h;
  j:=t;
  repeat
    while poss[i]<m do inc(i);
	while poss[j]>m do dec(j);
	if i<=j then
	begin
	  temp:=poss[i];
	  poss[i]:=poss[j];
	  poss[j]:=temp;
	  inc(i); dec(j);
	end;
  until i>j;
  if h<j then qsort(h,j);
  if i<t then qsort(i,t);
end;

begin
  assign(input,'milk3.in');
  assign(output,'milk3.out');
  reset(input);
  rewrite(output);
  readln(a[1],a[2],a[3]);
  poss[1]:=a[3];
  h:=0;
  t:=0;
  milk[0].data[1]:=0;
  milk[0].data[2]:=0;
  milk[0].data[3]:=a[3];
  n:=1;
  bfs;
  qsort(1,n);
  for i:=1 to n-1 do
    write(poss[i],' ');
  writeln(poss[n]);
  close(input);
  close(output);
end.
