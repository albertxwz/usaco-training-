{
ID:10179811
PROG:nocows
LANG:PASCAL
#FILE
}

var
	tree:array[1..200,0..100] of longint;
	n,k,i,j,l:longint;

begin
	assign(input,'nocows.in');
	reset(input);
	assign(output,'nocows.out');
	rewrite(output);

	readln(n,k);
	
	fillchar(tree,sizeof(tree),0);
	for i:=1 to k do tree[1,i]:=1;
	for i:=1 to k do
		for j:=1 to n do
			if j mod 2=1 then
				for l:=1 to j-2 do
					tree[j,i]:=(tree[j,i]+tree[j-1-l,i-1]*tree[l,i-1]) mod 9901;
					
	writeln((tree[n,k]+9901-tree[n,k-1]) mod 9901);
	
	close(input);
	close(output);
end.
