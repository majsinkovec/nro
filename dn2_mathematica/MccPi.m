(* ::Package:: *)

MccPi[n_]:=
Block[{dvojica}, Table[dvojica=RandomReal[{-1, 1}, 2];not={}; zun={};
If[Norm[dvojica]<=1, AppendTo[not, {dvojica[[1]], dvojica[[2]]}], AppendTo[zun,{dvojica[[1]], dvojica[[2]]}]];
{Flatten[not], Flatten[zun]}, {n}]]
