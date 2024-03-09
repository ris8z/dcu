dn(a, f).
dn(b, g).
dn(c, h).
dn(d, i).
dn(e, j).
dn(f, k).
dn(g, l).
dn(h, m).
dn(i, n).
dn(j, o).
dn(k, p).
dn(l, q).
dn(m, r).
dn(n, s).
dn(o, t).

dw(a, b).
dw(b, c).
dw(c, d).
dw(d, e).
dw(e, f).
dw(f, g).
dw(h, i).
dw(i, j).
dw(j, k).
dw(k, l).
dw(l, m).
dw(m, n).
dw(n, o).
dw(o, q).
dw(q, r).
dw(r, s).
dw(s, t).


ds(X,Y):- dn(Y,X).
de(X,Y):- dw(Y,X).

% x is at NordWest of Y, if is at weast of the number that is at nord
% of Y
nw(X,Y):- dw(X,Z), dn(Z,Y).
se(X,Y):- nw(Y,X).

% x is at NordEst of Y, if is at dw of the number dn of Y
ne(X,Y):- dn(Z,Y), de(X,Z).
sw(X,Y):- ne(Y,X).






