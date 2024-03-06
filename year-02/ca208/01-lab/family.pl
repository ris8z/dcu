%parents(child, father, mohter)
parents(david, george, noreen).
parents(jennifer, george, noreen).
parents(georgejr, george, noreen).
parents(scott, george, noreen).
parents(joanne, george, noreen).
parents(jessica, david, edel).
parents(clara, david, edel).
parents(michael, david, edel).
parents(laura, georgejr, susan).
parents(anna, scott, siobhan).
parents(edel, mick, peggy).
parents(maria, mick, peggy).
parents(assumpta, mick, peggy).
parents(patrick, kevin, maria).
parents(hugh, kevin, maria).
parents(helena, kevin, maria).
parents(roisin, win, assumpta).


%x is the father of Y
father(X, Y):-
              parents(Y, X, _).
%x is male
male(X):-
             father(X, _).

%X is the mother of Y
mother(X, Y):-
             parents(Y, _, X).
%x is famle
famle(X):-
             mother(X, _).

%X is a parent of Y
parent(X, Y):- father(X, Y); mother(X, Y).

%x is the grandfather of Y
grandfather(X, Y):-
              father(X, Z),
              parent(Z, Y).

%x is the grandmother of Y
grandmother(X, Y):-
              mother(X, Z),
              parent(Z, Y).
%x is the brother of Y
brother(X, Y):-
              male(X),
              parents(X, F, M),
              parents(Y, F, M),
              X \== Y.
%x is the sister of Y
sister(X, Y):-
              famle(X),
              parents(X, F, M),
              parents(Y, F, M),
              X \== Y.
%X is the uncle of Y(so x is the brother of one of the parents of y)
unlce(X, Y):-
              brother(X, Z),
              parent(Z, Y).
%x is the aunt of Y(so x is the sister of one of the parents of y)
aunt(X, Y):-
              sister(X, Z),
              parent(Z, Y).
%x is a sibling of Y(so x is either the bro of thet sis of Y)
sibling(X, Y):-
              brother(X, Y); sister(X, Y).
%x is the coustin of Y(one of the parent of x and y must be sisbingn)
cousin(X, Y):-
              parent(Z1, X),
              parent(Z2, Y),
              sibling(Z1, Z2).













