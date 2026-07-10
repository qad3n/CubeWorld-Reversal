# Cube World Reconstructed Source (Cube.exe and Server.exe)

This is a reverse-engineered source tree for Cube World's client (`Cube.exe`) and dedicated
server (`Server.exe`). The binaries are the 2013 Alpha build with the paraglider fix. Both are
32-bit Windows binaries built with MSVC 2012 in C++ with RTTI intact and no PDB shipped. The code
here was recovered with Ghidra 12.1.2 running headless.

The goal was to rebuild the game's original class and file layout, not to produce a compilable
copy. Ghidra gives us the decompiled function bodies; the RTTI type information plus call-graph
analysis let us group those functions back into the classes and subsystems they came from.

## What this is, and what it is not

It is the real class architecture, taken from the RTTI `cube::` namespaces, split into per-class
`.h` and `.cpp` files by subsystem, with recovered structs and the decompiled C for every game
function.

It is not the original source and it does not build. Optimized and stripped MSVC output cannot be
perfectly recovered. Function bodies are decompiler pseudo-C, and helpers that automation could not
name keep their `FUN_<addr>` labels. For those, see `GAP_ANALYSIS.md` in each binary's folder and
the inline notes from the audit pass.

## Layout

Each binary has its own folder: `cube/` is the client, `server/` is the dedicated server. Folders
shared by both:

```
world/      World, Zone, Region, Dungeon, House, Spawn, Field
            (the client also has Chunk, ChunkBuffer, LandscapeTile, WorldInfo, WorldMap, ZoneTile)
entity/     Creature, Sprite, SpriteManager, Speech, QuestText, QuestTextNode
ai/         cube::Behavior tree: Combat, Companion, RandomWalk, WalkPath, LookAtPlayer,
            RandomInteraction, Sequential, SpawnLocation
db/         cube::Database  (SQLite glue)
net/        cube::Server, cube::Connection  (server only; WinSock game protocol)
game_misc/  game functions with no single owning class
_library/   statically linked third-party code (SQLite, CRT/STL, FreeType), set aside
include/    cube_types.h, the recovered structs and types
```

Client-only folders:

```
ui/         Widget classes (inventory, chat, skills, map, and so on)
render/     CubeShader
audio/      Music, XAudio2Engine
control/    Controller, GameController
```

The server's `world/` is a subset of the client's, and only the server keeps a `net/` folder.

Two index files sit next to the code in each binary folder:

- `attribution.tsv` lists every function with its address, name, kind (game, gamemisc, or lib),
  and target class.
- `GAP_ANALYSIS.md` records a best-effort name, purpose, and confidence for every function that
  automation left as `FUN_`. The same notes appear inline as `/* [AUDIT] */` comments above those
  functions in the `.cpp` files.

## How functions were sorted

1. RTTI seeds each `cube::X` vtable, so its virtual methods and constructors attach to class X.
2. Library code is detected by its own fingerprints (SQLite error and pragma strings, CRT and STL
   names) and expanded through the call graph, then moved into `_library/`. It is open source, so
   it is not reconstructed.
3. An unnamed function called mostly by one class's methods is attributed to that class.
4. Whatever is left and still reachable from game code goes to `game_misc/`. Code the game never
   calls goes to `_library/other`.

## Numbers

| | Cube.exe (client) | Server.exe |
|---|---|---|
| Total functions | 12,983 | 6,152 |
| Decompiled OK | 12,980 | 6,151 |
| Game code (class plus game_misc) | 1,370 | 288 |
| attributed to a class | 833 | 180 |
| game_misc helpers | 537 | 108 |
| Library (SQLite, STL, CRT, FreeType) | 11,613 | 5,864 |
| cube:: classes recovered | 55 | 25 |
| Inline audit comments added | 3,390 | 1,359 |
| Coverage of FUN_ game funcs | 100% (1,125/1,125) | 100% (209/209) |

Recovered structs and types are exported to each binary's `include/cube_types.h`.

23 of the `cube::` classes are shared between client and server. These are the game-logic core:
World, Zone, Region, Creature, Database, the Behavior AI tree, and so on.

## Reading tips

- Start from a subsystem's class file. Virtual methods are named `Class::vfunc_N` and constructors
  `Class::ctor_N`.
- Every function block starts with `/* <ns>::<name> @ <addr> */`. That address maps back to the
  binary and to the raw Ghidra artifacts (full disassembly, string cross-references, call graph).
- You can ignore `_library/` if you only care about game logic.

## Provenance

The original build path was left in the binary: `C:\Users\funck\Projects\Cube\OptimizedXP\Cube.pdb`,
with a matching `Server.pdb` path in the server. `funck` and the string `Wollay` both appear in the
binary, pointing at Wolfram von Funck (Wollay).

The engine and platform code sits under separate namespaces. `plasma::` is the Plasma engine, with
roughly 95 classes (Widget, Engine, Font, FontEngine, D3D9Engine, Shape, ObjectManager, and more);
its object stream format is the `.plx` files, tagged internally as `PlasmaGraphics`. `abstr::` is a
smaller reflection and method-binding layer. `Concurrency::` is Microsoft's Parallel Patterns
Library.

SQLite 3.7.15.2 is statically linked. `zlib` (1.2.3), `FreeImage`, `XAudio2`, and the MSVC 2012
runtime (`msvcp110`, `msvcr110`) are external DLLs. The four `data*.db` files are SQLite key/value
blob stores keyed by asset filename.

## Attribution and legal notice

Cube World and all of its original code, assets, names, and trademarks belong to their owners:
Picroma and Wollay (Wolfram von Funck), the creators of Cube World. All rights to the original
game are theirs.

This repository is an unofficial fan project for education and interoperability research only. It
ships no original game binaries, assets, or data files (`Cube.exe`, `Server.exe`, `data*.db`,
`*.plx`, and the like); it contains only source code reconstructed by static analysis of the
shipped binaries. It is not affiliated with, endorsed by, or supported by Picroma or Wollay. If you
hold rights to Cube World and want anything here changed or removed, please open an issue.

To use anything in this repository you must own a legitimate copy of Cube World.
