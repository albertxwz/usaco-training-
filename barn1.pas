{
ID:10179811
PROG:barn1
LANG:PASCAL
#FILE
}
var
    a:array[0..201,1..2] of longint;
    b:array[0..200] of boolean;
    n,m,c,i,j,t,ans,k:longint;
    p:boolean;
begin
    assign(input,'barn1.in');reset(input);
    assign(output,'barn1.out');rewrite(output);
    readln(n,t,c);
    ans:=c;
    for i:=1 to c do begin readln(a[i,1]); a[i,2]:=a[i,1]; end;
    for i:=1 to c-1 do    
        for j:=i+1 to c do
            if a[i,1]>a[j,1] then begin
                a[0]:=a[i];
                a[i]:=a[j];
                a[j]:=a[0];
            end;
    fillchar(b,sizeof(b),0);
    for i:=2 to c do
        b[a[i,1]-a[i-1,2]]:=true;    
    i:=0;
    a[201,1]:=0;    
    a[201,2]:=0;
    while ans>n do begin
        k:=2;
        repeat inc(i); until b[i];     
        while (k<=c) and (ans>n) do begin
            p:=true;
            if a[k,1]-a[k-1,2]=i then begin    
                p:=false;
                a[k-1,2]:=a[k,2];
                for j:=k to c do a[j]:=a[j+1];     
                dec(c);
                dec(ans);
            end;
            if p then inc(k);
        end;
    end;
    t:=0;
    for i:=1 to c do inc(t,a[i,2]-a[i,1]+1);    
    writeln(t);
    close(input);close(output);
end. 