{
ID:1017981911
PROG:sort3
LANG:PASCAL
#FILE
}

var
  t:array[1..1000] of longint;
  a,b:array[1..3] of longint;
  i,j,n,ans,temp:longint;

begin
  assign(input,'sort3.in');
  reset(input);
  assign(output,'sort3.out');
  rewrite(output);
  readln(n);
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),0);
  //找它们的位置！！！
  for i:=1 to n do
  begin
    readln(t[i]);
	inc(b[t[i]]);
  end;
  //找出1、2、3的开始及结束位置
  a[1]:=1;
  a[2]:=b[1]+1;
  a[3]:=b[1]+b[2]+1;
  b[3]:=b[1]+b[2]+b[3];
  b[2]:=b[1]+b[2];
  ans:=0;
  for i:=1 to n do
    if (i<a[t[i]]) or (i>b[t[i]]) then						//如果i这个位置的数是错的
	  for j:=a[t[i]] to b[t[i]] do
	    if (a[t[j]]<=i) and (b[t[j]]>=i) and (t[i]<>t[j]) then				//看看能不能可j调换使得两者都到正确位置
		begin
		  inc(ans);
		  temp:=t[i];
		  t[i]:=t[j];
		  t[j]:=temp;
		  break;
		end;
  for i:=a[1] to b[1] do					//找出1的位置有多少数是错的，加2就行了
    if t[i]<>1 then
	  ans:=ans+2;
  writeln(ans);
  close(input);
  close(output);
end.
