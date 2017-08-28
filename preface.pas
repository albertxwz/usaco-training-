{
ID:10179811
PROG:preface
LANG:PASCAL
#FILE
}

const
  shu:array[1..4,0..9] of string=(('','I','II','III','IV','V','VI','VII','VIII','IX'),
                                  ('','X','XX','XXX','XL','L','LX','LXX','LXXX','XC'),
								  ('','C','CC','CCC','CD','D','DC','DCC','DCCC','CM'),
								  ('','M','MM','MMM','','','','','',''));
  luoma:array[1..7] of char=('I','V','X','L','C','D','M');

var
  a:array[1..7] of longint;
  i,k,temp,n:longint;

procedure stat(s:string);
var
  i:longint;
begin
  for i:=1 to length(s) do
    case s[i] of
	  'I':inc(a[1]);
	  'V':inc(a[2]);
	  'X':inc(a[3]);
	  'L':inc(a[4]);
	  'C':inc(a[5]);
	  'D':inc(a[6]);
	  'M':inc(a[7]);
	end;
end;

begin
  assign(input,'preface.in');
  reset(input);
  assign(output,'preface.out');
  rewrite(output);
  readln(n);
  fillchar(a,sizeof(a),0);
  for i:=1 to n do
  begin
    temp:=i;
	k:=0;
	while temp<>0 do
	begin
	  inc(k);
	  stat(shu[k,temp mod 10]);
	  temp:=temp div 10;
	end;
  end;
  for i:=1 to 7 do
    if a[i]<>0 then
	  writeln(luoma[i],' ',a[i]);
  close(input);
  close(output);
end.

