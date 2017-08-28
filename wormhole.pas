{
ID:10179811
PROG:wormhole
LANG:PASCAL
#FILE
}

type
	arr=record
			x,y:longint;
		end;

var
	loc:array[1..12] of arr;
        be,closed:array[1..12] of longint;
	n,ans,i,j,min,k:longint;

function check:boolean;
var
        i,j,x:longint;
        nohole:boolean;
begin
        for i:=1 to n do
        begin
                x:=i;
                nohole:=false;
                repeat
                        if closed[x]<>0 then x:=be[closed[x]]
                        else nohole:=true;
                until (x=i) or nohole;
                if (x=i) and (not nohole) then exit(true);
        end;
        exit(false);
end;

procedure dfs(k:longint);
var
	i,j,l:longint;
begin
        if k=n div 2+1 then
        begin
                if check then inc(ans);
                exit;
        end;
        for i:=1 to n do if be[i]=0 then begin l:=i; break; end;
        for i:=l+1 to n do
                if be[i]=0 then
                begin
                        be[l]:=i;
                        be[i]:=l;
                        dfs(k+1);
                        be[i]:=0;
                end;
        be[l]:=0;
end;

begin
	assign(input,'wormhole.in'); reset(input);
	assign(output,'wormhole.out'); rewrite(output);

	readln(n);
	for i:=1 to n do readln(loc[i].x,loc[i].y);
        fillchar(closed,sizeof(closed),0);
        for i:=1 to n do
        begin
                min:=maxlongint;
                k:=0;
                for j:=1 to n do
                        if (i<>j) and (loc[i].y=loc[j].y) and (loc[i].x<loc[j].x) and (loc[j].x-loc[i].x<min) then
                        begin
                                k:=j;
                                min:=loc[j].x-loc[i].x;
                        end;
                closed[i]:=k;
        end;

	ans:=0;
        fillchar(be,sizeof(be),0);
	dfs(1);
        writeln(ans);

	close(input);
	close(output);
end.
