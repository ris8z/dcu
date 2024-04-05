% Student: Giusppe Esposito
% Student number:  22702705

%Travel Modes (speed in km/h)
speed('f', 5).
speed('c', 80).
speed('t', 100).
speed('p', 500).



%Routes (distance in km)
route(dublin, cork, 200, 'fct').
route(cork, dublin, 200, 'fct').
route(cork, corkAirport, 20, 'fc').
route(corkAirport, cork, 25, 'fc').
route(dublin, dublinAirport, 10, 'fc').
route(dublinAirport, dublin, 20, 'fc').
route(dublinAirport, corkAirport, 225, 'p').
route(corkAirport, dublinAirport, 225, 'p').
route(naples, rome, 200, 't').



journey(S, D, M):-
        get_all_paths(S, D, M, Paths),
        get_min_path(Minpath, Paths),
        writeln(Minpath),!.



get_all_paths(Start, Destination, Modes, Paths):-
        findall([Time, Path], build_path(Start, Destination, Modes, [Start], Path, Time), Paths).



get_min_path(X, [X]).
get_min_path(MinElement, [[Mnumber|Mpath]|Tail]):-
        get_min_path([TailMnumber|TailMpath], Tail),
        (Mnumber < TailMnumber -> MinElement = [Mnumber|Mpath]; MinElement = [TailMnumber|TailMpath]).



build_path(Start, Destination, Modes, Visited, [Start, Destination], Time):-
        route(Start, Destination, Distance, PossibleModes),
        not_in(Destination, Visited),

        get_travel_modes(PossibleModes, Modes, TravelMods),
        get_delta_time(TravelMods, Distance, Time).



build_path(Start, Destination, Modes, Visited, [Start|Path], Time):-
        route(Start, Between, Distance, PossibleModes),
        not_in(Between, Visited),

        get_travel_modes(PossibleModes, Modes, TravelMods),
        get_delta_time(TravelMods, Distance, Dtime),

        build_path(Between, Destination, Modes, [Between|Visited], Path, TailTime),

        Time is Dtime + TailTime.



not_in(_, []):-!.
not_in(X, [Head|Tail]):-
        X \= Head,
        not_in(X, Tail).



get_travel_modes(Str1, Str2, TravelMods):-
        string_chars(Str1, L1),
        string_chars(Str2, L2),
        intersection(L1, L2, TravelMods),
        TravelMods \= [].



get_delta_time(TravelMods, Distance, Dtime):-
        get_max_speed(Speed, TravelMods),
        Dtime is Distance / Speed.



get_max_speed(0, []).
get_max_speed(Speed, [Head|Tail]):-
        get_max_speed(TailSpeed, Tail),
        speed(Head, HeadSpeed),
        (HeadSpeed > TailSpeed -> Speed = HeadSpeed; Speed = TailSpeed).
