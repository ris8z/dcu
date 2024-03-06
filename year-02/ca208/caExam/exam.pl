road(nap, cas, 5).
road(cas, rom, 4).
road(rom, ibiza, 10).
road(mil, monz, 3).

%Q1
between(X, Y, Z):-
    road(X, Y, _),
    road(Y, Z, _).

closeTo(X, Y):-
    road(X, Y, N),
    N =< 3.


%Q2

route(A, B):-
    road(A, B, _).

route(A, B):-
    road(A, C, _),
    route(C, B).

%Q3

sum(0, []).
sum(Sum, [Head|Tail]):-
    sum(TailSum, Tail),
    Sum is TailSum + Head.

maximum(0, []).
maximum(Max, [Head|Tail]):-
    maximum(TailMax, Tail),
    (Head >= TailMax -> Max = Head; Max = TailMax).
