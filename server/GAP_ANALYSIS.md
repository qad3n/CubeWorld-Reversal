# Semantic Gap Analysis — server

Best-effort analysis of functions automation could not name (still `FUN_`), from the
sub-agent audit: proposed name, purpose, confidence, key variables. Inline `[AUDIT]`
comments with the same content are also written above each function in the .cpp files.

**1369 functions analyzed** — confidence: high=767, med=483, low=119.

## audit (450)

| addr | proposed name | conf | purpose |
|---|---|---|---|
| 402ed0 | `RBTree_destroyRec` | high | Recursively destroys rb-tree nodes, freeing node+0x10 buffer and node; postorder delete |
| 406310 | `Vector_destroyTriples` | high | Destroys vector of 12-byte {ptr,?,?} elements from param_1 to param_2, deleting first field |
| 407a50 | `RBTree_iterIncrement` | high | std::_Rb_tree iterator increment (++): finds in-order successor node |
| 407c20 | `RBTree_destroyRecursive` | high | Recursively destroys a red-black tree/map subtree, freeing each node's embedded std::string then the node |
| 40a1d0 | `RBTree_eraseNode_plain` | high | Erases one RB-tree node (no owned payload), rebalances colors, operator_delete node |
| 412b60 | `vector_reallocate` | high | Reallocates a std::vector buffer to param_1 bytes, memmove-copies old contents, frees old, updates ptrs |
| 412bd0 | `vector_growToFit` | high | Ensures vector capacity >= requested; computes 1.5x growth (or requested) then calls reallocate |
| 413180 | `vector_resizeZero` | high | Resizes a byte vector to param_1: shrinks in place or grows (growToFit) and zero-fills new tail |
| 416a90 | `u16string_moveConstruct` | high | Move-constructs a std::u16string (2-byte chars, SSO cap 7): steals heap ptr or memmoves inline, resets source |
| 416b00 | `U16String_ctorFromCStr` | high | std::u16string ctor from null-terminated wide C-string; inits SSO capacity then computes length and assigns |
| 416b90 | `U16String_assignFromCStr` | high | std::u16string::assign from null-terminated wide C-string; computes length via 2-byte scan then assigns |
| 416d60 | `U16String_reallocGrow` | high | Grows string buffer: computes new capacity (~1.5x, cap 0x7ffffffe), operator_new, memcpy old data, operator_delete old |
| 417170 | `U16String_appendFill` | high | std::u16string append/resize by param_1 copies of char param_2; grows if needed, writes NUL terminator |
| 4172f0 | `U16String_assignSubstr` | high | std::u16string::assign(other,pos,count); handles self-assign (erase prefix) vs copy; bounds-checked |
| 417410 | `U16String_assignPtrCount` | high | std::u16string::assign(ptr,count); detects ptr aliasing own buffer and reroutes to substr-assign, else copies |
| 417d50 | `U16String_erase` | high | std::u16string::erase(pos,count): memmove tail down or truncate; sets len and NUL terminator |
| 419ef0 | `wstring_compareSubstr` | high | std::wstring::compare of substring [param_1,+param_2) against buffer param_3/param_4; returns -1/0/1 |
| 419f90 | `wstring_ctorFromSubstr` | high | Initializes empty wstring header then assigns substring [param_2,param_3) via FUN_004172f0 |
| 41a240 | `RBTree_eraseNode` | high | Removes one node from red-black tree with successor splice and rebalance, then frees node's two wstrings |
| 41a5d0 | `RBTree_buyNodeStr` | high | Allocates tree node, default-constructs its wstring, guarded by SEH |
| 41a6f0 | `RBTree_copyRec` | high | Recursively deep-copies red-black tree nodes (left/right children, color, parent links) |
| 41a7b0 | `RBTree_insertRebalance` | high | Inserts a bought node into RB-tree and performs rotations/recolor to restore invariants |
| 41ae40 | `wstring_lessCompare` | high | Comparator: returns true if key wstring param_2 < stored wstring param_1 (map ordering predicate) |
| 428100 | `list_destroyWstrings` | high | Clears a list of nodes each holding a wstring (offset 0x10), freeing string then node |
| 4294b0 | `rbtree_cloneSubtree` | high | Recursively deep-copies RB-tree nodes (left via *node, right via node[2]) allocating via 4290d0; std::map clone helper |
| 429570 | `std_map_insertRebalance_str2` | high | RB-tree insert fixup with red/black rotations; overflow throws _Xlength_error 'map/set<T> too long'; frees 2-str node; std::map |
| 4297a0 | `std_map_insertRebalance_SpeechNode` | high | RB-tree insert fixup (rotations); overflow cleans Speech node via 42c2e0; std::map 'map/set<T> too long' |
| 4299b0 | `std_map_insertRebalance_variantC` | high | RB-tree insert fixup; overflow cleans node via 42d060; std::map insert rebalance |
| 429bc0 | `std_map_insertRebalance_QuestText` | high | RB-tree insert fixup; overflow cleans QuestText node (ctor_3 + string) then throws; std::map |
| 429e40 | `std_map_insertHint_intKey` | high | Chooses insert side vs hint using int-key compare (07a50/dad80 = ++/--) then calls 429570; std::map hinted insert |
| 42a070 | `std_map_insertHint_strKey` | high | Hinted map insert with std::string-key compare (419ef0); falls back to 4c7c50/4c6d20; std::map, not game_misc |
| 42a260 | `std_map_insertHint_strKey_Speech` | high | Same hinted string-key map insert; uses 4297a0/42a970 (Speech node); std::map |
| 42a450 | `std_map_insertHint_strKey_variantC` | high | Hinted string-key map insert; uses 4299b0/42aae0; std::map |
| 42a640 | `std_map_insertHint_strKey_QuestText` | high | Hinted string-key map insert; uses 42ac40/429bc0 (QuestText node); std::map |
| 42a830 | `std_map_insertLowerBound_intKey` | high | Walks tree by int key to find insert slot; frees dup node or calls 429570; std::map _Insert_hint |
| 42a970 | `std_map_insertLowerBound_strKey_Speech` | high | Walks tree by string key (419ef0) to insert slot; dup frees Speech node (42c2e0); std::map |
| 42aae0 | `std_map_insertLowerBound_strKey_variantC` | high | String-key lower-bound insert; dup frees node via 42d060; std::map |
| 42ac40 | `std_map_insertLowerBound_strKey_QuestText` | high | String-key lower-bound insert; dup frees QuestText node (42d0c0); std::map |
| 42ada0 | `std_list_appendCopy_strNodes` | high | Appends copies of source list range as new nodes (4291a0); 'list<T> too long' guard; std::list assign |
| 42ae70 | `std_list_assignCopy_Speech` | high | Copy-assigns a std::list<string>: reuses existing nodes (copies strings) then erases surplus via 42e000; Speech |
| 42af50 | `std_use_facet_ctype_wchar` | high | MSVC std::use_facet<ctype<wchar_t>>: locate/register facet, throw std::bad_cast 'bad cast'; STL, not Speech |
| 42c6f0 | `std_iterator_notEqual` | high | Returns *this != *param_1 (iterator/pointer inequality); trivial |
| 42c710 | `std_map_subscript_intKey` | high | map::operator[] for int key: lower-bound search then insert default-constructed value (42cf80 path) if absent |
| 42cea0 | `std_map_makeHeader_0x2c` | high | operator_new(0x2c) RB-tree header/sentinel: self-links left/parent/right, sets nil+red flags 0x101; std::map _Buynode |
| 42ced0 | `std_map_makeHeader_0x38` | high | operator_new(0x38) RB-tree header node self-linked, flags 0x101; std::map sentinel builder |
| 42cf00 | `std_map_allocRawNode_0x2c` | high | operator_new(0x2c) node; sets 3 link words from *param_1 (sentinel); std::map node allocator |
| 42cf40 | `std_map_allocRawNode_0x38` | high | operator_new(0x38) node; link words from sentinel; std::map node allocator |
| 42cf80 | `std_map_allocRawNode_0x40` | high | operator_new(0x40) node; link words from sentinel; std::map node allocator |
| 42d140 | `rbtree_destroyRecursive_strNode` | high | Recursively frees RB-tree (right via [2], left via *node) freeing string(+0x14)+node; std::map clear |
| 42d1a0 | `rbtree_destroyRecursive_SpeechNode` | high | Recursively frees Speech RB-tree nodes: inner list(+0x30), string(+0x10), sublist(+0x28); std::map clear |
| 42d250 | `rbtree_destroyRecursive_QuestText` | high | Recursively frees QuestText RB-tree nodes (ctor_3 payload +0x28, string +0x10); std::map clear |
| 42d3d0 | `std_map_lowerBound_strKey` | high | Descends RB-tree comparing std::string key (419ef0) to return lower_bound node; std::map find |
| 42d420 | `rbtree_max` | high | Returns rightmost node of subtree (follow +8 while not nil); std::tree _Max |
| 42d440 | `rbtree_min` | high | Returns leftmost node of subtree (follow *node while not nil); std::tree _Min |
| 42d460 | `rbtree_rotateLeft` | high | Left rotation of RB-tree node about param_1; std::tree _Lrotate |
| 42d520 | `std_list_clear` | high | Destroys all std::list nodes (free string at +8) and re-inits head sentinel; std::list clear/dtor |
| 42d580 | `std_map_eraseRange_strNode` | high | Erases node range [first,last); special-cases full clear via 42d140; erases each via 42d640; std::map |
| 42d640 | `std_map_eraseNode_strNode` | high | Removes one RB-tree node with rebalance/rotations, frees string(+0x14)+node, decrements size; 'invalid map/set<T> iterator' |
| 42d8f0 | `std_map_eraseRange_SpeechNode` | high | Erases node range; full clear via 42d1a0 else per-node 42d9b0; std::map (Speech) |
| 42d9b0 | `std_map_eraseNode_SpeechNode` | high | Removes RB-tree node with rebalance; frees Speech payload (list+2 strings) inline; 'invalid map/set<T> iterator' |
| 42dc80 | `std_map_eraseRange_QuestText` | high | Erases node range; full clear via 42d250 else per-node 42dd40; std::map (QuestText) |
| 42dd40 | `std_map_eraseNode_QuestText` | high | Removes RB-tree node with rebalance; frees QuestText payload (ctor_3 +string); 'invalid map/set<T> iterator' |
| 42e000 | `std_list_eraseRange` | high | Erases list nodes in [first,last), unlinking and freeing string(+8); decrements size; std::list erase |
| 42f040 | `std_map_makeHeader_0x1c` | high | operator_new(0x1c) RB-tree header self-linked, flags 0x101; std::map/set sentinel builder |
| 42f1c0 | `rbtree_destroyRecursive_SpriteNode` | high | Recursively frees RB-tree Sprite nodes: clears list at node+5 then frees node; std::map clear |
| 42f440 | `std_vector_free` | high | Frees vector buffer (operator_delete) and zeros begin/end/cap; std::vector dtor; misattributed CombatBehavior |
| 42f4e0 | `std_map_eraseRange_SpriteNode` | high | Erases Sprite map node range; full clear via 42f1c0 else per-node 42f5a0; std::map |
| 42f5a0 | `std_map_eraseNode_SpriteNode` | high | Removes RB-tree node with rebalance then clears list payload (node+5) and frees; 'invalid map/set<T> iterator' |
| 462fe0 | `sqlite3_close` | high | Thin wrapper: FUN_00492580(db,0); SQLite sqlite3_close; class Database ok |
| 463120 | `sqlite3_exec` | high | SQLite sqlite3_exec: prepare/step each statement, invoke row callback with column text/names; misattributed Speech |
| 464e80 | `sqlite3_vfs_find` | high | Finds registered VFS by name in linked list under mutex; SQLite sqlite3_vfs_find |
| 4650e0 | `sqlite3_mutex_enter_ind` | high | Indirect call to mutex-enter (DAT_00582b18) if arg nonzero; SQLite mutex wrapper |
| 465120 | `sqlite3_mutex_leave_ind` | high | Indirect call to mutex-leave (DAT_00582b20) if arg nonzero; SQLite mutex wrapper |
| 466dd0 | `sqlite3_free` | high | Frees memory with allocator accounting/statistics (DAT_00582aec free); SQLite sqlite3_free/DbFree |
| 466fa0 | `sqlite3_randomness` | high | Fills param_2 with param_1 pseudo-random bytes (RC4 PRNG 487580) under mutex; SQLite sqlite3_randomness |
| 467f50 | `sqlite3_open` | high | Wrapper: openDatabase(4834d0, flags=6); SQLite sqlite3_open; misattributed Speech |
| 4683f0 | `sqlite3_log` | high | If log hook set (DAT_00582bac), formats and emits log message via 4885a0; SQLite sqlite3_log; misattributed Speech |
| 468670 | `sqlite3_errcode` | high | Validates db handle magic; returns errCode&errMask or MISUSE(0x15)/NOMEM(7); SQLite sqlite3_errcode |
| 468e30 | `sqlite3_prepare` | high | Wrapper: sqlite3Prepare(4a0180,...); SQLite sqlite3_prepare |
| 469510 | `sqlite3_bind_text` | high | Wrapper: bindText(4709e0,...,1); SQLite sqlite3_bind_text |
| 469a30 | `sqlite3_column_value` | high | Returns applied Mem value for column param_2 under mutex (4ae680); SQLite sqlite3_column_value |
| 469cb0 | `sqlite3_step` | high | SQLite sqlite3_step: runs VDBE, retries on SCHEMA(0x11) up to 5x re-preparing; 'API called with finalized/NULL prepared statement' |
| 469f40 | `sqlite3_column_int` | high | Fetches column value applying int affinity (4ae680) with mutex; SQLite sqlite3_column_int |
| 469fc0 | `sqlite3_column_bytes` | high | Returns byte length of column value (applies text/blob) with mutex; SQLite sqlite3_column_bytes |
| 46aa30 | `sqlite3_clear_bindings` | high | Resets all bound parameters of stmt (4b5e70 reset, 48ca70 apiExit); SQLite sqlite3_clear_bindings; 'API called with finalized...' |
| 46aab0 | `sqlite3_reset` | high | Resets a prepared statement (VdbeReset 4b8640, reinit state fields); SQLite sqlite3_reset; misattributed Speech |
| 46b2f0 | `btree_accessPayload` | high | Reads btree cell payload (param_2..+param_3) into buffer, traversing overflow pages; SQLite; 'database corruption' |
| 4709e0 | `sqlite3_bindValue` | high | Binds value to statement param (vdbeMemSetStr 4b79e0, apply encoding); SQLite bindText impl |
| 471200 | `btree_closeCursor` | high | Detaches btree cursor: frees overflow (48e9a0), unlinks from page/shared list (472880); SQLite sqlite3BtreeCloseCursor |
| 4712c0 | `btree_getAndInitPage` | high | Gets page param_2 (4a14c0) and initializes MemPage fields (pgno,flags,pBt); SQLite getAndInitPage |
| 471320 | `btree_initPage` | high | Parses MemPage cell pointers, computes nFree/nCell, validates; SQLite btreeInitPage; 'database corruption' |
| 471710 | `btree_parseCellPtr` | high | Parses a btree cell: decodes payload size (varint 49d440) and rowid (49d270), fills CellInfo; SQLite btreeParseCellPtr |
| 472880 | `btree_unlinkCursorOverflow` | high | Removes cursor from page overflow list, frees overflow entries, clears shared cursor flags; SQLite |
| 472d10 | `sqlite3_exprDelete` | high | Recursively frees an Expr tree and its sub-lists/tokens (Expr fields at 0xa..0x13); SQLite sqlite3ExprDelete |
| 474fe0 | `sqlite3_column_apiExit` | high | Sets stmt rc from db errCode after column access, leaves mutex; SQLite columnMallocFailure/apiExit |
| 475040 | `sqlite3_columnMem` | high | Returns Mem pointer for column param_2 (bounds-check) or dummy error Mem; SQLite columnMem |
| 4761f0 | `btree_copyPayload` | high | memcpy payload in given direction, with mutex/error check when writing (4a2c80); SQLite copyPayload |
| 4762d0 | `sqlite3_createCollation` | high | Registers/removes a collation seq; refuses modify with active statements; SQLite; 'unable to delete/modify collation sequence...' |
| 476810 | `btree_decodeFlags` | high | Decodes MemPage flags into leaf/intkey/cell offsets from page header; SQLite decodeFlags; 'database corruption' |
| 476d20 | `vdbe_displayP4` | high | Renders a VDBE P4 operand to text (keyinfo, collseq, vtab:%p:%p, %.16g, intarray, program, (blob)); SQLite displayP4 |
| 4799f0 | `sqlite3_findCollSeq` | high | Hash-lookup collation seq by name; creates+inserts entry if param_3 set; SQLite sqlite3FindCollSeq |
| 47bc80 | `vdbe_freeP4` | high | Frees a VDBE P4 operand by type (funcdef, mem, vtab, collseq, keyinfo...) via switch; SQLite freeP4 |
| 47c340 | `pager_freeSavepointBitvec` | high | Frees a bitvec (486af0) at pager+0x50 and nulls it; SQLite |
| 47c360 | `vdbe_freeAuxRef` | high | Decrements auxdata/funcarg refcount at +0x20 and frees when zero (494b00); SQLite |
| 47d150 | `btree_cacheCellSize` | high | Parses/caches current cell info for cursor when not yet cached (471710); SQLite getCellInfo |
| 47d460 | `btree_getOverflowPage` | high | Fetches next overflow page (via ptrmap or scan), returns page & next pgno; SQLite btree overflow walk |
| 47e8a0 | `pcache_pageInsert` | high | Inserts a PgHdr into a hash bucket / LRU list; SQLite pcache add-to-list |
| 47f590 | `pager_journalHdrOffset` | high | Rounds journal offset up to next sector boundary (alldiv/allmul by sector size); SQLite journalHdrOffset |
| 480650 | `sqlite3_mallocRaw` | high | Allocates via xMalloc with size/count accounting and soft-heap-limit check; SQLite mallocWithWarning |
| 483490 | `pager_pageToOffset` | high | Converts a negative page number to file offset (allmul/alldiv by page size); SQLite |
| 483c40 | `pager_lockDbDefault` | high | Acquires DB lock at level 4 (RESERVED) via VFS xLock, updates lock state; SQLite pagerLockDb |
| 483ca0 | `pager_lockDb` | high | Acquires DB lock at level param_2 via VFS xLock, updates eLock; SQLite pagerLockDb |
| 483cf0 | `pager_unlockAndRollback` | high | Unlocks/rolls back pager if in error/none state (4bac90); SQLite pagerUnlockAndRollback |
| 483dd0 | `pager_pageCount` | high | Computes DB size in pages from WAL or VFS xFileSize; SQLite sqlite3PagerPagecount |
| 484260 | `pager_syncJournal` | high | Syncs journal file (VFS xSync) unless nosync flag; SQLite pager syncJournal |
| 484370 | `pcache_releasePage` | high | Releases/unrefs a PgHdr: writes back or drops to free list per dirty state; SQLite sqlite3PcacheRelease |
| 4843d0 | `pager_unlockDb` | high | Releases DB lock (VFS xUnlock at +0x20) and updates eLock; SQLite pagerUnlockDb |
| 4844b0 | `pager_cksum` | high | Computes page checksum by sampling bytes at 200-byte stride; SQLite pager_cksum |
| 484930 | `pager_error` | high | Records IOERR/CORRUPT/FULL error code, sets pager to ERROR state (0xf=6); SQLite pager_error |
| 484ae0 | `pager_getSavepointPtr` | high | Looks up savepoint/bitvec entry for page (4a37e0) and returns it; SQLite thin helper |
| 485250 | `btree_invalidateAllCursors` | high | Marks all shared-cache cursors invalid and rolls back backend (4a3b00); SQLite invalidateAllOverflowCache |
| 485380 | `pcache_freePage` | high | Destroys a PgHdr page object: frees savepoints (487f30), releases file page, frees memory; SQLite pcacheFree/destroy |
| 4854a0 | `pager_lockWithRetry` | high | Acquires DB lock retrying on BUSY(5) via busy handler (+0x98); SQLite pagerLockDb w/ retry |
| 4856d0 | `pager_writeChangeCounter` | high | Writes incremented change counter and version into page1 header fields; SQLite write32bits changecounter |
| 4868a0 | `pcache_allocPage` | high | Allocates a page buffer from PCache free list or via mallocRaw; SQLite pcache1Alloc |
| 486af0 | `pcache_freePageMem` | high | Returns a page buffer to PCache free list or frees via xFree with accounting; SQLite pcache1Free |
| 486ed0 | `pcache_removeFromDirty` | high | Unlinks a PgHdr from the dirty page list, fixing head/tail/synced pointers; SQLite pcacheRemoveFromDirtyList |
| 486f40 | `btree_readCellPtrByte` | high | Reads a cell's leading byte (+optional 4-byte) at page param_2 via getPage (4a14c0); SQLite; 'database corruption' |
| 487070 | `btree_ptrmapPageno` | high | Computes the ptrmap page number that stores an entry for page param_2; SQLite ptrmapPageno |
| 4870c0 | `btree_ptrmapPut` | high | Sets a pointer-map entry (type,parent) for a page, allocating ptrmap page; SQLite ptrmapPut; 'database corruption' |
| 487690 | `pager_read32be` | high | Reads 4 bytes at offset from file (VFS xRead) and returns big-endian uint; SQLite read32bits |
| 4876e0 | `pager_readDbPage` | high | Reads a DB page from file/WAL (xRead) into cache buffer, captures page1 counters; SQLite readDbPage |
| 4877e0 | `pager_readJournalHeader` | high | Reads/validates a journal header (magic), records nRec/pageSize/sectorSize; SQLite readJournalHdr |
| 487a00 | `pager_readMasterJournal` | high | Reads super/master-journal name appended to journal, validates magic+checksum; SQLite readMasterJournal |
| 487f30 | `pager_freeSavepointArray` | high | Frees pager savepoint bitvecs (48e9a0) and the savepoint array; SQLite releaseAllSavepoints |
| 487fb0 | `vdbe_releaseMemArray` | high | Releases an array of param_2 Mem cells (frees strings/blobs, 40-byte stride); SQLite releaseMemArray |
| 4880a0 | `btree_releasePage` | high | Releases the page referenced by a btree cursor (+0x44) via pcacheRelease; SQLite releasePage |
| 488510 | `btree_unrefSharedCache` | high | Decrements shared BtShared refcount, unlinks from global list, frees mutex when zero; SQLite removeFromSharingList |
| 48b310 | `btree_clearCell` | high | Frees a cell's overflow-page chain and updates ptrmap entries (4870c0); SQLite clearCell |
| 48b530 | `pager_setSectorSize` | high | Determines pager sector size from VFS xSectorSize/xDeviceCharacteristics, clamps 0x200..0x10000 |
| 48b660 | `sqlite3_setupLookaside` | high | Configures a DB connection's lookaside memory pool (slot size/count linked free list); SQLite setupLookaside; misattributed Speech |
| 48ca70 | `sqlite3_apiExit` | high | Maps rc to db errMask, sets NOMEM on mallocFailed; SQLite sqlite3ApiExit |
| 48d6f0 | `sqlite3_autoExtensions` | high | Runs all registered auto-extensions on a new connection; logs failures; SQLite; 'automatic extension loading failed: %s' |
| 48f150 | `btree_dropCursor` | high | Removes one BtCursor: releases pages, unlinks from list, releases overflow cache; SQLite |
| 48f390 | `btree_commitPhaseTwo` | high | Commits btree phase two: commits pager (4a1bb0) and releases lock (471200); SQLite sqlite3BtreeCommitPhaseTwo |
| 48fbc0 | `btree_enter` | high | Enters a Btree's shared mutex, saving other locked cursors' state; SQLite sqlite3BtreeEnter |
| 48fca0 | `btree_enterAll` | high | Enters mutexes on all shared btrees of a connection (iterate aDb); SQLite sqlite3BtreeEnterAll |
| 490750 | `sqlite3BtreeLeave` | high | Release one BtShared mutex: decrement lock nRef at +0xc, on zero call sqlite3_mutex_leave(BtShared->mutex) |
| 490780 | `sqlite3BtreeLeaveAll` | high | Loop over db->aDb[] (base +0x10, count +0x14) releasing each Btree's shared mutex |
| 490e00 | `sqlite3BtreeOpen` | high | Open a Btree/BtShared (alloc 0x2c btree + 0x54 shared), handle ':memory:', shared-cache list; sets pager pagesize |
| 4916b0 | `sqlite3BtreeCommitPhaseOne` | high | Btree enter; save cursors, on locked call trip-cursors; fetch & update page1 change counter; btree leave |
| 491f60 | `sqlite3BtreeTripAllCursors` | high | Set all cursors on BtShared to fault state 3 with error code, drop cached pages |
| 4920e0 | `sqlite3CantopenError` | high | Report SQLITE_CANTOPEN(0xe) via sqlite3ReportError and return 0xe |
| 493af0 | `sqlite3CorruptError` | high | Report SQLITE_CORRUPT(0xb) via sqlite3ReportError and return 0xb |
| 493f20 | `sqlite3CreateFunc` | high | Register/replace a user SQL function (handles ANY-encoding fanout), guarding active statements |
| 494b00 | `sqlite3PageFree` | high | Return a page/allocation to pager page-cache free list or heap, updating memdb counters |
| 494b90 | `sqlite3PageMalloc` | high | Allocate from pager scratch/page pool (+0x100 free list) or fall back to sqlite3Malloc; set OOM flag |
| 494cf0 | `sqlite3PageRealloc` | high | Resize a pager-managed allocation, copying if moving between pool and heap |
| 494db0 | `sqlite3PageStrdup` | high | Duplicate a C string into a pager-managed allocation (strlen + PageMalloc + memcpy) |
| 495300 | `sqlite3DeleteTable` | high | Free a Table: remove columns from function/fkey hash, delete FKs, indices, ExprList defaults, then free |
| 495480 | `sqlite3SelectDelete` | high | Free a Select chain (pPrior at [8]): ExprLists, SrcList(0x2c), Where/Having/OrderBy/GroupBy exprs |
| 4961f0 | `sqlite3ErrorWithMsg` | high | Set db error code (+0x2c) and formatted message on connection, allocating/formatting error Mem |
| 496370 | `sqlite3ExpirePreparedStatements` | high | Mark every VDBE on db (list at +4, next +0x3c) as expired by setting flag bit 0x20 at +0x60 |
| 498790 | `sqlite3ExprDelete` | high | Recursively free an Expr node (left [2]/right [3]), its token string, ExprList/Select subtree |
| 499060 | `sqlite3ExprListDelete` | high | Free an ExprList: iterate items (stride 5), delete each Expr and span string, then free array |
| 4995c0 | `sqlite3FindFunction` | high | Find best-matching FuncDef in per-db and global hash by name/nArg/encoding; optionally create new |
| 49b0f0 | `sqlite3HashInsertElement` | high | Insert a hash element into the per-name function hash bucket, computing bucket from first byte+len |
| 49c920 | `sqlite3Get4byte` | high | Read a 4-byte big-endian unsigned int from buffer |
| 49d270 | `sqlite3GetVarint` | high | Decode a 1-9 byte SQLite varint into 64-bit result, returning byte count |
| 49d440 | `sqlite3GetVarint32` | high | Fast-path decode of a 1-3 byte varint, delegating to GetVarint for longer |
| 49d5c0 | `sqlite3PageFreeList` | high | Free a linked list of page allocations (head at param_1[2]), updating global memory stats under mutex |
| 49d6a0 | `sqlite3HashFind` | high | Look up key (param_2,len) in hash, returning associated data pointer or 0 |
| 49d6f0 | `sqlite3HashInsert` | high | Insert/replace/delete a hash entry; grow & rehash when load high; allocate HashElem(0x14) |
| 49d910 | `sqlite3IdListDelete` | high | Free an IdList: free each item name string then the array |
| 49fad0 | `sqlite3Close` | high | Tear down a database connection: free cursors, VTables, schema, funcs, collations, aggregate ctx, pager |
| 4a0180 | `sqlite3LockAndPrepare` | high | Safety-check + mutex-enter connection, run sqlite3Prepare, retry once on SCHEMA(0x11), release |
| 4a0350 | `sqlite3Malloc` | high | Allocate memory (size guard <0x7ffffeff) via configured xMalloc, tracking stats under mem mutex |
| 4a03c0 | `sqlite3MallocAlarm` | high | Invoke registered soft-heap-limit alarm callback once (re-entrancy guarded), around mem mutex |
| 4a1250 | `sqlite3OsClose` | high | Close an OS file: if handle open call pMethods->xClose(vtable+4) and null it |
| 4a1280 | `sqlite3OsCurrentTimeInt64` | high | Get current time as int64 ms: use xCurrentTimeInt64 if v>=2 else xCurrentTime*86400000 |
| 4a1350 | `sqlite3OsFileControl` | high | Invoke file vtable method at +8 (xFileControl-like) with 4 args |
| 4a1390 | `sqlite3OsWrite` | high | Invoke OS file vtable method at +0xc (xWrite) with buf/amt/offset args |
| 4a13b0 | `sqlite3PcacheBufferSetup` | high | Build page-cache buffer free-list from configured page memory (pPage,sz,n) at init |
| 4a17a0 | `sqlite3PagerClose` | high | Close pager: purge cache, write journal cleanup, close DB/journal files, free pager |
| 4a19a0 | `sqlite3PagerCommitPhaseOne` | high | Sync journal and flush dirty pages to DB during commit; handle incremental-vacuum truncation |
| 4a1ce0 | `sqlite3PagerMovepage` | high | Relocate a pager page to new pgno, updating dirty list, journaling and change-count flags |
| 4a1ea0 | `sqlite3PagerOpen` | high | Allocate & init a Pager (fixup filename, journal '-journal', wal '-wal', open DB file, set pagesize) |
| 4a24c0 | `pagerReadFileheader` | high | Zero dst then read up to param_2 bytes of DB header via xRead, mapping SHORT_READ(0x20a) to 0 |
| 4a26b0 | `sqlite3PagerSetBusyhandler` | high | Store busy-handler callback (+0x98/+0x9c) and forward to VFS via xFileControl (+0x28) |
| 4a27d0 | `sqlite3PagerSetPagesize` | high | Change pager page size: alloc temp space, compute nPage via alldiv, update cache & reserve bytes |
| 4a2980 | `pager_playback` | high | Roll back changes from hot journal: read super/header, replay pages, sync & end transaction |
| 4a2c20 | `sqlite3PagerUnrefNotNull` | high | Release one reference to a pager page (pcacheRelease + free BtShared if refless) |
| 4a2e90 | `sqlite3ParseUri` | high | Parse a file: URI into filename + vfs + query params, decoding %-escapes and options |
| 4a3620 | `pcacheSortDirtyList` | high | Merge-sort the pager dirty-page list (32-bucket radix merge) by page number for flushing |
| 4a37e0 | `sqlite3PcacheFetch` | high | Fetch/create a page slot in the page cache, recycling LRU when needed; return PgHdr in *param_4 |
| 4a39a0 | `pcacheManageDirtyList_add` | high | Add a page to the pager dirty list, maintaining head/tail/first-synced pointers |
| 4a39f0 | `sqlite3PcacheMove` | high | Rekey a cached page to new pgno via pcache xRekey, re-adding to dirty list if applicable |
| 4a3a80 | `sqlite3PcacheRelease` | high | Drop one page reference; when zero, either write sub-journal & recycle or return to clean LRU |
| 4a3b00 | `pcacheTruncate` | high | Discard cached pages with pgno>=param_2 (write sub-journal), zero page1 buffer, resize pcache |
| 4a5af0 | `sqlite3Prepare` | high | Compile SQL text into a prepared VDBE: check schema locks, run tokenizer/parser, finalize program |
| 4a5f90 | `sqlite3Put4byte` | high | Write a 4-byte big-endian unsigned int to buffer |
| 4a6140 | `sqlite3Realloc` | high | Reallocate memory via configured xRealloc with mem-stat accounting and soft-heap alarm |
| 4a65c0 | `sqlite3RegisterBuiltinFunctions` | high | Populate global function hash with built-in scalar/aggregate FuncDefs, then date/time & like |
| 4a7850 | `sqlite3SafetyCheckOk` | high | Validate db connection magic word, reporting misuse(0x15) on null/invalid pointer |
| 4a7960 | `sqlite3SchemaClear` | high | Reset a schema object: delete all Tables, Indices, Triggers, Views and collations, mark reset |
| 4a7a80 | `sqlite3SchemaGet` | high | Get or allocate (0x54) the shared Schema for a Btree, resetting its fields; set OOM on fail |
| 4a7be0 | `pcache1Free` | high | Free a page buffer: return to configured page-buffer pool or heap, updating slot/mem counters |
| 4a7d10 | `pcache1Alloc` | high | Allocate a page buffer from configured page-buffer pool free-list, else tracked heap |
| 4a9a30 | `sqlite3SetString` | high | Format string with sqlite3VXPrintf into StrAccum, free old *param_1 and store result |
| 4a9cb0 | `sqlite3SrcListDelete` | high | Free a SrcList: for each item free names/aliases, index, on/using exprs & subquery Select |
| 4aa580 | `sqlite3StatusUp` | high | Increment mem-status counter[param_1] by param_2 and update its high-water mark |
| 4aa5b0 | `sqlite3StatusSet` | high | Set mem-status counter[param_1]=param_2 and update its high-water mark |
| 4aa5e0 | `sqlite3Step` | high | Execute one step of a prepared statement (VdbeExec or Explain), profile timing, map errors |
| 4aa7b0 | `sqlite3StrAccumAppend` | high | Append text to a StrAccum, growing buffer (realloc/PageMalloc) or setting overflow/OOM flags |
| 4aa8f0 | `sqlite3StrAccumFinish` | high | NUL-terminate a StrAccum and, if using page buffer, copy result to a heap/db allocation |
| 4aa970 | `sqlite3StrAccumReset` | high | Reset a StrAccum, freeing its heap/db buffer if it differs from the static base |
| 4aa9b0 | `sqlite3Strlen30` | high | Return length of a C string masked to 30 bits (0 for null) |
| 4ad2f0 | `sqlite3VXPrintf_toAccum` | high | Format args into a temporary StrAccum via sqlite3VXPrintf, set OOM on connection if failed |
| 4ad370 | `sqlite3VXPrintf` | high | Core printf engine: parse conversions (%d/f/s/x/etc), width/precision/flags, append to StrAccum |
| 4ae630 | `sqlite3ValueNew` | high | Allocate and zero-init a Mem (0x28) value with type-null/encoding defaults |
| 4aec30 | `sqlite3VdbeChangeEncoding` | high | If Mem holds text (flag 2) with wrong encoding, translate it via sqlite3VdbeMemTranslate |
| 4aef00 | `sqlite3VdbeFreeCursorsAndProgram` | high | Free a VDBE program: op array (aOp), aColName, sub-programs, aVar, result columns, aMem |
| 4af2b0 | `sqlite3VdbeDeleteAuxData` | high | Free auxdata (sqlite3_set_auxdata) entries not preserved by mask, invoking each xDelete |
| 4b5e70 | `sqlite3VdbeDelete` | high | Finalize and unlink a VDBE from the connection's prepared-statement list, then free it |
| 4b67d0 | `sqlite3VdbeList` | high | Produce EXPLAIN / EXPLAIN QUERY PLAN result rows from a VDBE's op array |
| 4b6fa0 | `sqlite3VdbeMemExpandBlob` | high | Materialize a zero-padded blob (MEM_Zero flag 0x4000): grow buffer and memset the zero region |
| 4b7010 | `sqlite3VdbeMemFinalize` | high | Run an aggregate function's xFinalize into a Mem, then release the previous value |
| 4b7260 | `sqlite3VdbeMemGrow` | high | Ensure a Mem's dynamic buffer is >=param_2 bytes, preserving old content if requested |
| 4b7380 | `sqlite3VdbeMemHandleBom` | high | Strip a leading UTF BOM from a text Mem and set its encoding (UTF16LE/BE) accordingly |
| 4b7490 | `sqlite3VdbeMemMakeWriteable` | high | Make a Mem's buffer writable/owned: expand blob then copy to its own zMalloc, NUL-terminate |
| 4b7590 | `sqlite3VdbeMemNulTerminate` | high | Add a NUL terminator to a text Mem lacking one (grow buffer, set term flag 0x200) |
| 4b76e0 | `sqlite3VdbeMemRelease` | high | Release a Mem's external bindings (flag 0x2460) and free its dynamic buffer, null pointers |
| 4b7720 | `sqlite3VdbeMemReleaseExternal` | high | Free a Mem's external resource: frame(0x2000), destructor(0x400), rowset(0x20) or agg-ctx(0x40) |
| 4b78c0 | `sqlite3VdbeMemClearExternAndSetNull` | high | Clear a Mem's aggregate-context / rowset resource and reset it to type-null |
| 4b79e0 | `sqlite3VdbeMemSetStr` | high | Set a Mem to a text/blob value (copy, transfer-ownership, or static) with length/encoding |
| 4b7cf0 | `sqlite3VdbeMemStringify` | high | Convert a numeric Mem to its text representation ('%!.15g' for real), optional re-encoding |
| 4b7dc0 | `sqlite3VdbeMemTranslate` | high | Transcode a Mem's text between UTF-8 and UTF-16LE/BE, allocating a new buffer |
| 4b8640 | `sqlite3VdbeHalt` | high | Halt a VDBE: rollback/commit statement, propagate error string to db, set closed magic |
| 4b9420 | `sqlite3VdbeTransferError` | high | Move a VDBE's error code/message into the parent connection's error Mem |
| 4ba040 | `sqlite3KeyInfoUnref` | high | Decrement a KeyInfo refcount (+0xc); when zero run destructor (vtable+0x10) and free |
| 4ba4a0 | `sqlite3WalFrames` | high | Write a set of dirty pages as frames into the WAL, taking the write lock and checkpointing |
| 4ba620 | `sqlite3WalClose` | high | Checkpoint (if lockable) and close the WAL: run checkpoint, delete/limit wal file, free Wal |
| 4bac90 | `sqlite3WalOpen` | high | Allocate & init a Wal object (0x70 + pagesize), open the WAL file, read its shm/pagesize flags |
| 4bada0 | `walFindFrame` | high | Search the WAL hash tables for the newest frame of a given page, returning its frame offset |
| 4bc440 | `sqlite3_config` | high | Global config dispatch: set/get memory,mutex,pcache methods, page/scratch buffers, lookaside etc |
| 4bc920 | `sqlite3_initialize` | high | One-time library init: mutex, malloc, pcache subsystems and built-in functions, set inited flag |
| 4bd210 | `sqlite3StrHash_wal` | high | Compute a rolling hash over param_2 bytes (xor + *8) using the case-fold table |
| 4bd5d0 | `pager_incr_changecounter` | high | Increment DB change-counter on page1, write sync-flags/header magic, optionally to WAL |
| 4bfc30 | `vdbeUnbind` | high | Validate a prepared-statement bind index and release the target Mem parameter |
| 4bfd90 | `pcache1RemoveFromList` | high | Unlink a page-cache/pager object from the singly-linked global list at DAT_00583e70 |
| 4c0220 | `walBusyLock` | high | Acquire a WAL shm lock, invoking the busy-handler callback and retrying while it returns nonzero |
| 4c0270 | `walCheckpoint` | high | Copy frames from the WAL back into the DB file (checkpoint), advancing backfill counters |
| 4c05d0 | `walChecksumBytes` | high | Compute the two-word Fibonacci-weighted WAL checksum over a data block (native/byteswapped) |
| 4c0690 | `walCleanupHash` | high | Reset the WAL hash slots and page-number array for frames beyond the current mxFrame |
| 4c0740 | `walDecodeFrame` | high | Validate a WAL frame header (salt + checksums) and extract its page number & DB size |
| 4c0850 | `walEncodeFrame` | high | Build a WAL frame header: page number, DB size/commit, salts and cumulative checksums |
| 4c0910 | `walIndexAppend` | high | Insert a frame's page number into the appropriate wal-index hash table (linear probe) |
| 4c0a00 | `walIndexClose` | high | Free/unmap the wal-index (heap-mode) shared-memory pages or delegate to VFS xShmUnmap |
| 4c0ae0 | `walIndexPage` | high | Map or lazily allocate the requested wal-index shared-memory page (heap 0x8000 blocks) |
| 4c0c00 | `walIndexReadHdr` | high | Read & validate the wal-index header, recovering it under a write lock if inconsistent |
| 4c0d40 | `walIndexRecover` | high | Reconstruct the wal-index by scanning the WAL file frames and rebuilding hash tables |
| 4c10b0 | `walIndexTryHdr` | high | Copy the two wal-index header copies from shm and verify they match with checksum |
| 4c12b0 | `walIndexWriteHdr` | high | Write the current wal-index header (with checksum) into both shm header copies |
| 4c1390 | `walIteratorInit` | high | Build a WAL checkpoint iterator: merge-sort each index block's page list by frame order |
| 4c1520 | `walIteratorNext` | high | Return the next (pageNumber,frame) from a merge iterator across sorted index segments |
| 4c15c0 | `sqlite3WalLimitSize` | high | Truncate the WAL file down to a limit via xFileSize/xTruncate under I/O barriers |
| 4c1640 | `walMerge` | high | Merge two sorted frame-index runs (by page number, dedup) into an output list |
| 4c1720 | `walMergesort` | high | Recursively merge-sort a WAL index block's page-number list into ascending order |
| 4c1940 | `walRestartHdr` | high | Reset the WAL header for restart: bump change counter & salt via randomness, rewrite index hdr |
| 4c1ad0 | `walTryBeginRead` | high | Attempt to begin a WAL read transaction: pick a read-mark, lock it, validate header stability |
| 4c1da0 | `walUnlockShared` | high | Release a WAL shared read lock at slot param_2 via xShmLock |
| 4c1dd0 | `walWriteToLog` | high | Write data to the WAL/DB file, splitting the write at the mapping/size boundary with a sync |
| 4c5d90 | `std::vector::_Reserve` | high | Allocate storage for a std::vector of 24-byte elements, guarding overflow |
| 4c6540 | `std::pair::ctor2` | high | Construct a 2-field pair/struct from two source pointers (misattributed World) |
| 4c6560 | `std::pair::copy_ctor` | high | Copy a 2-word pair/struct (misattributed World) |
| 4c68e0 | `std::_Tree::_Rebalance_int` | high | Red-black tree insert fixup (recolor/rotate) after inserting an {int}-keyed node |
| 4c6af0 | `std::_Tree::_Rebalance_strkey` | high | Red-black insert fixup for a node whose payload is a std::string (frees string on length error) |
| 4c6d20 | `std::_Tree::_Rebalance_strkey2` | high | Red-black insert fixup for a string-keyed node variant (frees string buffer on overflow) |
| 4c6f50 | `std::_Tree::_Rebalance_strkey3` | high | Red-black insert fixup for another string-keyed node layout (frees on length error) |
| 4c7180 | `std::_Tree::_Rebalance_buynode` | high | Buynode via FUN_004d9b50 then red-black insert fixup for a keyed node |
| 4c7380 | `std::_Tree::_Insert_hint_int` | high | Insert with hint into an int-keyed map: check adjacency to hint, else lower_bound + rebalance |
| 4c7570 | `std::_Tree::_Insert_hint_pair` | high | Insert with hint into a {int,int}-keyed map using comparator, else fall back to positional insert |
| 4c77c0 | `std::_Tree::_Insert_hint_str` | high | Insert with hint into a string-keyed map (string compare via FUN_00419ef0), else nohint insert |
| 4c79b0 | `std::_Tree::_Insert_nohint_int` | high | Locate insertion point in an int-keyed tree (descend by key) and rebalance-insert the new node |
| 4c7ad0 | `std::_Tree::_Insert_nohint_pair` | high | Locate insertion point in a {int,int}-keyed tree and rebalance-insert, freeing node if duplicate |
| 4c7c50 | `std::_Tree::_Insert_nohint_str` | high | Locate insertion point in a string-keyed tree (FUN_00419ef0 compare) and rebalance-insert |
| 4c7de0 | `std::_Tree::_Insert_nohint_str2` | high | String-keyed tree insertion-point search and rebalance-insert (variant of 4c7c50) |
| 4c8130 | `std::pair::ctor_swap` | high | Construct a 2-field pair, taking first from param_2, second from param_3 |
| 4cde20 | `std::pair::copy_ctor2` | high | Copy a 2-word pair/struct from source (World) |
| 4cde60 | `std::map::operator[]_int` | high | Map operator[] for int key: find lower_bound; if absent insert default-valued node; return value slot |
| 4cdef0 | `std::map::insert_pair` | high | Insert a {int,int}->value entry into a map if key absent (lower_bound + hinted insert) |
| 4ce000 | `std::map::insert_str` | high | Insert a std::string-keyed entry into a map if key absent (buynode + positional insert) |
| 4ce0e0 | `std::map::insert_str2` | high | Insert a std::string-keyed entry (variant) into a map if key absent |
| 4ce350 | `std::pair_less` | high | Comparator: return true if this-pair < param_1-pair (lexicographic on {second,first}) |
| 4ce380 | `std::pair_lessequal` | high | Comparator: return true if this-pair <= param_1-pair (lexicographic) |
| 4ce3b0 | `std::pair_less_2` | high | Comparator on two {int,int} pointers: *p2 < *p1 lexicographically |
| 4ce5f0 | `std::_Tree::ctor_sentinel` | high | Allocate a red-black tree head/sentinel node (0x30), self-linking its three child pointers |
| 4ce720 | `std::_Rb_tree_destroy_recursive` | high | Recursively frees RB-tree map subtree; frees embedded string buffer (>7 uses heap) then node |
| 4ce780 | `std::_Rb_tree_rotate` | high | Red-black tree single rotation (rebalance) relinking parent/child/root pointers |
| 4d3e10 | `std::map::erase_range` | high | Erases [param_2,param_3) from a map/set; full-clear fast path resets sentinel |
| 4d3ed0 | `std::_Rb_tree_erase_node` | high | Removes one node from RB-tree map<...,string>, rebalances (recolor/rotate), frees node+string buffer |
| 4d4180 | `std::_Rb_tree_erase_node_variant` | high | RB-tree erase+rebalance for map with smaller value; frees node[4] buffer (cap at [9]); mirror of 4d3ed0 |
| 4d9de0 | `std::_Rb_tree_insert_rebalance_A` | high | RB-tree insert fixup (recolor/rotate) for map/set variant; frees new node buffer+throws on overflow |
| 4da010 | `std::_Rb_tree_insert_rebalance_B` | high | RB-tree insert fixup mirror (cap 0x9249247); allocs value via FUN_004d9ac0 then rebalances |
| 4da210 | `std::map::insert_hint` | high | Hinted insert into map<vector,...>: validates hint position via range-compare then rebalance or full insert |
| 4da4a0 | `std::map::insert_unique` | high | Locates insert position by walking tree with range comparisons, inserts or discards duplicate node |
| 4da790 | `std::map::insert_vectorKey` | high | Insert unique into map keyed by int-vector: walk with lexicographic compare then FUN_004da010 rebalance |
| 4da930 | `std::lexicographical_less` | high | Lexicographic less-than compare of two int ranges [p1,p2) vs [p3,p4); returns tri-state in low byte |
| 4da9c0 | `std::copy_ints` | high | Copies ints from [param_1,param_2) to param_3, guarding null dest |
| 4daca0 | `std::map::insertOrAssign` | high | Insert-or-update entry keyed by int-vector: find via lower_bound, if new build vector+node and insert (SEH) |
| 4dad80 | `std::_Rb_tree_increment` | high | In-order successor (iterator++) for RB-tree map/set node |
| 4dae20 | `std::vector<int>::reserve` | high | Allocates param_1*4 bytes for int vector, sets begin/end/cap; throws length/bad_alloc |
| 4daf50 | `std::map::lower_bound_vecKey` | high | Lower-bound search in map keyed by int-vector using lexicographic compare; returns node or header |
| 4f2be0 | `std::vector::push_back_int` | high | Appends an int to a vector, growing capacity if full; handles push of element aliasing own storage |
| 4f3e70 | `std::_Rb_tree_insert_rebalance_C` | high | RB-tree insert fixup (recolor/rotate) for map; frees node+throws on overflow (cap 0x7fffffd) |
| 4f7c20 | `std::_Rb_tree_destroy_recursive_B` | high | Recursively frees an RB-tree subtree (nodes only, no embedded buffer) |
| 4f7c60 | `std::map::lower_bound_2key` | high | Lower-bound in map keyed by 2 ints (node[4],node[5]); descends comparing (a,b) lexically |
| 4f8520 | `std::map::clear` | high | Clears a tree/list container: recursively frees children then resets header sentinel and size |
| 4fc060 | `std::map::erase_range_B` | high | Erases node range [param_2,param_3) from a map; full-clear fast path; per-node FUN_0040a1d0 erase |
| 530600 | `std::map::lower_bound_yx` | high | Lower-bound in map ordered by (y,x): descends tree comparing key[1] then key[0] |
| 54a6ce | `operator_new_wrapper` | high | Thin wrapper calling operator_new(param_1); discards result (allocation stub) |
| 54a946 | `_ftol2_round` | high | Converts x87 float10 in ST0 to rounded int64 (banker/half-up correction); MSVC ftol helper |
| 4025b0 | `RBNode_allocSetKey` | med | Allocates rb-tree node then stores vec3 key (3 dwords) at node+0x10 |
| 402b10 | `RBTree_findOrInsert` | med | Map find by vec3 key; returns existing value+0x18 or inserts new node and returns it |
| 407a30 | `RBTree_copyBeginThenInc` | med | Stores *this into param_1 then advances this via tree successor |
| 407ad0 | `List_allocSentinel0x34` | med | Allocates 0x34-byte list node as self-referential sentinel head; +0xc=0x101 |
| 407b00 | `List_allocSentinel0x20` | med | Allocates 0x20-byte list node as self-referential sentinel head; +0xc=0x101 |
| 407b30 | `List_allocSentinel0x18` | med | Allocates 0x18-byte list node as self-referential sentinel head; +0xc=0x101 |
| 407b60 | `List_allocNode0x134` | med | Allocates 0x134-byte list node; sets prev/next links (param_1/param_2 or self) |
| 407ba0 | `List_allocNode0x30` | med | Allocates 0x30-byte list node; sets prev/next links (param_1/param_2 or self) |
| 407be0 | `List_allocNode0x14` | med | Allocates 0x14-byte list node; sets prev/next links (param_1/param_2 or self) |
| 41a060 | `MapNode_allocSentinel40` | med | Allocates 0x28-byte RB-tree sentinel node, self-links 3 pointers, +0xc=0x101 |
| 41af30 | `RBTree_buyNode40` | med | Allocates 0x28 tree node and self-initializes its 3 link pointers from template |
| 420080 | `list_emplaceCopy40` | med | Inserts list node and copies 40-byte (5 qword) payload into node+8 |
| 4203c0 | `list_emplaceCopy24` | med | Inserts list node and copies 24-byte (3 qword) payload into node+8 |
| 4290d0 | `std_map_Speech_allocPairNode` | med | Allocates 0x40 map node (via 42cf80) and default-constructs two std::strings (+0x10,+0x28) copying key/value; std::map node, not game_misc |
| 4291a0 | `std_list_Speech_makeStrNode` | med | Allocates list node (via 4f7b60) and inits one std::string at node+8; std::list<string> node builder |
| 429240 | `std_map_allocNode_intKeyStr` | med | Allocates 0x2c map node (42cf00); sets int key at +0x10 and constructs std::string at +0x14; std::map node ctor |
| 429280 | `std_map_Speech_allocEntryNode` | med | Allocates 0x38 map node (42cf40); copies string key (+4) and two sub-containers via 42b040/42b180; Speech map entry node |
| 429340 | `std_map_allocNode_str2` | med | Allocates 0x40 map node (42cf80) and copies two std::strings (+0x10,+0x28) via 416a90; std::map<string,string> node |
| 429430 | `std_map_copyAssign` | med | Clones a whole RB-tree into this (recursive 4294b0) then fixes leftmost/rightmost header links; std::map copy |
| 42b040 | `std_list_copyCtor` | med | Builds empty std::list header (41a030) then copies elements via 429430; std::list copy-ctor |
| 42b180 | `std_list_copyCtor_strList` | med | Builds std::list<string> (4f7b60 head) and appends copies via 42ada0; std::list copy-ctor |
| 42c9a0 | `std_map_insert_strToStr` | med | Inserts string->string pair into map: builds node (429340) and inserts via 42a450; std::map<string,string> |
| 42cad0 | `std_map_insert_strToStr_v2` | med | Same string->string map insert (429340/42a450) with key built via 4172f0; std::map |
| 42d300 | `std_strstreambuf_init` | med | Initializes a memory stream buffer: allocs 2*n bytes, memcpy, sets get/put area pointers by mode flags; STL strstream |
| 464130 | `sqlite3_overloadFunction` | med | Creates/overrides a SQL function stub (findFunction 4995c0 else createFunction 493f20); SQLite; 'MATCH' caller |
| 4666d0 | `sqlite3_snprintf_guarded` | med | Reentrancy-guarded printf-to-buffer (4bc920 check then 466700); SQLite public snprintf-style entry |
| 466700 | `sqlite3_vxprintf_toBuf` | med | Formats into a fixed 72-byte StrAccum buffer via 4ad370/4aa8f0; SQLite vsnprintf implementation |
| 466a80 | `sqlite3_snprintf_impl` | med | StrAccum-based snprintf into buffer with size param_1 (4ad370 format, 4aa8f0 finalize); SQLite |
| 46b780 | `pager_setInAllSavepoints` | med | For each savepoint bitvec sets the given page bit (bitvec 48ea60); SQLite pager savepoint set |
| 46bae0 | `btree_moveToNext` | med | Advances/moves a btree cursor to next cell or child page, allocating pages; SQLite; 'database corruption' |
| 46e390 | `btree_writeOverflow` | med | Writes payload across overflow pages using 64-bit page math (allmul/alldvrm); SQLite fillInCell overflow write |
| 4757a0 | `sqlite3_txnActive` | med | Returns 1 if db has active write txn or any btree in-trans backend; SQLite connection-busy check |
| 47fc00 | `btree_readPage1` | med | Locks and reads database page 1 header, validates 'SQLite format 3' magic, sets page/reserve sizes; SQLite lockBtree |
| 480840 | `btree_putCellPtr` | med | Writes a 4-byte value into a page cell's pointer field, searching cells by matching old value; SQLite; 'database corruption' |
| 4834d0 | `sqlite3_openDatabase` | med | Opens/initializes a DB connection: allocs sqlite3, registers BINARY/NOCASE/RTRIM collations, opens backend, MATCH func; SQLite openDatabase; misattributed Speech |
| 483e60 | `pager_playbackSavepoint` | med | Plays back journal/savepoint pages or full journal to restore state (484f60 per-page); SQLite pagerPlaybackSavepoint |
| 484120 | `pager_playbackAllPages` | med | Applies pager_playbackOnePage(4842a0) to every in-journal/dirty page (4baf40 iterate); SQLite |
| 4842a0 | `pager_playbackOnePage` | med | Reads a page record from savepoint bitvec and writes it back to DB; SQLite pager_playback_one_page; marks cursors |
| 484410 | `pager_writeDirtyList` | med | Writes a list of dirty pages to disk (4ba7d0), notifies cursors (48e040); SQLite pager_write_pagelist |
| 484760 | `pager_endTransaction` | med | Finalizes/closes journal, releases savepoints, unlocks or resets to read state; SQLite pager_end_transaction |
| 484960 | `pager_incrChangeCounter` | med | Increments file change counter on page1, syncing/writing via 4876e0; SQLite pager_incr_changecounter |
| 484b10 | `pager_openJournal` | med | Begins write transaction: allocates in-journal bitvec (0x200), opens journal file, writes header; SQLite pager_open_journal |
| 484c20 | `pager_playback` | med | Full journal playback loop: reads super-journal name, page records, checksums, replays each; SQLite pager_playback |
| 484f60 | `pager_playbackOnePageJournal` | med | Reads one page record (pgno+data+cksum) from journal and writes it to DB/page cache; SQLite pager_playback_one_page |
| 485280 | `pager_truncateImage` | med | Truncates DB image to param_2 pages via VFS xTruncate/zero-fill; SQLite pager_truncate |
| 485520 | `pager_writePage` | med | Writes a page to journal then marks dirty/writes to DB, updates savepoint bitvecs; SQLite pager_write |
| 485750 | `pager_commitPhaseOne` | med | Opens/writes journal and flushes all dirty pages, syncing before commit; SQLite commit phase one |
| 488380 | `btree_updateOverflowCell` | med | Rewrites a cell's overflow chain/ptrmap and copies payload for balance; SQLite balance helper |
| 4885a0 | `sqlite3_logCallback` | med | Formats a message into 212-byte StrAccum and invokes the log hook (DAT_00582bac); SQLite; misattributed Speech |
| 489d30 | `vdbe_commitAllBtrees` | med | Iterates db backends: parses page1 (47fc00), commits/updates change counters, sets SCHEMA retry; SQLite vdbeCommit |
| 48f070 | `btree_closeConnection` | med | Closes a Btree connection: finalizes cursors, unlinks from shared list, frees schema/pager; SQLite sqlite3BtreeClose |
| 48f2f0 | `btree_rollback` | med | Rolls back a btree transaction: reverts page cache (46e160) or aborts (4a19a0); SQLite sqlite3BtreeRollback |
| 4919c0 | `btreeCheckReadConflicts` | med | Under btree mutex, scan cursors/locks (iVar1+0x48/0x4c/0x16) and return SQLITE_LOCKED(0x106) on conflict |
| 492650 | `pcacheCleanupCursorSpace` | med | Free per-cursor overflow/aOverflow allocations, adjusting pcache memory counters or free list |
| 492710 | `pcacheClearOverflowList` | med | Walk cursor overflow-cell list at +0x1d8, returning each buffer to page free-list or heap |
| 4934c0 | `pcacheCompactPageArray` | med | Compact a Btree cursor/page array (+0x10,count +0x14): drop refcount-0 entries, inline-store when <3 |
| 499500 | `sqlite3FindDbFunction` | med | Locate function/column struct: use table lookup (FUN_004799f0) then index by param_2*5 slot |
| 49ab00 | `sqlite3DeleteTableAux` | med | Delete Table auxiliaries: unhash columns, free trigger-step-like nodes ([7]/[8]) exprs and select subtrees |
| 4a0440 | `pcache1Initialize` | med | Init memory subsystem: default methods if unset, set up page-cache buffer and scratch from config |
| 4a0cd0 | `sqlite3MutexInit` | med | Lazily select mutex method table (threaded vs noop) then tail-call its xMutexInit |
| 4a1370 | `sqlite3OsShmMap_or_v10` | med | Invoke OS/vtable method at offset +0x10 with two args |
| 4a1bb0 | `pager_playback_or_reset` | med | On error state, reset/playback pager: set state; on I/O error latch code and mark error(6) |
| 4a2440 | `pager_write_dirty_or_openWal` | med | If writable & no savepoint: close read fd and open write-mode/WAL, set pager state 5 |
| 4a2510 | `sqlite3PagerCommitPhaseTwo_or_sync` | med | Finalize pager: commit/sync per state, on I/O error latch code and set error state 6 |
| 4a25c0 | `sqlite3PagerReleaseSavepoints` | med | Release/rollback pager savepoints down to param_3, freeing bitvecs and syncing sub-journal |
| 4a2bd0 | `pagerSyncHotJournal` | med | Sync journal file via VFS (xSync at +0xb or xFileControl+0x28), mapping NOTFOUND(0xc)->0 |
| 4a2c80 | `pagerPlaybackSavepoint` | med | Replay/reload pages over a savepoint range, reacquiring/reinitializing each affected page |
| 4a35c0 | `pagerReleaseAllSavepoints_flush` | med | Flush pages holding savepoint bit 2: write to sub-journal, clear dirty, notify pcache |
| 4a37a0 | `pcacheRelease_writeSubj` | med | Release a page that is in savepoint state: write sub-journal then decrement pin and recycle |
| 4a3950 | `pcacheMakeClean` | med | Clear dirty flag on a page: write sub-journal, remove from dirty list, notify pcache backend |
| 4a6e20 | `sqlite3ExprListClearList` | med | Free a null-terminated list of pager-managed allocations (head *param_1), reset owner header |
| 4a9650 | `sqlite3WindowListDelete_or_Cte` | med | If non-null, walk/free a substructure (FUN_00472d10) then free the node itself |
| 4aac10 | `sqlite3VdbeFrameRestore` | med | Restore VDBE Mem-cell array from a saved frame: release externals, copy back saved cells |
| 4ae2b0 | `sqlite3VdbeMemRelease_free` | med | Release a Mem's external resources (flag 0x2460) and its dynamic buffer, then free the Mem |
| 4ae680 | `sqlite3ValueApplyAffinity` | med | Coerce a Mem value to target affinity/encoding (numeric, text, blob-to-text) as needed |
| 4b8c50 | `sqlite3VdbeResizeMemArray` | med | Free old and allocate param_2 fresh Mem cells (0x50 each), init each to type-null |
| 4b9b30 | `sqlite3AggInfoDelete_or_columns` | med | Free a table auxiliary array at +0x34 (skip index1) then the array itself |
| 4ba070 | `sqlite3VtabUnlockList` | med | Expire prepared statements then walk & unref the connection's deferred VTable list (+0x13c) |
| 4ba0e0 | `walTryBeginRead` | med | Retry loop to establish a WAL read transaction, reading wal-index header and picking a read-mark |
| 4ba770 | `walIteratorFree_or_restart` | med | Release WAL read/write locks held by a checkpoint/writer and reset lock state |
| 4ba7d0 | `walWriteFrames_inner` | med | Encode and write successive WAL frames (header+page) to the log file, updating checksums/salts |
| 4baf40 | `sqlite3WalUndo_or_iterate` | med | Iterate WAL frames from a saved point invoking a callback per page, then cleanup hash on rollback |
| 4bcbc0 | `pcache1_init_systeminfo` | med | Query system info (GetSystemInfo) for page granularity and register a pcache/pager cleanup entry |
| 4bce20 | `sqlite3WithDelete_or_AggFree` | med | Free a linked structure at param_2+4 (6-word items): delete Expr, free 3 sub-buffers, then array |
| 4c01d0 | `sqlite3VtabMoveToList` | med | Move VTable nodes matching db==param_1 to output; push others back onto their db's disconnect list |
| 4c29f0 | `pagerWriteWalHeader` | med | Rewrite pager WAL/journal header: recompute page sizes, salts (randomness) & checksums, write out |
| 4c2c10 | `walWriteWalFrames_journal` | med | Write a super-journal/WAL header record (name + sizes + checksum) via file writes |
| 4c5c10 | `std::vector::_Ucopy` | med | Copy a range of 24-byte (6-word) elements to a destination buffer (misattributed WalkPathBehavior) |
| 4c5c60 | `std::vector::copy_ctor` | med | Copy-construct a std::vector of 24-byte structs: reserve then uninitialized-copy source range |
| 4c67a0 | `std::_Tree::_Buynode_int2` | med | Allocate a red-black tree node and copy a {int,int}+String key into it |
| 4c67e0 | `std::_Tree::_Buynode_str` | med | Allocate a map node and construct its std::string key + trailing value |
| 4c6820 | `std::_Tree::_Buynode_str2` | med | Allocate a map node and construct its std::string key + two trailing values |
| 4c6860 | `std::vector_of_vector::dtor` | med | Destroy a range of objects each owning a vector<struct12>, freeing nested & outer storage (Zone) |
| 4ce620 | `std::_List_node_alloc_0x48` | med | Allocates+links a 0x48-byte list/tree sentinel node via operator_new; throws bad_alloc; class=Zone likely misattributed STL |
| 4ce660 | `std::_List_node_alloc_0xc` | med | Allocates+links a 0xc-byte list node (operator_new) with prev/next self-link; shared STL list-node ctor |
| 4ce6a0 | `std::_Tree_node_alloc_0x30` | med | Allocates 0x30-byte RB-tree node, copies *param_1 into [0..2] (left/parent/right); bad_alloc on fail |
| 4d9ac0 | `std::_Tree_node_construct_seh` | med | Allocates tree node (FUN_004f7ba0), zeroes color/flag, in-place copy-constructs vector at node+4 (SEH guarded) |
| 4d9b70 | `std::list::insertNode3` | med | Inserts list node (FUN_00407be0) and writes 3-int payload (xyz) at node+8..+0x10 |
| 4d9bb0 | `std::_Tree_node_move_construct` | med | Allocates tree node (FUN_004daed0), zeroes color, move-constructs 9-field value at node+4 via FUN_004d9960 |
| 4da680 | `std::map::insert_scalarKey` | med | Lower-bound walk on tree keyed by single uint (offset+4), inserts unique or returns existing |
| 4daa80 | `std::vector<int>::copyConstruct` | med | Copy-constructs an int vector from source [*param_1,param_1[1]); reserves then copies (SEH) |
| 4dae90 | `std::_Tree_node_alloc_0x14` | med | Allocates 0x14-byte tree/list node, inits [0..2] from *param_1 sentinel; bad_alloc on fail |
| 4daed0 | `std::_Tree_node_alloc_0x34` | med | Allocates 0x34-byte tree node, inits [0..2]=sentinel; bad_alloc on fail |
| 4f7b60 | `std::_List_node_alloc_0x20` | med | Allocates 0x20-byte list node, self-links prev/next when null; bad_alloc on fail |
| 4f7ba0 | `std::_Tree_node_alloc_0x1c` | med | Allocates 0x1c-byte tree node, inits [0..2]=sentinel; bad_alloc |
| 4f7be0 | `std::_Tree_node_alloc_0x20b` | med | Allocates 0x20-byte tree node, inits [0..2]=sentinel; bad_alloc |
| 52df80 | `std::_Tree_node_alloc_assign2` | med | Allocates World tree node (FUN_0052ed60), zeroes color, stores 2-int key at node+4/+5 |
| 52dfb0 | `std::list::insertNode1` | med | Inserts list node (FUN_004ce660) and stores single value at node+8 |
| 52ed30 | `std::_List_init_sentinel` | med | Allocates 0x14-byte list sentinel, self-links [0..2], sets [0xc]=0x101 (nil/color init) |
| 52ed60 | `std::_Tree_node_alloc_0x18` | med | Allocates 0x18-byte tree node, inits [0..2]=sentinel; bad_alloc |
| 54ada6 | `eh_vector_ctor_iter_unwind` | med | Compiler EH thunk: on exception calls __ArrayUnwind for array element constructor iterator |
| 54ae15 | `eh_vector_dtor_iter_unwind` | med | Compiler EH thunk: on exception calls __ArrayUnwind for array element destructor iterator |
| 4025f0 | `RBTree_insertNode` | low | Red-black tree insert-with-hint; positions node relative to hint param_2 then rebalances |
| 402840 | `RBTree_insertRebalance` | low | RB tree insert lower_bound search + rebalance; returns node and inserted flag |
| 46e160 | `btree_balanceCleanup` | low | Frees overflow, relocates trailing cells (via 47e2e0 insert), updates page count; SQLite btree balance/incrvacuum; 'database corruption' |
| 476ff0 | `vdbe_runVtabCommit` | low | Iterates db backends invoking a per-backend commit/virtual-table callback (+0xc0); SQLite commit phase |
| 47df00 | `pager_hasHotJournal` | low | Queries file existence/size via VFS xAccess/xLock/xShmLock to detect a hot journal; SQLite hasHotJournal |
| 47e2e0 | `btree_clearDbPage` | low | Recursively clears/frees a btree page and its child cells (46bae0 walk, 480840 update); SQLite clearDatabasePage; 'database corruption' |
| 483b10 | `vdbe_initPseudoCursor` | low | Initializes a pseudo/ephemeral cursor default state or xShmMap (+0x18); SQLite VdbeCursor setup |
| 483bd0 | `pager_walCheckpointCheck` | low | Checks/updates WAL frame availability (4ba0e0), marks cursors stale on change; SQLite |
| 483d40 | `pager_endTransactionCheck` | low | Ends/downgrades transaction: checks file size via VFS then unlock/truncate; SQLite pager_end_transaction |
| 484530 | `pager_deleteMasterJournal` | low | Reads super/master-journal, opens each child journal, deletes master if all children obsolete; SQLite pager_delmaster |
| 489c10 | `btree_saveCursorPages` | low | Reads current page (46b2f0), caches, then releases all cursor pages resetting cell cache; SQLite btree cursor save/clear |
| 48e040 | `btree_writeOverflowCursors` | low | For each affected cursor, writes overflow payload for a page (46e390); SQLite incremental-vacuum cursor update |
| 4a3a60 | `pagerFileSync` | low | If VFS present, tail-call a file-control/sync method (jumptable via DAT_00582b44) |
| 4bd250 | `walDirtyPagesPresent_or_bitTest` | low | Test whether required pages exist in a page-map/bitvec structure, returning 1 if missing |
| 4c5a60 | `pagerWalSyncTruncate` | low | Finalize WAL/journal: write header, sync and truncate/zero the file per commit mode |
| 4d4f90 | `WalkPathBehavior::checkPathClear` | low | Samples random AABB volume against voxel terrain to test walkability/collision along a box region |

## crtstl (377)

| addr | proposed name | conf | purpose |
|---|---|---|---|
| 401420 | `fixedpoint16_to_float` | high | Convert 16.16 fixed-point int64 to float (*1/65536) |
| 401450 | `vec3_sub` | high | Vec3 subtract: param_1 = this - param_2 |
| 401490 | `int64_sub` | high | 64-bit two-limb subtract with borrow |
| 4014f0 | `vec3_add` | high | Vec3 add: param_1 = this + param_2 |
| 401570 | `vec2_dot` | high | Vec2 dot product (x*x + y*y) |
| 4015a0 | `vec3_dot` | high | Vec3 dot product |
| 4015e0 | `vec2_scale` | high | Scale vec2 in place by scalar |
| 401610 | `vec3_scale` | high | Scale vec3 in place by scalar |
| 401650 | `vec3_add_inplace` | high | Vec3 add-assign: this += param_1 |
| 401840 | `std_string_grow` | high | std::basic_string reserve/reallocate (SSO aware) |
| 4018f0 | `std_allocate` | high | operator new wrapper, throws bad_alloc on failure |
| 401ca0 | `std_fabsf` | high | Absolute value of float |
| 401d40 | `vec2_length` | high | Vec2 length = sqrt(x^2+y^2) |
| 401d80 | `vec3_length` | high | Vec3 length = sqrt(x^2+y^2+z^2) |
| 401f50 | `vec2_normalize` | high | Normalize vec2 in place |
| 401fb0 | `vec3_normalize` | high | Normalize vec3 in place |
| 402180 | `vec2_length_sq` | high | Vec2 squared length |
| 4021b0 | `vec3_length_sq` | high | Vec3 squared length |
| 4021f0 | `mat4_transform_point` | high | Transform point by 4x4 matrix with perspective divide |
| 4022e0 | `mat4_translate_vec` | high | Accumulate translation of vec3 into matrix col 0x30 |
| 4023b0 | `mat4_translate` | high | Translate matrix by 3 scalar components |
| 402480 | `std_asinf` | high | arcsine of float |
| 4024a0 | `std_cosf` | high | cosine of float |
| 4024c0 | `std_sinf` | high | sine of float |
| 4024e0 | `std_sqrtf` | high | square root of float |
| 402990 | `vec3_store` | high | Store 3 dwords into object (vec3 init) |
| 402d80 | `Int64_lessThan` | high | Signed 64-bit less-than compare of two int64 (hi param[1], lo param[0]); returns bool |
| 402e30 | `int64x3_add` | high | Add three int64 lanes (6-dword accumulate) |
| 402e60 | `int64_add` | high | 64-bit add with carry |
| 402e80 | `int64x3_sub` | high | Subtract three int64 lanes |
| 402eb0 | `int64_sub2` | high | 64-bit subtract with borrow |
| 405420 | `std_map_find_value` | high | std::map lower_bound lookup, return mapped value or 0 |
| 405510 | `fixedpoint_to_int_floor` | high | 16.16 fixed-point to int with floor (via __alldiv) |
| 4055a0 | `std_powf` | high | power function on float (calls libm pow) |
| 406350 | `free_string_buffer` | high | Free a single {ptr,size,cap} string element |
| 4063b0 | `std_list_construct` | high | Construct empty std::list (allocate sentinel node) |
| 4079f0 | `vec3_scale_to` | high | Scale vec3 by scalar into output param_1 |
| 411040 | `std_list_push_back` | high | std::list push_back node ("list<T> too long") |
| 412670 | `vec3_normalize_to` | high | Normalize vec3 into output param_1 |
| 4129d0 | `std_vector_assign` | high | std::vector assign/copy-into with reallocation |
| 412b00 | `std_vector_allocate` | high | Allocate std::vector storage of given byte size |
| 412c70 | `zlib_compress_to_vector` | high | Compress vector into byte vector via zlib compress() |
| 412d00 | `zlib_compress_buffer` | high | Compute bound, zlib compress(), resize output |
| 412d90 | `zlib_uncompress_to_vector` | high | Decompress vector via zlib inflate wrapper |
| 412e20 | `zlib_inflate_stream` | high | Streamed zlib inflate loop (inflateInit_ "1.2.3"/inflate/inflateEnd) |
| 413200 | `std_vector_size` | high | Return byte size (end-begin) of vector |
| 413210 | `db_store_blob_wrapper` | high | Prepare buffer view and call blob upsert |
| 413240 | `db_upsert_blob` | high | SQLite blob upsert: SELECT/UPDATE/INSERT into blobs(key,value) |
| 413640 | `std_thread_start` | high | Spawn thread via _beginthread with copied functor |
| 4137f0 | `vector_calc_growth_0x118` | high | Compute new capacity for vector of 0x118-byte elems |
| 413840 | `std_vector_reallocate_0x118` | high | Reallocate vector of 0x118-byte elems, move-copy |
| 413940 | `std_vector_reserve_0x118` | high | Reserve vector of 0x118-byte elems ("vector<T> too long") |
| 4149e0 | `net_encode_field_u8` | high | Delta-encode 1-byte field into change list, set dirty bitmask |
| 414a80 | `net_encode_field_u16` | high | Delta-encode 2-byte field into change list + bitmask |
| 414b20 | `net_encode_field_u32` | high | Delta-encode 4-byte int field into change list + bitmask |
| 414bc0 | `net_encode_field_f32` | high | Delta-encode float field into change list + bitmask |
| 414c60 | `net_encode_field_vec5` | high | Delta-encode 0x14-byte (5-float) field + bitmask |
| 414d40 | `net_encode_field_struct0xac` | high | Delta-encode 0xac-byte struct if changed + bitmask |
| 414de0 | `net_encode_field_creature` | high | Delta-encode 0xe38-byte creature struct if changed + bitmask |
| 414e80 | `net_encode_field_item0x118` | high | Delta-encode 0x118-byte item struct if changed + bitmask |
| 414f20 | `net_encode_field_int3` | high | Delta-encode 0xc-byte (3-int) field + bitmask |
| 414fd0 | `net_encode_field_f32x3` | high | Delta-encode 3-float field + bitmask |
| 415090 | `net_encode_field_2int_0x18` | high | Delta-encode 0x18-byte (2-int pair) field + bitmask |
| 415150 | `net_encode_field_int2` | high | Delta-encode 8-byte (2-int) field + bitmask |
| 4151f0 | `net_decode_field_u8` | high | Decode 1-byte field from stream if dirty bit set |
| 415260 | `net_decode_field_u16` | high | Decode 2-byte field from stream if dirty bit set |
| 4152d0 | `net_decode_field_u32` | high | Decode 4-byte field from stream if dirty bit set |
| 415340 | `net_decode_field_vec5` | high | Decode 0x14-byte (5-float) field if dirty bit set |
| 4153d0 | `net_decode_field_struct0xac` | high | Decode 0xac-byte struct if dirty bit set (memcpy) |
| 415450 | `net_decode_field_creature` | high | Decode 0xe38-byte creature struct if dirty bit set |
| 4154d0 | `net_decode_field_item0x118` | high | Decode 0x118-byte item struct if dirty bit set |
| 415550 | `net_decode_field_int3` | high | Decode 0xc-byte (3-int) field if dirty bit set |
| 4155d0 | `net_decode_field_struct0x18` | high | Decode 0x18-byte struct if dirty bit set |
| 415660 | `net_decode_field_int2` | high | Decode 8-byte (2-int) field if dirty bit set |
| 415b20 | `net_encode_field_string` | high | Delta-encode C-string field (strcmp) into list + bitmask |
| 415be0 | `net_encode_field_struct0x2c` | high | Delta-encode 0x2c-byte (11-int) struct if changed + bitmask |
| 415cd0 | `net_decode_field_struct0x10` | high | Decode 0x10-byte struct if dirty bit set |
| 415d50 | `net_decode_field_struct0x2c` | high | Decode 0x2c-byte struct if dirty bit set (memcpy) |
| 4168f0 | `WriteBuffer::appendRaw` | high | Grows serialize buffer then memcpy raw bytes, advances write cursor at +0xc |
| 416c00 | `std::wstring::operator[]` | high | Returns &buf[i] for wstring honoring SSO/heap (cap>7), i*2 stride |
| 416cb0 | `std::string::_Chassign` | high | Fill count chars with value at pos in std::string (SSO/heap deref + memset) |
| 416d00 | `CharTraits_assignFill` | high | Fills param_2 UTF-16 chars = param_3 at offset param_1*2; follows SSO indirection when capacity>7 (traits::assign fill) |
| 416ec0 | `std::wstring::_Allocate` | high | Allocate wchar_t buffer of n elements (n*2 bytes), _Xbad_alloc on failure |
| 4170c0 | `std::string::append(count,char)` | high | Append n copies of char to std::string, _Xlength_error, _Grow + _Chassign |
| 419f80 | `std::string::empty` | high | Return true if length field (+0x10) is zero |
| 41caf0 | `std::list::push_back` | high | Append node to std::list (make node via _Buynode), list-too-long guard |
| 41cb40 | `std::vector<T0x188>::size` | high | Return element count (end-begin)/0x188 |
| 41eab0 | `std::char_traits::compare` | high | Lexicographic byte compare of two buffers length n (memcmp), returns -1/0/1 |
| 41fff0 | `std::vector<int>::size` | high | Return element count (end-begin)>>2 |
| 420020 | `std::vector<T0xc>::size` | high | Return element count (end-begin)/0xc |
| 420600 | `std::map::_Insert(rebalance)` | high | Insert node into red-black tree with recoloring/rotations, map-too-long guard |
| 420810 | `std::map::insert(hint)` | high | Hint-based unique insert: check neighbors else lower_bound then _Insert |
| 420a60 | `std::map::_Insert_unique` | high | Lower-bound walk then insert-or-return-existing for unique key map |
| 421e50 | `std::wstring::basic_string(count,wch)` | high | Construct wstring of n repeated wchars: init SSO then _Chassign(_427fd0) |
| 423ce0 | `std::map<int,Entity>::insert` | high | Find lower-bound then insert Entity(0x1180) value into map (stack temp build) |
| 426b20 | `scalar_deleting_destructor` | high | Virtual dtor thunk: call vfunc+0x14 then operator delete if flag set |
| 426b80 | `std::_Tree::equal_range` | high | Red-black lower/upper bound walk for key, returns bound pair |
| 426f60 | `std::list::_Tidy(no_size)` | high | Destroy all list nodes without resetting size field |
| 426fa0 | `std::list::erase` | high | Unlink single list node from neighbors, free it, decrement size |
| 426fd0 | `std::list::erase(embedded_list)` | high | Unlink node then destroy its embedded list (_00426c20), decrement size |
| 427fd0 | `std::basic_string<wchar_t>::resize` | high | Resizes wide-string buffer, throws length_error when too long |
| 428360 | `std::list<T>::push_back` | high | Appends node before end sentinel; throws list-too-long at max_size |
| 4283b0 | `std::list<T>::push_back` | high | Appends list node (max_size 0x6666665) |
| 428400 | `std::list<T>::push_back` | high | Appends list node (max_size 0x3333332) |
| 428450 | `std::list<T>::push_back` | high | Appends list node (max_size 0xaaaaaa9) |
| 4284a0 | `std::list<T>::push_back` | high | Appends list node (max_size 0x3fffffe) |
| 4284f0 | `std::list<T>::push_back` | high | Appends list node (max_size 0x2aaaaa9) |
| 428540 | `std::list<T>::push_back` | high | Appends list node (max_size 0x3333332) |
| 428590 | `std::list<T>::push_back` | high | Appends list node (max_size 0x7fffffe) |
| 4285e0 | `std::list<T>::push_back` | high | Appends list node (max_size 0xffffffe) |
| 4286b0 | `ws2_32_send_all` | high | Loops send() until all bytes are transmitted (ws2_32 Ordinal_16) |
| 42d060 | `node_free_twoStrings` | high | Frees a node holding two std::strings (+0x28 and +0x10) then frees node; std::map node deleter |
| 42d0c0 | `QuestText_node_free` | high | Destroys QuestText payload at node+0x28 (ctor_3) and frees string(+0x10) then node; std::map QuestText node deleter |
| 42e9a0 | `std::use_facet<codecvt>` | high | Fetches locale codecvt facet, throws bad_cast if missing |
| 42f070 | `std::basic_filebuf<char>::_Endwrite` | high | Flushes codecvt unshift sequence via fwrite when closing filebuf |
| 42f890 | `std::basic_filebuf<char>::open` | high | Opens file via _Fiopen and sets up codecvt for the filebuf |
| 431020 | `std::map<int,T>::operator[]` | high | Finds key or inserts default node, returns mapped-value ref |
| 469150 | `sqlite3_bind_blob` | high | bind BLOB to parameter (bindText enc0) |
| 4fae90 | `World_rockGroundBaseColor` | high | Rock/ground base color helper (matches cw_color.rock_base) |
| 518630 | `World_buildVoxelColumn` | high | Voxel column builder: terrain skin + water/rivers + feature/decoration passes |
| 523d80 | `World_landMask` | high | Ridged land base gated by smoothstep(gate)*smoothstep(water_depth) + per-feature deforms |
| 401020 | `copy_3_bytes` | med | Copy 3 bytes (e.g. RGB color triple) into object |
| 401040 | `set_3_bytes` | med | Set 3 explicit byte fields (color/triple init) |
| 4010b0 | `store_4_dwords` | med | Store 4 dwords (16-byte vector/quaternion init) |
| 401370 | `copy_4_bytes` | med | Copy 3 bytes + 1 trailing byte (4-byte struct init) |
| 4013e0 | `ptr_add_offset` | med | Return this+offset (pointer arithmetic helper) |
| 4013f0 | `std_vector_int_at` | med | Bounds-checked std::vector<int>::at (returns elem or 0) |
| 4014b0 | `int64_sub_timecall` | med | Subtract 64-bit result of time/counter call from this |
| 401530 | `int64_add_timecall` | med | Add 64-bit counter-call result to this int64 |
| 4016c0 | `call_ptr_n_times` | med | Invoke function pointer param_3+1 times in loop |
| 402030 | `matrix_rotate_columns` | med | Rotate matrix columns by degrees using cos/sin |
| 402150 | `get_field_0x44` | med | Return dword field at +0x44 |
| 402160 | `get_field_0x48` | med | Return dword field at +0x48 |
| 402170 | `get_field_0x4c` | med | Return dword field at +0x4c |
| 402a10 | `int64_assign_timecall` | med | Assign 64-bit counter-call result to *param_1 |
| 402bb0 | `ptr_index_dword` | med | Return base + index*4 (vector element pointer) |
| 402c10 | `iterator_advance_0x11c` | med | Post-advance iterator by stride 0x11c |
| 402c30 | `iterator_advance_0xc` | med | Post-advance iterator by stride 0xc |
| 402d10 | `fixedpoint_greater` | med | Compare packed fixed-point value, greater-than test |
| 402d40 | `fixedpoint_greater_call` | med | Compare fixed-point vs counter-call result |
| 405570 | `set_flag_bits_0x114` | med | Set or clear flag bits in ushort field at +0x114 |
| 405610 | `copy_4_bytes_b` | med | Copy 4 bytes into object |
| 405660 | `int64_sub_shifted` | med | Subtract (param<<16) as int64 from this |
| 405690 | `int64_add_shifted` | med | Add (param<<16) as int64 to this |
| 405750 | `fixedpoint_less` | med | Fixed-point less-than comparison |
| 4061d0 | `get_field_0x10` | med | Return dword field at +0x10 |
| 4061e0 | `get_bit6_of_byte3` | med | Read bit 6 of byte at +3 (flag accessor) |
| 4061f0 | `check_type_low5_active` | med | True if (byte+3 & 0x1f) not in {0,2} |
| 406250 | `get_field_0x1c` | med | Return dword field at +0x1c |
| 406280 | `get_low5bits_byte3` | med | Return byte at +3 masked with 0x1f (type field) |
| 406380 | `store_6_dwords` | med | Store 6 dwords into object (mat2x3/struct init) |
| 4063d0 | `init_struct_fields_a` | med | Zero-init several object fields |
| 406f70 | `init_buffer_256_a` | med | Init header fields then memset 0x100 buffer |
| 406fd0 | `init_buffer_256_b` | med | Init header (ushort) then memset 0x100 buffer |
| 4078d0 | `compare_int_eq` | med | Equality of first int of this and param |
| 4078f0 | `item_struct_equals` | med | Deep equality of game item struct (0x118, count at 0x114) |
| 4079c0 | `compare_3_bytes_ne` | med | Return 1 if any of 3 bytes differ |
| 407c80 | `formula_diminishing_int` | med | Game curve: 1 - 1/(x*0.1+1), 0 if x<1 |
| 407d60 | `formula_diminishing_float` | med | Game curve: 1 - 1/((x-1)*0.05+1) |
| 4095d0 | `formula_scaled_a` | med | Game curve: (1-1/(x*0.1+1))*3+1, 0 if x<1 |
| 409740 | `formula_curve_b` | med | Game curve: 1 - 1/((x+1)*0.1+1) |
| 40a7f0 | `formula_scaled_b` | med | Game curve: (1-1/(x*0.1+1))*3+1.5, 0 if x<1 |
| 40ef90 | `list_find_by_id_byte` | med | Search intrusive list at +0x1178 for node with matching byte id (game) |
| 4103a0 | `rbtree_inorder_walk` | med | In-order traversal of rb-tree at +0x139c (empty body) |
| 4116f0 | `formula_curve_c` | med | Game curve: (1-1/(x*0.1+1))+1, 0 if x<1 |
| 4120f0 | `formula_curve_d` | med | Game curve: (1-1/(x*0.1+1))*0.5+0.5 |
| 412c50 | `delete_member_object` | med | Delete owned member object pointer and null it |
| 413000 | `is_field4_nonzero` | med | Return true if dword at +4 is nonzero |
| 413420 | `resize_dword_array` | med | Grow/shrink array of 4-byte cells, copy old contents (game grid) |
| 4136d0 | `uninitialized_copy_items` | med | uninitialized_copy of 0x118-stride objects into dest |
| 4156e0 | `compare_3dword_eq_b` | med | Return 1 if any of 3 dwords differ |
| 415710 | `compare_3float_ne` | med | Return 1 if any of 3 floats differ |
| 415750 | `item_struct_equals_full` | med | Full equality of 0x118-byte item struct (all fields) |
| 4159b0 | `creature_items_equal` | med | Compare all 12 equipment item slots for equality (game) |
| 415b00 | `item_not_equals` | med | Negated item-struct equality test |
| 415c90 | `buffer_read_bounded` | med | Read param_2 bytes from stream buffer with bounds check |
| 415dd0 | `EntityData::serializeToStream` | med | Writes all Entity(0x1180) fields into growable send buffer via typed primitive writers |
| 416210 | `EntityData::writeDelta` | med | Delta-serializes Entity(0x1180) fields vs previous copy (param_4 changed-flag) into buffer |
| 416c50 | `std::string::_Assign_rv` | med | Move-assign body for std::string (steal heap ptr or copy SSO), reset source |
| 41ba70 | `std::vector<T0x188>::operator[]` | med | Return &base[i] for element stride 0x188 (Creature-size record) |
| 41c9e0 | `World::getVoxelField` | med | Bounds-check x,y (<=0x1fffff), resolve chunk, return field cell ptr in region grid |
| 41ce90 | `computeLengthSquared_16_16` | med | Fixed-point squared magnitude of two 64-bit vec components (allmul/alldiv 0x10000) |
| 41d160 | `floatVec3_to_byte3` | med | Truncate 3 floats to 3 signed bytes (quantize color/normal) |
| 41d190 | `std::vector<T0x148>::_Umove` | med | Uninitialized move Chunk(0x148) range, copies fields + string via _Move |
| 41d240 | `std::vector<T0xc>::_Ucopy` | med | Uninitialized copy of 12-byte elements via per-element copy(_41d950) |
| 41d270 | `std::equal(Chunk range)` | med | Element-wise equality compare of two Chunk(0x148) arrays (fields+floats) |
| 41d340 | `std::vector<T0x11c>::_Ucopy` | med | Uninitialized copy stride 0x11c elements (field + string via _41d340 helper) |
| 41d390 | `std::vector<T0xc>::_Move_backward` | med | Move-assign 12-byte owning elements, delete old heap ptr, null source |
| 41d410 | `std::vector<T0x11c>::_Ucopy` | med | Uninitialized copy stride 0x11c using string copy (_00413710) |
| 41d460 | `std::vector<T0xc>::_Ucopy_guarded` | med | Uninitialized copy 12-byte elements with exception unwind cleanup |
| 41d500 | `std::vector<T0x11c>::_Ucopy` | med | Uninitialized copy stride 0x11c with string copy (dup of _41d410) |
| 41d550 | `std::vector<T0x11c>::_Ufill_default` | med | Default-construct n elements stride 0x11c (zero + init magic + memset 0x100) |
| 41d5d0 | `std::vector<T0xc>::_Ufill_default` | med | Zero-initialize n 12-byte elements (3 null ptrs each) |
| 41d600 | `std::vector<T0x14>::_Ucopy` | med | Uninitialized copy of 20-byte elements field-by-field |
| 41d680 | `std::vector<T0x148>::_Ucopy` | med | Uninitialized copy of Chunk(0x148) elements via _41d820 |
| 41d6c0 | `std::vector<T0xc>::_Umove` | med | Move 12-byte elements (steal 3 ptrs, null source) |
| 41d720 | `std::vector<T0x11c>::vector(copy)` | med | Copy-construct vector<T0x11c>: reserve then _Ucopy elements |
| 41d820 | `Chunk::copyAssign` | med | Copy Chunk(0x148): string(_413710) + block of dword fields 0x118..0x144 |
| 41d8d0 | `VoxelColumn::init` | med | Init voxel/field struct: memset 0x100, capacity magic 0x3d924925, id=-1 |
| 41d950 | `std::vector<T0x11c>::operator=` | med | Copy-assign vector<T0x11c>: reuse/realloc storage then _Ucopy/_Umove |
| 41dae0 | `std::vector<T0x148>::operator=` | med | Copy-assign vector<Chunk 0x148>: reuse/realloc then copy |
| 41dc60 | `std::vector<T0xc>::operator=` | med | Copy-assign vector of 12-byte owning elements (destroy old, copy new) |
| 41de30 | `QuestText::copyStrings13` | med | Copy 13 consecutive std::string members (stride 0x118) via _00402a70 |
| 41df20 | `struct::copyAssign(vec+str)` | med | Copy struct: vector(_41dc60) + string(_402a70) + trailing int fields |
| 41df70 | `EntityData::copyAssign` | med | Member-wise copy of full Entity(0x1180): scalars, string, quest strings, tail arrays |
| 41e2e0 | `std::vector<T0xc>::operator[]` | med | Return &base[i] for 12-byte element stride |
| 41e320 | `std::vector<T0x11c>::_Reserve` | med | Allocate n*0x11c storage, set begin/end/cap, vector-too-long guard |
| 41e390 | `std::vector<T0x148>::_Reserve` | med | Allocate n*0x148 (Chunk) storage, vector-too-long guard |
| 41e400 | `std::vector<T0x11c>::_Grow_calc` | med | Compute geometric growth capacity for vector<T0x11c> |
| 41e450 | `std::vector<T0x14>::_Reallocate` | med | Reallocate 20-byte-element vector to param_1 capacity, move old, free |
| 41e540 | `std::vector<T0x11c>::_Reallocate` | med | Reallocate vector<T0x11c> to capacity, _Ucopy old elements, free |
| 41e640 | `std::vector<T0x148>::_Reallocate` | med | Reallocate vector<Chunk 0x148> to capacity, copy old, free |
| 41e740 | `std::vector<T0xc>::_Reallocate` | med | Reallocate vector of 12-byte owning elements, move + destroy old |
| 41e840 | `std::vector<T0x14>::reserve` | med | Ensure capacity for n extra 20-byte elements (geometric) |
| 41e8f0 | `std::vector<T0x11c>::_Grow_by` | med | Grow vector<T0x11c> to hold param_1 additional elements |
| 41e960 | `std::vector<T0x148>::reserve` | med | Ensure capacity for n extra Chunk(0x148) elements |
| 41ea10 | `std::vector<T0xc>::reserve` | med | Ensure capacity for n extra 12-byte elements |
| 41eb20 | `std::vector<T0xc>::erase` | med | Erase 12-byte element range, shift tail, destroy freed elements |
| 41ee20 | `World::deserializeZonePacket` | med | Read zone/chunk update packet: entity(0x118) list + hit(0x14) list into world |
| 41f4d0 | `std::vector<T0x14>::push_back` | med | Append 20-byte element to vector (reserve if full), copies self-ref safely |
| 41f5b0 | `std::vector<T0x148>::push_back` | med | Append Chunk(0x148) to vector (reserve if full) via _41d820 |
| 41f640 | `std::vector<T0x11c>::resize` | med | Resize vector<T0x11c>: shrink (destroy) or grow (default-fill) to n |
| 41f770 | `std::vector<T0xc>::resize` | med | Resize vector of 12-byte elements: erase tail or grow with defaults |
| 41f880 | `writeCombatActionToStream` | med | Serialize 0x28 record to buffer: 5 ints,2 bytes,2 ints,int64 (reserve+append) |
| 41f9e0 | `writeHitToStream` | med | Serialize 0x14 record to buffer: 2 ints,int,byte,int64 |
| 41faa0 | `World::serializeZoneSaveData` | med | Serialize zone: chunk list, entity vector, block/field arrays into buffer |
| 41fe60 | `VoxelColumn::setBlock` | med | Set voxel record at signed index in growable column (+0x18 ptr,+0x1c size) |
| 41ff00 | `World::fillVoxelColumn` | med | Fill a field's voxel column from top height down, sampling colors via _52d030 |
| 4200d0 | `std::map::insert_node(0x70)` | med | Buy node (_4267f0) and copy 0x70 value via _004227e0 |
| 420100 | `std::map::insert_node(0x1c)` | med | Buy node (_426870) and copy 0x1c value inline (key+fields) |
| 420160 | `std::map::insert_node(string)` | med | Buy node (_4268f0) and copy value containing std::string (_421f20) |
| 420200 | `std::map::insert_node(wstring)` | med | Buy node (_426830) and construct wstring value (_4172f0) |
| 4202b0 | `std::map::insert_node(0x47a)` | med | Buy node (_4268b0) and copy value via _00422a00 |
| 4202e0 | `std::map::insert_node(list)` | med | Buy node (_4268f0) and copy value containing std::list (_004226a0) |
| 420400 | `std::map::insert_node(0x28b)` | med | Buy node (_426970) and copy value via _00422c90 |
| 420430 | `std::map::insert_node(0x48)` | med | Buy node (_4269b0) and copy value + sub-struct via _00422da0 |
| 420470 | `std::map::insert_node(0x40)` | med | Buy node (_4268b0) and copy 0x40 value via _00422e10 |
| 4204a0 | `std::map::insert_node(Chunk)` | med | Buy node (_4269f0) and copy Chunk(0x148) value via _0041d820 |
| 4204d0 | `std::list<Chunk>::assign` | med | Assign list from Chunk range via _004218b0 (splice/copy) |
| 420bb0 | `std::list::_Assign(0x28)` | med | Copy-assign list nodes for 0x28 value type via _00420080 |
| 420c80 | `std::list::_Assign(str)` | med | Copy-assign list of string-valued nodes via _0052df40 |
| 420d50 | `std::list::_Assign(str2)` | med | Copy-assign list nodes via _00420160 (string value) |
| 420e20 | `std::list::_Assign(0x1c)` | med | Copy-assign list nodes (0x1c value) via _00420100 |
| 420ef0 | `std::list::_Assign(0x47a)` | med | Copy-assign list nodes via _004202b0 |
| 420fc0 | `std::list::_Assign(list)` | med | Copy-assign list-of-lists nodes via _004202e0 |
| 421090 | `std::list::_Assign(str3)` | med | Copy-assign list nodes with string via _00420380, list-too-long guard |
| 421160 | `std::list::_Assign(0x18)` | med | Copy-assign list nodes (0x18 value) via _004203c0 |
| 421230 | `std::list::_Assign(0x28b)` | med | Copy-assign list nodes via _00420400 |
| 421300 | `std::list::_Assign(0x48)` | med | Copy-assign list nodes (0x48 value) via _00420430 |
| 4213d0 | `std::list::_Assign(0x40)` | med | Copy-assign list nodes (0x40 value) via _00420470 |
| 4214a0 | `std::list::_Assign(0x08b)` | med | Copy-assign list nodes via _004f3ba0 |
| 421570 | `std::list<Chunk>::_Assign` | med | Copy-assign list of Chunk-valued nodes via _004204a0 |
| 421640 | `std::list::_Assign(0x14b)` | med | Copy-assign list nodes via _00549300 |
| 421710 | `std::list::_Assign(0x70)` | med | Copy-assign list nodes (0x70 value) via _004200d0 |
| 4217e0 | `std::list::_Assign_arr(0x1c)` | med | Assign list from contiguous 0x14-stride array via _00420100 |
| 4218b0 | `std::list<Chunk>::_Assign_arr` | med | Assign list from Chunk(0x148) array via _004204a0, list-too-long guard |
| 421980 | `std::vector<T0x78>::_Ucopy` | med | Uninitialized copy of 0x78-byte elements via _00423350 |
| 4219c0 | `serializeList_records_0x28` | med | Serialize list to buffer: count then memcpy each 0x28 node value |
| 421a30 | `serializeList_records_0x10` | med | Serialize list: count then per-node 0x10-byte value |
| 421aa0 | `serializeList_records_0x70` | med | Serialize list: count then memcpy each 0x70 node value |
| 421b10 | `serializeList_records_0x14` | med | Serialize list: count then per-node 0x14 value |
| 421b80 | `serializeList_records_0x48` | med | Serialize list: count then memcpy each 0x48 node value |
| 421bf0 | `serializeList_records_0x120` | med | Serialize list: count then memcpy each 0x120 node value |
| 421c60 | `serializeList_records_0x18` | med | Serialize list: count then per-node 0x18 value |
| 421ce0 | `serializeList_records_0x38` | med | Serialize list: count then memcpy each 0x38 node value |
| 421d50 | `serializeList_records_0x58` | med | Serialize list: count then memcpy each 0x58 node value |
| 421dc0 | `serializeList_Chunk_0x148` | med | Serialize list: count then memcpy each Chunk(0x148) node value |
| 421e80 | `std::list::list(copy,0x28)` | med | Copy-construct list, alloc head then _Assign nodes via _00420bb0 |
| 421f20 | `std::list::list(copy,str)` | med | Copy-construct list of string values via _00420c80 |
| 421fc0 | `std::list::list(copy,str2)` | med | Copy-construct list via _00420d50 |
| 422060 | `std::list::list(copy,0x70)` | med | Copy-construct list via _00421710 |
| 422100 | `std::list::list(copy,0x1c)` | med | Copy-construct list via _00420e20 |
| 4221a0 | `std::list::list(copy,0x47a)` | med | Copy-construct list via _00420ef0 |
| 422240 | `std::list::list(copy,list)` | med | Copy-construct list-of-lists via _00420fc0 |
| 4222e0 | `std::list::list(copy,str3)` | med | Copy-construct list via _00421090 |
| 422380 | `std::list::list(copy,0x18)` | med | Copy-construct list via _00421160 |
| 422420 | `std::list::list(copy,0x28b)` | med | Copy-construct list via _00421230 |
| 4224c0 | `std::list::list(copy,0x48)` | med | Copy-construct list via _00421300 |
| 422560 | `std::list::list(copy,0x40)` | med | Copy-construct list via _004213d0 |
| 422600 | `std::list::list(copy,0x08b)` | med | Copy-construct list via _004214a0 |
| 4226a0 | `std::list<Chunk>::list(copy)` | med | Copy-construct list of Chunk values via _00421570 |
| 422740 | `std::list::list(copy,0x14b)` | med | Copy-construct list via _00421640 |
| 4227e0 | `copyStruct_0x70` | med | Member-wise copy of 0x70-byte value struct (skips gap at +0x14) |
| 422890 | `initStruct_0x70_defaults` | med | Init 0x70 struct defaults: id fields=-1, floats 0.5/1.0/1.0 |
| 422a00 | `copyStruct_0x47` | med | Member-wise copy of ~0x47-byte value struct |
| 422a90 | `initStruct_0x47_zero` | med | Zero-initialize ~0x47-byte value struct fields |
| 422c00 | `Zone::extractChunkList` | med | Build struct from zone: copy 2 ids + assign Chunk list from zone range |
| 422c90 | `copyStruct_0x38` | med | Member-wise copy of 0x38-byte value struct |
| 422d00 | `initStruct_0x38_zero` | med | Zero-initialize 0x38-byte value struct |
| 422d70 | `copyStruct_head_plus_0x48` | med | Copy 3-int head then sub-struct via _00422da0 |
| 422da0 | `copyStruct_0x48` | med | Member-wise copy of 0x48-byte value struct (skips +4) |
| 422e10 | `copyStruct_0x44` | med | Member-wise copy of 0x44-byte value struct |
| 423350 | `copyStruct_0x74` | med | Member-wise copy of 0x74-byte value struct (skips +0x54) |
| 423400 | `Zone::copyStateContainer` | med | Copy struct of 12 std::list members (net/save state container) |
| 423c90 | `copyStruct_0x28` | med | Member-wise copy of 0x28-byte value struct |
| 423dd0 | `Server::worldUpdateSendLoop` | med | Per-client send worker: timeGetTime pacing, walk entity tree, push zone/entity updates |
| 426020 | `Connection::receiveDispatch` | med | Recv loop (Ordinal_16) + switch on packet type, decode and apply to world |
| 4267b0 | `std::list::_Buyheadnode(0x1180)` | med | Allocate+init list head sentinel sized for 0x1180 nodes |
| 4269f0 | `std::list::_Buynode(0x150)` | med | Allocate list node (0x150) with prev/next links |
| 426c20 | `node_dtor_free_list_0x10` | med | Destroy embedded list at +0x10 (tidy nodes) then free node |
| 426db0 | `std::vector<T0x78>::_Reallocate` | med | Reallocate 0x78-byte-element vector, _Ucopy old, free old storage |
| 428160 | `std::list<T>::front_or_null` | med | Returns first node, or 0 when list empty (begin==end) |
| 428170 | `std::list<T>::operator=` | med | Locked clear then copy-assign list nodes (member at +0x3c) |
| 4281d0 | `std::list<T>::operator=` | med | Locked clear then copy-assign list nodes (member at +0x44) |
| 428230 | `std::list<T>::operator=` | med | Locked clear then copy-assign list nodes (member at +0x34) |
| 428ee0 | `std::vector<T>::size` | med | Element count = (end-begin)>>5 for 0x20-byte elements |
| 42cfc0 | `_Catch_operator_delete` | med | Catch-block cleanup: frees object |
| 42d000 | `_Catch_operator_delete` | med | Catch-block cleanup: frees object |
| 42d040 | `_Catch_cleanup_thunk` | med | Catch-block cleanup destructor thunk |
| 42d4c0 | `_Catch_operator_delete` | med | Catch-block cleanup: frees object |
| 42e900 | `std::_Fputc` | med | Writes one char via fputc, returns success flag |
| 42eee0 | `std::basic_streambuf::`scalar deleting dtor'` | med | Destroys and frees a basic_streambuf |
| 42ef30 | `std::basic_streambuf::`scalar deleting dtor'` | med | Destroys and frees a basic_streambuf |
| 42f480 | `std::basic_filebuf<char>::close` | med | Closes filebuf: endwrite then fclose |
| 430780 | `std::basic_string::assign` | med | Builds string by reserving then appending two sources |
| 430870 | `std::_Tree::_Buynode` | med | Allocates map node and moves a list value into it |
| 430930 | `std::_Tree::_Insert` | med | Red-black insert with rebalancing (map<int,list>) |
| 430b40 | `std::map::insert` | med | map insert dispatching to _Tree::_Insert |
| 430d70 | `std::_Tree::_Insert` | med | Red-black insert with rebalancing |
| 430fa0 | `std::basic_string::assign` | med | Clears and copy-assigns a std::string |
| 430fe0 | `std::basic_string::assign_cstr` | med | Assigns a C-string (computes strlen) |
| 4311a0 | `std::_Tree::_Erase_node_with_list` | med | Destroys a map node's embedded list then frees the node |
| 4311f0 | `std::basic_string::replace` | med | Replaces/inserts substring; throws length/pos errors |
| 4312e0 | `std::basic_string::append` | med | Appends buffer to string; throws string-too-long |
| 431400 | `game_loadVoxelModelsFromDb` | med | Loads .cub voxel models (cubequest4/spiribit/egg1...) from data1.db at startup (game) |
| 45f030 | `std::list<T>::_Insert` | med | Inserts a list node; throws list-too-long |
| 5322d0 | `GameController_updateSubsystems` | med | Server build of cube 0x60c510 GameController_updateSubsystems: top-callee call-count profile matches exactly (242/154/152/111/103/89/76/69/67/61/56/56 + CRefTime::Millisecs x53). 60129 B; was misnamed lib_fn_5322d0 and misclassified lib/other (never-game-called blind spot; fixed via curated_override.tsv). Ghidra process:timeout in full export; recovered with 3600s + 512MB payload (383s); body in gap/server/extra_bodies.c. |
| 401000 | `assign_two_qwords` | low | Store two 8-byte values (16-byte struct/pair init) |
| 406260 | `vec_op_self_wrapper` | low | Wrapper invoking vec op with this as both operands |
| 408230 | `creature_spawn_projectile` | low | Charge-up gauge then push projectile onto list (game) |
| 408300 | `calc_attack_power` | low | Compute attack power from stats/equipment (game) |
| 408f70 | `calc_damage_value` | low | Compute damage with equipment/effect modifiers and mode multiplier (game) |
| 4094a0 | `calc_stat_variant` | low | Compute stat value from base+equipment (game) |
| 409620 | `check_weapon_kind` | low | Predicate on creature weapon-type byte and subtype (game) |
| 409780 | `get_ability_cast_duration` | low | Switch ability id -> cast/effect duration in ms (game) |
| 409ac0 | `calc_regen_total` | low | Sum regen contributions across equipment slots via pow (game) |
| 40a840 | `generate_entity_appearance` | low | Randomize/derive NPC appearance and stat block by race (game) |
| 40efc0 | `get_value_range_a` | low | Switch id -> min/max range outputs (game table) |
| 40f0a0 | `get_value_range_b` | low | Switch id -> min/max range outputs (game table) |
| 40f220 | `roll_probability` | low | RNG probability roll with consumable-type modifier (game) |
| 40f520 | `check_proc_chance` | low | Evaluate ability proc chance vs RNG over effect list (game) |
| 40f610 | `check_ability_state` | low | Predicate on ability type and charge state (game) |
| 40f6d0 | `stub_return_zero` | low | Always returns 0 |
| 40f6e0 | `check_falling_state` | low | Predicate: falling with negative z-velocity and idle (game) |
| 40f7f0 | `is_ranged_ability_id` | low | Switch classify ability id -> bool (game table) |
| 40f8b0 | `is_consumable_effect` | low | Predicate on type/subtype bytes for consumable (game) |
| 40ffe0 | `get_cast_time` | low | Return cast/attack time, reduced by attribute (game) |
| 4110d0 | `creature_reset_state` | low | Reset large Creature/entity object: free lists, zero fields (game) |
| 411360 | `creature_init_fields` | low | Initialize Creature default field values + memset regions (game) |
| 411540 | `calc_attack_power_b` | low | Compute attack power variant from stats/equipment (game) |
| 412550 | `process_regen_tick` | low | Drain regen accumulator, apply per-tick heal loop (game) |
| 4139b0 | `calc_defense_value` | low | Compute defense/block value from item type/subtype (game) |
| 413aa0 | `get_effect_duration_a` | low | Return duration by type byte (game) |
| 413ac0 | `calc_dot_tick_value` | low | Compute damage-over-time tick value from item (game) |
| 413be0 | `calc_heal_value` | low | Compute heal amount by item subtype (game) |
| 413df0 | `get_material_color` | low | Lookup RGBA color by material/type id (game table) |
| 414200 | `calc_value_ranged` | low | Compute value for ranged item subtypes (game) |
| 414260 | `calc_defense_value_b` | low | Defense/block value variant by subtype (game) |
| 414470 | `roll_random_level` | low | Pick random level within curve-derived range (game) |
| 41cae0 | `getFieldAtFixedOffset` | low | Return dword member at large fixed offset (+0x80015c) of world/region struct |
| 41d7e0 | `struct_clear_fields_c_10` | low | Zero two dword fields (+0xc,+0x10) of a struct |
| 41e300 | `std::vector<T0x148>::back_slot` | low | Return current end ptr and advance vector end by 0x148 (Chunk push slot) |
| 41ebb0 | `rbtree_node_isRed` | low | Return !(sign bit of color byte at +3): red/black test for tree node |
| 422af0 | `initStruct_0x10_zero` | low | Zero 4 dwords (0x10 struct) |
| 427000 | `game_inventoryAccumulateCount` | low | Adds count to inventory/currency totals keyed by item type-code (game logic, mislabeled crtstl) |
| 4272d0 | `game_buildItemDefinition` | low | Builds an item/entity definition record from a serialized descriptor (game logic) |
| 428290 | `game_isEntityTypeSolid` | low | Predicate over entity/item type-code byte (game logic) |
| 4282d0 | `game_isItemTypeStackable` | low | Predicate classifying item type-code (game logic) |
| 4282f0 | `game_itemTypeCategory` | low | Maps item type-code to category id 0-3 (game logic) |
| 428630 | `game_appendItemEntry` | low | Parses and appends an item/definition entry to a container (called by 427000) |
| 428780 | `accessor_dword_at_4` | low | Returns dword at object offset +4 |
| 428930 | `array_index_stride32` | low | Returns base + index*0x20 (element address accessor) |
| 42e220 | `game_gridLookup1024` | low | 2D 0x400x0x400 grid cell accessor (game world/region grid) |
| 42e880 | `game_blockLookup` | low | Voxel block lookup on 0x40-subdivided world grid (game) |
| 42edb0 | `memcmp3_equal` | low | Compares first 3 bytes of two buffers for equality (magic check) |
| 42ede0 | `vec3_div_scalar` | low | Divides a 3-int vector by scalar into out param (game math) |
| 430730 | `game_voxelColorAt` | low | 3D voxel-model color accessor (x,y,z into RGB grid) — .cub model (game) |

## other (300)

| addr | proposed name | conf | purpose |
|---|---|---|---|
| 4072a0 | `std_map_destroy` | high | Destroy std::map: erase tree then free head (unwind) |
| 407650 | `std_vector_string_tidy` | high | Destroy vector<string> range then free storage (unwind) |
| 4129a0 | `ostream_sentry_dtor` | high | std::basic_ostream sentry destructor (_Osfx if no uncaught exc) |
| 4135d0 | `thread_entry_trampoline` | high | Thread entry: invoke functor then _endthread (bad_function_call guard) |
| 423700 | `std::_Deallocate` | high | operator delete(*param_1): free a single heap block pointed by field |
| 423710 | `std::list::_Tidy` | high | Destroy all list nodes then free head sentinel, reset size |
| 423770 | `std::list::_Tidy(at+8)` | high | Destroy all nodes of list embedded at +8 then free head, clear size |
| 45f120 | `sqlite3_value_bytes` | high | Returns byte length of an sqlite3_value (Mem), stringifying if needed |
| 45f160 | `sqlite3_value_double` | high | Coerces an sqlite3 Mem value to double (int/real/text via AtoF) |
| 45f1d0 | `sqlite3_value_int` | high | Coerces an sqlite3 Mem value to 32-bit int |
| 45f250 | `sqlite3_value_int64` | high | Coerces an sqlite3 Mem value to 64-bit int |
| 45f370 | `sqlite3_value_type` | high | Returns the cached datatype code of an sqlite3_value |
| 45f380 | `sqlite3_value_numeric_type` | high | Applies numeric affinity and returns the resulting type |
| 45f3e0 | `sqlite3_likeFunc` | high | SQL LIKE/GLOB implementation; validates ESCAPE and pattern complexity |
| 45f5b0 | `winShmMap` | high | os_win shared-memory mapping (winShmMap1/2/3 log tags) |
| 45f7d0 | `sqlite3_aggregate_context` | high | Allocates/returns the zeroed per-aggregate context buffer |
| 45f8a0 | `sqlite3_set_auxdata` | high | Stores per-argument auxiliary data + destructor, growing the array |
| 45f990 | `sqlite3_result_text` | high | Sets context result to UTF-8 text (VdbeMemSetStr) |
| 45f9d0 | `sqlite3_result_double` | high | Sets context result to a double |
| 45fa00 | `sqlite3_result_text16le` | high | Sets context result to UTF-16LE text |
| 45fa70 | `sqlite3_result_text16be` | high | Sets context result to UTF-16BE text |
| 45faa0 | `sqlite3_result_error_toobig` | high | Sets the context error to SQLITE_TOOBIG |
| 45fad0 | `sqlite3_result_error_nomem` | high | Sets the context error to SQLITE_NOMEM |
| 45fb30 | `sqlite3ErrStr` | high | Maps an error code to its message string (unknown error/ROLLBACK) |
| 45fbd0 | `sqlite3_result_int` | high | Sets context result to a 32-bit int |
| 45fc30 | `sqlite3_result_int64` | high | Sets context result to a 64-bit int |
| 45fc90 | `sqlite3_result_null` | high | Sets context result to NULL |
| 45fd10 | `sqlite3_result_text16` | high | Sets context result to UTF-16 text (enc 1) |
| 45fd50 | `sqlite3_result_text16be` | high | Sets context result to UTF-16BE text (enc 2) |
| 45fdc0 | `winSetSystemCall` | high | os_win: override an aSyscall entry by name (AreFileApisANSI table) |
| 45fe90 | `sqlite3_result_blob` | high | Sets context result to a blob (enc 3) |
| 45ffa0 | `winGetSystemCall` | high | os_win: look up an aSyscall pointer by name (CharUpperW table) |
| 460380 | `sqlite3_prepare_v2` | high | Compiles SQL text to a prepared statement (mutex-guarded) |
| 4603f0 | `winNextSystemCall` | high | os_win: iterate aSyscall table returning next name (CharUpperW) |
| 460480 | `sqlite3_prepare_v2` | high | Prepare variant with an extra flag parameter |
| 4604f0 | `sqlite3_prepare16` | high | Prepare from UTF-16 SQL (converts to UTF-8 first) |
| 460590 | `sqlite3_progress_handler` | high | Registers a progress callback and its arg on the db handle |
| 4605e0 | `sqlite3_busy_handler` | high | Registers a busy callback and its arg on the db handle |
| 460630 | `sqlite3_hexFunc` | high | SQL hex(): encodes a blob to hexadecimal text |
| 4607a0 | `sqlite3_sleep` | high | Sleeps N milliseconds via the default VFS xSleep |
| 4608d0 | `sqlite3_next_stmt` | high | Iterates the prepared-statement list on a db handle |
| 460910 | `sqlite3_commit_hook` | high | Registers a commit callback (+0xa8), returns previous arg |
| 460960 | `sqlite3_rollback_hook` | high | Registers a rollback callback (+0xb0) |
| 460c30 | `memjrnlRead` | high | In-memory journal read across a 0x3fc-byte page chain (memjournal.c) |
| 460d00 | `sqlite3_update_hook` | high | Registers a row-update callback (+0xb8) |
| 461320 | `sqlite3_soft_heap_limit64` | high | Sets/returns the soft heap limit under the mem mutex |
| 461400 | `sqlite3_soft_heap_limit` | high | 32-bit soft-heap-limit wrapper over the 64-bit setter |
| 461420 | `memjrnlWrite` | high | In-memory journal write into a 0x400-byte page chain (memjournal.c) |
| 461530 | `sqlite3_juliandayFunc` | high | SQL julianday(): computes the Julian day number (date.c) |
| 461bb0 | `sqlite3_datetimeFunc` | high | SQL datetime(): formats %Y-%m-%d %H:%M:%S (date.c) |
| 461d80 | `sqlite3_timeFunc` | high | SQL time(): formats %H:%M:%S (date.c) |
| 461e80 | `sqlite3DetachFunc` | high | DETACH DATABASE implementation (attach.c) |
| 462070 | `memjrnlFreePages` | high | Frees the in-memory journal page chain and resets the file object |
| 462150 | `sqlite3_dateFunc` | high | SQL date(): formats %Y-%m-%d (date.c) |
| 4622c0 | `memjrnlClose` | high | Closes the in-memory journal (frees its pages) |
| 462330 | `sqlite3_strftimeFunc` | high | SQL strftime(): custom date formatting (%06.3f/%.16g) (date.c) |
| 462930 | `pcache1Fetch` | high | Fetches/creates a page in the page-cache hash table (pcache1.c) |
| 462b60 | `winAccess` | high | os_win file-access check (GetFileAttributes with retry Sleep) |
| 462d70 | `sqlite3CompileOptionUsed` | high | Checks whether a compile-time option (SQLITE_*) is enabled |
| 463000 | `sumStep` | high | aggregate SUM/TOTAL xStep: accumulate int64/double into ctx, track overflow/approx |
| 4636f0 | `sumFinalize` | high | aggregate SUM xFinal: result_int64/double from accumulator ('integer overflow') |
| 4637e0 | `avgFinalize` | high | aggregate AVG xFinal: result_double = rSum/count |
| 463860 | `winFullPathname` | high | Win32 VFS xFullPathname: GetFullPathName A/W build absolute path |
| 463b80 | `totalFinalize` | high | aggregate TOTAL xFinal: result_double of accumulated sum (0.0 if null) |
| 463c80 | `countStep` | high | aggregate COUNT xStep: increment 64-bit counter (skip NULL arg) |
| 463e90 | `minmaxStep` | high | aggregate min()/max() xStep: keep extreme value via comparator FUN_004a0720 |
| 463f80 | `sqlite3Reprepare` | high | recompile expired prepared statement, swap in new Vdbe |
| 464270 | `winDlOpen` | high | Win32 VFS xDlOpen: LoadLibrary A/W |
| 464310 | `groupConcatStep` | high | group_concat xStep: append separator + value text to StrAccum |
| 464c00 | `sqlite3_step` | high | public API sqlite3_step: run stmt (sqlite3Step), map busy/misuse |
| 464cd0 | `sqlite3_finalize` | high | public API: finalize prepared statement (sqlite3VdbeFinalize) |
| 464d90 | `groupConcatFinalize` | high | group_concat xFinal: result_text of accumulated string |
| 464e60 | `winDlSym` | high | Win32 VFS xDlSym: GetProcAddress |
| 464f20 | `sqlite3_vfs_register` | high | register sqlite3_vfs into global list (opt makeDflt) |
| 464fa0 | `sqlite3_vfs_unregister` | high | unlink sqlite3_vfs from global registration list |
| 465020 | `sqlite3_mutex_alloc` | high | allocate mutex via mutex subsystem (DAT_00582b10) |
| 465040 | `sqlite3_mutex_free` | high | free mutex (DAT_00582b14) |
| 465060 | `winDlClose` | high | Win32 VFS xDlClose: FreeLibrary |
| 465070 | `winClose` | high | Win32 VFS xClose: CloseHandle with retry ('winClose') |
| 465100 | `sqlite3_mutex_try` | high | try-enter mutex (DAT_00582b1c) |
| 465140 | `winRandomness` | high | Win32 VFS xRandomness: seed from systime/pid/tickcount/perfcounter |
| 465210 | `winRead` | high | Win32 VFS xRead: ReadFile with lock-conflict retry, zero-fill short read |
| 4655a0 | `winSleep` | high | Win32 VFS xSleep: Sleep (microsec rounded to ms) |
| 4655d0 | `sqlite3_status` | high | get/reset global status counter[op] (current+highwater) |
| 465630 | `winCurrentTimeInt64` | high | Win32 VFS: current time as Julian-day-ms int64 |
| 465680 | `sqlite3_db_config` | high | per-connection config: op1001 lookaside else enable-flag bits |
| 465720 | `sqlite3_db_status` | high | connection status: lookaside/cache/schema/stmt memory usage |
| 465a30 | `sqlite3_stmt_status` | high | get/reset Vdbe counter[op] (fullscan/sort/autoindex) |
| 465a50 | `winWrite` | high | Win32 VFS xWrite: WriteFile with lock-conflict retry |
| 465ba0 | `winCurrentTime` | high | Win32 VFS xCurrentTime: current time as Julian-day double |
| 465c00 | `sqlite3_extended_result_codes` | high | enable/disable extended error codes (db+0x30 mask) |
| 465c40 | `sqlite3_last_insert_rowid` | high | return db->lastRowid (db+0x20) |
| 465c50 | `sqlite3_changes` | high | return db->nChange (db+0x48) |
| 465c60 | `sqlite3_total_changes` | high | return db->nTotalChange (db+0x4c) |
| 465c70 | `sqlite3_interrupt` | high | set db->u1.isInterrupted=1 (db+0xe0) |
| 465c90 | `sqlite3Complete` | high | tokenize SQL, true if statement complete (';' terminated) |
| 4660e0 | `sqlite3_complete` | high | public API: wrap sqlite3Complete on Mem-copied string |
| 4661b0 | `sqlite3_busy_handler` | high | set db busy handler callback+arg (db+0x1ac/0x1b0) |
| 466390 | `winTruncate` | high | Win32 VFS xTruncate: seek + SetEndOfFile (chunk-rounded) |
| 466440 | `sqlite3_get_table` | high | public API: run query, collect all rows into string array |
| 4665f0 | `sqlite3_free_table` | high | free result array from sqlite3_get_table |
| 466ae0 | `winSync` | high | Win32 VFS xSync: FlushFileBuffers |
| 466b20 | `sqlite3_malloc` | high | public malloc wrapper (init + sqlite3Malloc) |
| 466b40 | `sqlite3_realloc` | high | public realloc wrapper (init + sqlite3Realloc) |
| 466ea0 | `typeofFunc` | high | SQL typeof(): result_text 'integer/real/text/blob/null' |
| 466f30 | `winFileSize` | high | Win32 VFS xFileSize: GetFileSize |
| 467060 | `lengthFunc` | high | SQL length(): byte count for blob/num, UTF-8 char count for text |
| 467170 | `sqlite3_commit_hook` | high | set commit hook callback+arg (db+0x98/0x9c), return old |
| 4671c0 | `sqlite3_backup_init` | high | create backup object between two db connections (distinct check) |
| 467d70 | `sqlite3_rollback_hook` | high | set rollback hook callback+arg (db+0xa0/0xa4), return old |
| 467ed0 | `sqlite3_update_hook` | high | set update hook callback+arg (db+0x114/0x118/0x11c) |
| 468070 | `absFunc` | high | SQL abs(): \|int64\| (overflow-checked) or \|double\| |
| 4681c0 | `winLock` | high | Win32 VFS xLock: acquire shared/reserved/pending/exclusive byte-range locks |
| 468380 | `sqlite3StrNICmp` | high | case-insensitive length-bounded string compare (UpperToLower) |
| 468410 | `sqlite3_wal_hook` | high | set WAL commit hook callback+arg (db+0xc0/0xc4), return old |
| 468460 | `instrFunc` | high | SQL instr(): 1-based position of substring, else 0 |
| 4686e0 | `sqlite3_errcode` | high | return db->errCode (validated magic) |
| 468750 | `sqlite3_wal_checkpoint` | high | checkpoint WAL for named/all databases |
| 4688d0 | `sqlite3_errmsg16` | high | return UTF-16 error message string for db |
| 4689a0 | `sqlite3_limit` | high | get/set per-connection limit[id], clamp to hard limit |
| 468a90 | `substrFunc` | high | SQL substr(): extract substring by 1-based offset/len (UTF-8 aware) |
| 468dc0 | `winCheckReservedLock` | high | Win32 VFS xCheckReservedLock: test reserved byte lock |
| 468e50 | `sqlite3_prepare_v2` | high | public API sqlite3_prepare_v2 (UTF-8, saves SQL) |
| 468e70 | `winUnlock` | high | Win32 VFS xUnlock: release byte-range locks down to level |
| 468f40 | `sqlite3_prepare16` | high | public API sqlite3_prepare16 (UTF-16) |
| 468f60 | `sqlite3_prepare16_v2` | high | public API sqlite3_prepare16_v2 (UTF-16) |
| 468fa0 | `winFileControl` | high | Win32 VFS xFileControl: lockstate/size-hint/chunk/tempname etc |
| 469170 | `sqlite3MemMalloc` | high | win32 default malloc: allocate with 8-byte size header |
| 4691c0 | `sqlite3_bind_double` | high | bind double to parameter (vdbeUnbind + MemSetDouble) |
| 469220 | `sqlite3_bind_int` | high | bind 32-bit int to parameter |
| 469280 | `sqlite3MemFree` | high | win32 default free (free(p-8)) |
| 469290 | `sqlite3_bind_int64` | high | bind 64-bit int to parameter |
| 4692f0 | `roundFunc` | high | SQL round(): round double to N digits (sprintf %f fallback) |
| 4694b0 | `sqlite3_bind_null` | high | bind NULL to parameter (vdbeUnbind) |
| 4694f0 | `sqlite3MemSize` | high | win32 default malloc size (header at p-8) |
| 469530 | `sqlite3MemRealloc` | high | win32 default realloc with size header |
| 469590 | `sqlite3_bind_text16` | high | bind UTF-16 text to parameter |
| 4695b0 | `sqlite3_bind_value` | high | bind a sqlite3_value (dispatch by type) to parameter |
| 469710 | `sqlite3_bind_zeroblob` | high | bind zeroblob(n) to parameter |
| 469760 | `sqlite3MemRoundup` | high | win32 default malloc roundup to 8 bytes |
| 469830 | `sqlite3_clear_bindings` | high | release/NULL all bound parameter values of a stmt |
| 469960 | `upperFunc` | high | SQL upper(): ASCII uppercase copy |
| 469b10 | `lowerFunc` | high | SQL lower(): ASCII lowercase copy (UpperToLower table) |
| 46a030 | `randomFunc` | high | SQL random(): return random signed 64-bit int |
| 46a100 | `winOpen` | high | Win32 VFS xOpen: CreateFile A/W with retry, init file handle |
| 46a4c0 | `sqlite3_column_bytes16` | high | return UTF-16 byte length of result column i |
| 46a520 | `winDelete` | high | Win32 VFS xDelete: DeleteFile A/W with retry |
| 46a710 | `sqlite3_column_double` | high | return double value of result column i |
| 46a790 | `sqlite3_column_int` | high | return 32-bit int value of result column i |
| 46a7c0 | `randomblobFunc` | high | SQL randomblob(n): result blob of n random bytes |
| 46a860 | `sqlite3_column_int64` | high | return 64-bit int value of result column i |
| 46a8f0 | `sqlite3_column_text` | high | return UTF-8 text of result column i |
| 46a920 | `sqlite3_column_text16` | high | return UTF-16 text of result column i |
| 46a950 | `sqlite3_column_type` | high | return datatype code of result column i |
| 46a9f0 | `sqlite3_column_value` | high | return protected sqlite3_value for result column i |
| 46ace0 | `sqlite3_create_function` | high | register UTF-8 scalar/aggregate function (no destructor) |
| 46ad10 | `winMutexAlloc` | high | Win32 mutex: allocate/init CRITICAL_SECTION (or static slot) |
| 46ad70 | `winShmUnmap` | high | Win32 VFS: unmap/close shared-memory node, drop refcount |
| 46ae30 | `winMutexFree` | high | Win32 mutex: DeleteCriticalSection + free |
| 46ae50 | `sqlite3_create_function16` | high | register UTF-16 named scalar/aggregate function |
| 46aef0 | `winMutexEnter` | high | Win32 mutex: EnterCriticalSection |
| 46af10 | `winShmLock` | high | Win32 VFS xShmLock: LockFile/Unlock shared/exclusive on -SHM ranges |
| 46b0d0 | `winMutexLeave` | high | Win32 mutex: LeaveCriticalSection |
| 46b0e0 | `sqlite3_create_function_v2` | high | register function with destructor (createFunctionApi core) |
| 46bab0 | `allSpaces` | high | true if last n bytes are all spaces (record-compare helper) |
| 479af0 | `hash_find` | high | Generic name-hash lookup with case-fold compare (DAT_00569620); SQLite sqlite3HashFind |
| 47c390 | `hash_findEntry` | high | Linear-probe/chain hash lookup with case-fold compare over table bucket; SQLite hash find |
| 487580 | `prng_nextByte` | high | RC4-style PRNG: lazily seeds 256-byte state from VFS randomness then returns next keystream byte; SQLite |
| 487c30 | `hash_rehash` | high | Rebuilds hash table to param_2 buckets, reinserting all entries; SQLite rehash |
| 48c460 | `func_buildHash` | high | Inserts builtin/rename SQL functions (sqlite_rename_table/trigger) into function hash table; SQLite |
| 48cac0 | `strAccum_appendSpaces` | high | Appends param_2 space characters to a StrAccum in 0x1d-byte chunks, growing buffer; SQLite |
| 48e8c0 | `bitvec_clear` | high | Clears a page bit in a Bitvec (recurse sub-buckets, rehash hash leaf); SQLite sqlite3BitvecClear |
| 48e9a0 | `bitvec_destroy` | high | Recursively frees a Bitvec tree (0x7d sub-pointers) with allocator accounting; SQLite sqlite3BitvecDestroy |
| 48ea60 | `bitvec_set` | high | Sets a page bit in a Bitvec, splitting hash leaf into sub-buckets on overflow; SQLite sqlite3BitvecSet |
| 48ec40 | `bitvec_test` | high | Tests whether a page bit is set in a Bitvec (recurse/hash probe); SQLite sqlite3BitvecTestNotNull |
| 4a14c0 | `getAndInitPage` | high | Acquire pager page param_2 into a MemPage, error on 0/corruption, init contents or zero |
| 4bd350 | `subjournalPage` | high | Write a page to the pager sub-journal (encode pgno + page data at computed offset), bump count |
| 407730 | `copy_struct_0xac` | med | Field-by-field copy of ~0xac-byte struct |
| 412980 | `unwind_stream_dtor` | med | Unwind cleanup: invoke stream base virtual destructor |
| 413560 | `std_function_deleter` | med | std::function target deleter (invoke vfunc +0x10, null slot) |
| 413590 | `std_function_deleter2` | med | Double std::function target deleter (unwind) |
| 4137c0 | `compare_3dword_eq_a` | med | Return 1 if 3 dwords all equal |
| 418180 | `rapidxml::skip_whitespace_to_tag` | med | XML parser: skip chars via lookup table until '<'; null-terminates text run |
| 4181d0 | `rapidxml::parse_node_data` | med | XML parse text node, decode '&' entities, stop at '<'; collapses via memmove |
| 418360 | `rapidxml::parse_data_crlf` | med | XML parse text normalizing CRLF to LF, stop at '<' |
| 418cf0 | `rapidxml::skip_attr_value_crlf` | med | XML skip attribute value to terminator(param_2), CRLF->LF, no entities |
| 418db0 | `rapidxml::parse_attr_value_crlf` | med | XML parse attribute value to param_2 terminator, CRLF->LF + entity decode |
| 419490 | `rapidxml::skip_attr_value` | med | XML skip attribute value to terminator(param_2) using class-table bit2 |
| 4194e0 | `rapidxml::parse_attr_value` | med | XML parse attribute value to terminator with '&' entity decode |
| 4195a0 | `rapidxml::parse_attr_value_ws` | med | XML attr value to terminator, whitespace(bit3)->space normalization |
| 419670 | `rapidxml::parse_attr_value_ws_ent` | med | XML attr value: terminator + whitespace-normalize + '&' entity decode |
| 419770 | `rapidxml::parse_attr_value_trim` | med | XML attr value: trim leading ws, normalize inner ws, terminator, trim trailing |
| 4198e0 | `rapidxml::parse_attr_value_trim_ent` | med | XML attr value: leading-trim + ws-normalize + entity decode + trailing-trim |
| 419fd0 | `std::_Tree::~_Tree` | med | Destroy std::map/set node subtree (_Erase recursive) then free head node |
| 41a000 | `std::_Tree::~_Tree(variant)` | med | Destroy std::map/set (other value type) via _Erase then free head |
| 420040 | `std::map<int,Entity>::_Buynode` | med | Allocate map node (0x1180 value) and copy Entity key/value in place |
| 420380 | `std::map::insert_node(str+2)` | med | Buy node (_426930) and copy key + std::string via _00413710 |
| 420540 | `std::map<int,Entity>::_Copy` | med | Recursively deep-copy Entity map subtree (clone nodes) |
| 422b10 | `QuestText::copyStrings13` | med | Copy 13 std::string members (stride 0x118) via _00413710 |
| 422f90 | `EntityData::copyConstruct` | med | Member-wise copy of Entity(0x1180): scalars, string, quest strings, tail arrays |
| 423750 | `dtor_helper_428080` | med | Run subobject cleanup (_00428080) then free base heap block |
| 426a70 | `std::_Tree::_Buynode(0x1180)` | med | Allocate map node (0x1180) copying parent/left/right links |
| 42c250 | `_Unwind_dtor_container` | med | Exception-unwind cleanup: destroys a container/node |
| 42c280 | `_Unwind_dtor_container` | med | Exception-unwind cleanup destructor thunk |
| 42c2b0 | `_Unwind_operator_delete` | med | Exception-unwind: frees object |
| 42c350 | `_Unwind_operator_delete` | med | Exception-unwind: frees object |
| 42c3a0 | `_Unwind_dtor_thunk` | med | Exception-unwind cleanup destructor thunk |
| 42c410 | `_Unwind_dtor_thunk` | med | Exception-unwind cleanup destructor thunk |
| 42ee10 | `_Unwind_streambuf_dtor` | med | Exception-unwind: basic_streambuf destructor thunk |
| 42ee40 | `_Unwind_streambuf_dtor` | med | Exception-unwind: basic_streambuf destructor thunk |
| 430ec0 | `_Unwind_operator_delete` | med | Exception-unwind: frees object |
| 45f310 | `sqlite3_value_text16` | med | Returns UTF-16 text of a value (VdbeMemStringify) |
| 45f330 | `sqlite3_value_text16le` | med | Returns UTF-16LE text of a value |
| 45f350 | `sqlite3_value_text16be` | med | Returns UTF-16BE text of a value |
| 45f950 | `sqlite3_minmaxFunc` | med | SQL min()/max(): compares argv via collation and keeps the extreme value |
| 45fb90 | `sqlite3_sourceidFunc` | med | SQL function returning the source-id string |
| 45fd90 | `sqlite3_compileoptionusedFunc` | med | SQL function sqlite_compileoption_used() |
| 45fed0 | `sqlite3_result_value` | med | Sets context result by shallow-copying a Mem value |
| 45ff40 | `sqlite3_result_int_helper` | med | Sets context result to an int (helper for 460810) |
| 460010 | `sqlite3_result_numeric_as_text` | med | Converts a numeric Mem to text result via %!.15g/%!.20e |
| 460810 | `sqlite3_result_int_checked` | med | Coerces a value to int64, checks the size limit, sets int result |
| 4609b0 | `sqlite3_quote_or_blobtext` | med | Serializes a blob/value to text (VdbeMemGrow + hex) |
| 462250 | `sqlite3PcacheSetCachesize` | med | Adjusts page-cache size accounting under mutex (pcache1.c) |
| 4622e0 | `pcache1Shrink` | med | Truncates the page cache and restores count (pcache1.c) |
| 4628d0 | `sqlite3PcachePagecount` | med | Returns the cached page count under mutex |
| 462910 | `memjrnlFileSize` | med | Returns the 64-bit size of the in-memory journal |
| 462eb0 | `minmaxFunc` | med | SQL scalar min()/max(): collation-compare args, copy winning value into result |
| 463630 | `pcacheManageDirtyList` | med | pcache: move page onto dirty list or unlink from hash bucket |
| 463b60 | `ctimeFunc` | med | CURRENT_TIME SQL func trampoline -> datetime backend(ctx,0,NULL) |
| 463be0 | `pcache1RekeyPage` | med | pcache: rehash a page entry from old key to new pgno bucket |
| 463c60 | `cdateFunc` | med | CURRENT_DATE SQL func trampoline -> datetime backend(ctx,0,NULL) |
| 463ce0 | `ctimestampFunc` | med | CURRENT_TIMESTAMP SQL func trampoline -> datetime backend(ctx,0,NULL) |
| 463d00 | `pcache1TruncateUnsafe` | med | pcache: discard cached pages with pgno>=limit |
| 463d50 | `minMaxFinalize` | med | aggregate min/max xFinal: move stored accumulator Mem into result |
| 463e20 | `pcache1Destroy` | med | pcache: free page cache, adjust counters, sqlite3_free |
| 4641e0 | `sqlite3VdbeMemFinalize_aggctx` | med | release aggregate context Mem, run xFinal cleanup, free |
| 464d50 | `winGetLastError` | med | Win32: fetch GetLastError and format message |
| 464d70 | `globFunc` | med | SQL glob(): dispatch to patternCompare (FUN_00470aa0 glob comparator) |
| 464e40 | `likeFunc` | med | SQL like(): dispatch to patternCompare (FUN_00470aa0 like comparator) |
| 465200 | `sqlite3_db_mutex` | med | return db->mutex (db+0xc) |
| 4662c0 | `sqlite_rename_table` | med | ALTER TABLE helper: rewrite SQL replacing table name, quote via %w |
| 466790 | `sqlite3VdbeRecordCompare` | med | compare two Mem-value arrays field-by-field with collation |
| 466b60 | `sqlite_rename_parent` | med | ALTER TABLE helper: rewrite FK parent refs in trigger/view SQL |
| 466e80 | `sqlite3ResetMemHighwater` | med | reset memory-used highwater to current |
| 467000 | `sqlite3_trace` | med | install trace callback (db+0x10c/0x110), expire statements |
| 4672d0 | `sqlite_rename_trigger` | med | ALTER TABLE helper: rewrite trigger body table refs, quote %w |
| 467f40 | `sqlite3_get_autocommit` | med | return db->autoCommit (field+0x24) |
| 467f70 | `sqlite3_declare_vtab` | med | parse CREATE TABLE stmt to declare vtab schema |
| 4689e0 | `sqlite3_vtab_config` | med | configure vtab (CONSTRAINT_SUPPORT) on current VtabCtx |
| 469770 | `sqlite3_column_count` | med | return Vdbe->nResColumn (stmt+0x4c) |
| 4697f0 | `sqlite3_result_error` | med | set error message string on context (computes strlen) |
| 469940 | `sqlite3_bind_parameter_count` | med | return Vdbe->nVar (stmt+0x2c) |
| 469aa0 | `sqlite3_column_text16_exec` | med | fetch column[i] UTF-16 text (enc2) for exec/get_table |
| 469bd0 | `sqlite3_column_text_data` | med | fetch data column[nCol+i] UTF-8 text - get_table body row |
| 469c40 | `sqlite3_column_text16_data` | med | fetch data column[nCol+i] UTF-16 text |
| 46a980 | `last_insert_rowidFunc` | med | SQL last_insert_rowid(): store db->lastRowid into result |
| 46ab70 | `changesFunc` | med | SQL changes(): store db->nChange into result (db+0x48) |
| 46ac30 | `total_changesFunc` | med | SQL total_changes(): store db->nTotalChange into result (db+0x4c) |
| 46b1c0 | `sqlite3_aggregate_count` | med | deprecated: return aggregate row count (ctx pMem->n) |
| 46b260 | `sqlite3_value_blob` | med | return BLOB pointer of a Mem value (force to blob) |
| 46b2b0 | `sqlite3_value_bytes` | med | return byte length of a Mem value |
| 46c6c0 | `analysisLoader` | med | parse sqlite_stat string into index aiRowEst, detect 'unordered' |
| 46c7b0 | `analyzeAggregate` | med | expr walker: register aggregate func/column in NameContext (TK_AGG) |
| 4a6530 | `registerDateTimeFunctions` | med | Insert built-in date/time FuncDefs (base &DAT_00582bc8) into global function hash |
| 4c29b0 | `writeBigEndianToFile` | med | Byte-swap a 32-bit value to big-endian and write it to a file at given offset via xWrite |
| 4d9960 | `Path::moveConstruct` | med | Move-constructs a 0x24-byte object: steals 3-ptr vector [0..8] from source (nulls it), copies 6 tail fields |
| 409270 | `collect_equipped_items` | low | Gather list of relevant equipped item pointers by weapon type (game) |
| 409660 | `check_quest_id_match` | low | True if event type 0x19 and id matches computed value (game) |
| 409d10 | `get_ability_multiplier` | low | Switch ability id -> float multiplier constant (game) |
| 40f8f0 | `get_ability_cooldown` | low | Switch ability id -> cooldown value (game) |
| 411ad0 | `calc_damage_value_b` | low | Damage calc variant with equipment/effect modifiers (game) |
| 414550 | `calc_gem_bonus` | low | Compute gem/rune bonus value by subtype (game) |
| 426c70 | `iterator_base_plus4` | low | Return param+4 (skip node header to value) |
| 426c80 | `iterator_base_plus8` | low | Return param+8 (skip node header to value) |
| 42c6d0 | `_Unwind_nop_thunk` | low | Exception-unwind cleanup stub |
| 45f850 | `sqlite3_context_field_get` | low | Returns a pointer field from context/value (getter) |
| 45f860 | `sqlite3_mem_field8_get` | low | Returns dword at Mem+8 |
| 45f870 | `sqlite3_apivalue_at` | low | Bounds-checked getter of an 8-byte array element |
| 45fce0 | `sqlite3_scalarfunc_valueint` | low | SQL scalar function driven by value_int (zeroblob-like) |
| 45fee0 | `sqlite3_scalarfunc_typename` | low | SQL function mapping a value type to a static type string |
| 4607e0 | `sqlite3_stmt_flag_get` | low | Returns a byte flag from a stmt/db (+0x36) |
| 4607f0 | `sqlite3_deref_or_zero` | low | Returns *ptr, or 0 when ptr is NULL |
| 461310 | `sqlite3_global_config_set` | low | Stores a value into a global config field (DAT_00582b8c) |
| 461610 | `sqlite3_value_serialize` | low | Builds text/blob output from a value (os/date helper; SetFilePointer ref) |
| 461cd0 | `sqlite3_date_init_helper` | low | Initializes a date/time computation struct (memset) |
| 463e00 | `sqlite3_result_error_vprintf` | low | wrapper -> FUN_00476470 formatted result/error with NULL destructor |
| 463f70 | `sqlite3_result_error_vprintf_dtor` | low | wrapper -> FUN_00476470 formatted result with explicit destructor |
| 464d30 | `sqlite3ValueZAccessor` | low | return Mem->z (field+4) when valid (field+0x14 set) |
| 4653d0 | `pcacheConfigControl` | low | dispatch: save/restore config block, page fetch/unpin/rekey/shrink |
| 467ec0 | `sqlite3FieldAccessor20` | low | return u32 field at +0x20 |
| 4683e0 | `sqlite3PrepareTrampoline` | low | thin wrapper -> FUN_004834d0 parse/prepare |
| 468a70 | `btreePageFlagDecode` | low | map btree page flag byte via table 0x56c79b |
| 468f80 | `sqlite3_column_database_name` | low | return column DB name if metadata flag set (col+0x98) |
| 4697a0 | `sqlite3_column_name` | low | return column-name Mem[i] pointer (stmt+0x48) |
| 4697d0 | `btreeMaxLocalCalc` | low | compute ((flags&0x10)\|8)<<8 page cell metric |
| 469f20 | `sqlite3ValueNumericType` | low | return type short at +0x2c when Mem valid |
| 46b1d0 | `sqlite3StmtBusyFlag` | low | return 1 if flag 0x20 at +0x60 set |
| 46b1f0 | `sqlite3VdbeCheckSchema` | low | revalidate cursor/vtab vs schema cookie (FUN_004aac10) |
| 4a0960 | `StrAccumInit_or_ctor` | low | Zero a 5-word object and set its vtable pointer &DAT_00569a48 |
| 4d9b50 | `Path::allocNodeAssign` | low | Allocates node (FUN_004dae90), zeroes color word, stores single value at node+4 |

## game_misc (104)

| addr | proposed name | conf | purpose |
|---|---|---|---|
| 4016f0 | `String_reserveGrow` | high | std::string capacity grow/reallocate with growth policy; copies param_2 bytes to new buffer |
| 401a40 | `String_assign` | high | std::string assign from buffer param_1 of length param_2; grows or reuses SSO buffer |
| 401cd0 | `Matrix4_setIdentity` | high | Initializes a 4x4 float identity matrix (diagonal = 1.0f=0x3f800000) |
| 402510 | `Vec3i64_randomize` | high | Fills 3 int64 slots with 64-bit random values via FUN_0054a946 (RNG) |
| 402550 | `Vec3i64_toFloatScaled` | high | Converts 3 int64 to floats scaled by 1.5258789e-05 (1/65536); fixed-point to float vec3 |
| 402a40 | `Copy24Bytes` | high | Copies 6 dwords (24 bytes) from param_1 to this; vec3-of-int64 or 6-field copy |
| 402c50 | `Vec3i64_subtract` | high | Copies 6 dwords then subtracts param_2's three int64 with borrow; 64-bit vec3 subtract |
| 402cb0 | `Vec3i64_add` | high | Copies 6 dwords then adds param_2's three int64 with carry; 64-bit vec3 add |
| 405450 | `Vec3i64_toBlockCoords` | high | Divides each vec3 int64 component by 0x10000 with floor; fixed-point to integer block coords |
| 406210 | `Grid_lookup1024` | high | Bounds-checked 2D grid lookup (0..0x3ff each); returns dword at this+0xbc+(x*0x400+y)*4 |
| 409de0 | `Combat_getResistFactor` | high | Diminishing-returns factor 1-1/(level*0.1+1) from a resist/level slot, or 1.0 if type unhandled |
| 40f2b0 | `Combat_isSpecialSpiritActive` | high | Predicate: true if this+0xaa8==3 and spirit-state this+0xaa9 in a specific set of ids |
| 40fda0 | `Combat_computeMaxHealth` | high | Computes max HP: 2^a*2^b*base(+0x178) with class/mode multipliers plus per-equipment-slot bonuses |
| 410f00 | `pow2Mul` | high | Helper: returns 2^a * 2^b (two pow calls, product) for stat scaling |
| 410f90 | `pow2MulDiv` | high | Helper: returns 2^a * 2^b / 2^c for stat scaling |
| 411740 | `Combat_upsertBuffEntry` | high | Updates existing buff of same type in list at 0x1178 or appends a new 0x20-byte node; guards list length |
| 412710 | `ostream_writeCString` | high | std::operator<<(ostream&, const char*): pads/writes a C string honoring width/fill, sets state on error |
| 412c40 | `string_dataPtr` | high | std::string data accessor: returns heap buffer *param_1 if capacity(>=0x10) else inline SSO buffer |
| 413070 | `SpeechDb_readBlobByKey` | high | SELECT value FROM blobs WHERE key=?: binds key, steps, copies BLOB into out buffer |
| 413130 | `SpeechDb_loadBlobToVector` | high | Loads a blob by key via readBlobByKey then resizes dest vector and memcpy's the bytes |
| 413710 | `struct_copy0x118` | high | Copies a 0x118-byte record field-by-field (header + 0x20 array of 8-byte entries + tail) |
| 413ce0 | `Combat_equipHealthBonus` | high | Computes a health/stat bonus from an equipment slot (rarity+type), scaled by 2^*5*factor; 0 if slot empty |
| 416930 | `malloc_thunk` | high | Tail-jump thunk to malloc (jumptable via indirect jump) |
| 416950 | `utf32_to_utf16` | high | Converts a UTF-32 buffer to UTF-16: counts units (surrogate pairs for >=0x10000), allocates, converts |
| 4169c0 | `utf_convert_variant` | high | Counts output length (00417890) then allocates and converts a UTF buffer (variant encoding) |
| 416a20 | `std::string::string(string&&)` | high | SSO(16) move-construct std::basic_string<char>, steals heap ptr, resets source |
| 417070 | `encodeUtf16Codepoint` | high | Encodes one Unicode codepoint to UTF-16: direct if <0x10000 else surrogate pair; returns advanced ptr |
| 417680 | `Transcode_dispatch` | high | Dispatches byte-buffer to UTF-16 conversion by encoding id: 1=UTF8,2/5=UTF32,3=UTF16BE,6=UTF16LE swap |
| 417730 | `Utf16BE_byteSwapToNative` | high | Converts UTF-16BE buffer to native by byte-swapping each unit; allocates dest unless param_5 in-place |
| 417790 | `Utf8_toUtf16Alloc` | high | UTF-8 to UTF-16: counts units (FUN_004179e0), allocates buffer, decodes (FUN_00417ae0) |
| 417890 | `Utf32BE_countUtf16Units` | high | Counts UTF-16 units needed for a byte-swapped UTF-32 buffer (2 for >=0x10000 else 1) |
| 4178f0 | `Utf32_toUtf16` | high | Converts UTF-32 (native) buffer to UTF-16 with surrogate encoding |
| 417950 | `Utf32BE_toUtf16` | high | Converts byte-swapped UTF-32BE buffer to UTF-16 with surrogate encoding |
| 4179e0 | `Utf8_countUtf16Units` | high | Counts UTF-16 units for a UTF-8 byte buffer; validates 1-4 byte sequences, ASCII fast-path via word mask |
| 417ae0 | `Utf8_decodeToUtf16` | high | Full UTF-8 to UTF-16 decoder: handles 1-4 byte seqs and surrogate emission, ASCII word fast-path |
| 417e40 | `Xml_detectEncoding` | high | Detects text encoding from BOM and <?xml prefix bytes; returns encoding id (1 UTF8,2/3 UTF16,5/6 UTF32) |
| 418000 | `XmlParse_selectHandler` | high | Returns element-content parse handler fn ptr chosen by bits (param_1>>4)&0xf (8 encoding/normalization variants) |
| 418280 | `Xml_normalizeTextRun` | high | Scans UTF-16 text: normalizes CR/CRLF to LF, resolves entities at '&' (FUN_00419c90), stops at '<' or NUL |
| 418410 | `Xml_parseMainLoop` | high | Core XML tokenizer/parser: walks tags, elements, attributes, dispatches to comment/PI/CDATA handlers via longjmp on error |
| 418ea0 | `Xml_parseCommentOrCData` | high | Parses <!-- comment --> or <![CDATA[ ... ]]> section, optionally creating a node and normalizing content |
| 419210 | `Xml_parseProcInstr` | high | Parses processing instruction / XML declaration <? ... ?>; special-cases 'xml' decl, creates PI node, captures target/data |
| 419ac0 | `Xml_scanCDataContent` | high | Scans CDATA body: normalizes CR/CRLF to LF, terminates at ']]>' (NUL-terminating), returns ptr past terminator or 0 |
| 419ba0 | `Xml_scanCommentContent` | high | Scans comment body: normalizes CR/CRLF to LF, terminates at '-->' (NUL-terminating), returns ptr past terminator or 0 |
| 419c90 | `decodeXmlEntity` | high | Decodes one XML/HTML entity in wide-char string (&#dec; &#xhex; &amp; &apos; &gt; &lt; &quot;) then appends result |
| 41a120 | `Tree_destroyRec_oneStr` | high | Recursively destroys tree nodes freeing one wstring (offset 0x10) per node then the node |
| 41a510 | `Tree_eraseRange_variant` | high | Erases iterator range from map/set (variant using FUN_004d4180 erase-node) |
| 41a9b0 | `SpeechMap_findOrInsert` | high | Lower-bound search by wstring key (via compare) then insert new node; returns iter+bool |
| 41af70 | `QuestTextNode_copyRec` | high | Recursively deep-copies a QuestTextNode subtree including its child map and nested node lists |
| 41b000 | `isPunctuation` | high | Returns true if wide char is one of . : - , ; ! ? / ( ) punctuation marks |
| 41b930 | `copyVec12Range` | high | Copies range of 12-byte (3-dword) elements from [param_1,param_2) into param_3 |
| 41ba90 | `vec12_reallocate` | high | Reallocates 12-byte-element vector to param_1 capacity, copies old elements, frees old buffer |
| 41bb80 | `vec12_reserveGrow` | high | Ensures 12-byte-element vector capacity for param_1 more, computing 1.5x growth |
| 426d30 | `vecInt_reallocate` | high | Reallocates 4-byte-element (int/ptr) vector, memmoves old data, frees old buffer |
| 426eb0 | `vecInt_reserveGrow` | high | Ensures int-vector capacity for param_1 more elements with 1.5x growth policy |
| 4286f0 | `World_getTileAtCoords` | high | Bounds-checks (x,y)<0x2000, locates chunk via /64 then indexes 8x8 subtile (0x68 bytes) returning tile ptr |
| 42c2e0 | `Speech_mapNode_dtor` | high | Destroys Speech map-node payload: clears list (+0x20), frees string (+0x10) and inner list (+0x18), then frees node |
| 42e920 | `vec3b_copyBackward` | high | copy_backward of 3-byte (RGB) elements [first,last)->dest; std::copy_backward |
| 42e960 | `vec3b_uninitCopy` | high | uninitialized_copy of 3-byte (RGB) elements; returns dest end; std::copy |
| 42f250 | `vec3b_reallocate` | high | Reallocates vector of 3-byte elements to capacity param_1, moves via 42e960, frees old; std::vector growth |
| 42f330 | `vec3b_reserveGrow` | high | Ensures vector<3byte> has room for param_1 more (1.5x growth); 'vector<T> too long'; calls 42f250 |
| 45f080 | `vec_ptr_resize` | high | Resizes vector<void*> (4-byte elems) to param_1: shrink via memmove or grow+zero via 426eb0; std::vector::resize |
| 4d1950 | `VoxelGrid::cellAt3D` | high | Bounds-checked accessor into 3D voxel grid returning 0xc-byte cell ptr; returns dummy on OOB |
| 4d8f90 | `VoxelGrid::remapCoords` | high | Applies chunk rotation/mirror (orientation in low 2 bits) to (x,y) grid coords; optional y-flip |
| 4dd090 | `NavGraph::heuristicCost` | high | Weighted manhattan/diagonal distance heuristic from a 3-int delta vector (10/4 weights, x2) |
| 4dd0f0 | `NavGraph::lookupNode` | high | Finds node for 3-int key (x,y,z) in map at this+0x140c; returns value ptr (node+7) or null |
| 4dd1a0 | `NavGraph::addNode` | high | Inserts a graph node keyed by (x,y,z) into map(+0x140c) and open-set(+0x1414); updates best-open pointer |
| 4febd0 | `World::findNearestFeatureCell` | high | Searches a 3x3-ish grid region for the nearest feature/object cell to a point; returns cell coords+ptr |
| 523380 | `pointSegmentDistanceSq` | high | Squared distance from point param_3 to segment [param_1,param_2] (2D), clamped to endpoints |
| 405330 | `World_clearContainers` | med | Resets two rb-trees and a linked list plus calls FUN_004f8520; clears world/zone sub-structures |
| 405f20 | `Column_getBlockChecked` | med | Bounds-checked access into block column array (this+0x18), returns element or sentinel default |
| 405fd0 | `World_getBlockAt` | med | Looks up chunk then block by coords; returns block ptr or sentinel defaults on out-of-range |
| 406050 | `World_getBlockFloat` | med | Floor-divides fixed-point coords by 0x10000 then fetches block via World_getBlockAt |
| 406100 | `Chunk_getColumnAt` | med | Validates world coords in range, resolves chunk (hint or lookup) and returns column ptr |
| 406290 | `Region_getChunkCell` | med | Bounds-checked (0..0xffff) region lookup via grid then returns cell at +0x10018 |
| 406ef0 | `Struct_initWithBuffer0x100` | med | Zero-inits struct and memsets an inner 0x100 buffer; per-slot init template |
| 407cc0 | `mapItemTypeToSlotIndex` | med | Maps an item/equip type opcode to a bonus-slot index (6/7/8) or -1 for unhandled |
| 40fcf0 | `Combat_getStaminaRegenRate` | med | Returns stamina/regen amount = this+0x17c * factor (20/50/60/80) chosen by spirit/flag state |
| 410010 | `Combat_selectNextAttackAnim` | med | Large decision tree selecting the next attack/animation id (char) from class, spirit, weapon state |
| 410290 | `Combat_selectSpiritAttackId` | med | Returns an action/attack id chosen from spirit state, class and a parity of position bits |
| 4128da | `ostream_writeCleanupHandler` | med | Exception-unwind/finally handler for ostream_writeCString: setstate, _Osfx, restore ExceptionList |
| 416ef0 | `Pool_allocBlock` | med | Pool allocator: gets a node sized by param_1 (small vs >0x2000 large lists), links it, returns data ptr (+0x18) |
| 416f80 | `Pool_allocElementNode` | med | Allocates a 0x20-byte node from pool (inline if room in current 0x8000 block else spill), zero-inits, tags with param_2 |
| 417000 | `Pool_mallocAlignedBlock` | med | Requests a memory block (size+0x38) via PTR_FUN_00582198 malloc, aligns to 32 bytes, links into pool chain |
| 417230 | `XmlPool_allocAttrNode` | med | Allocates 0x14-byte attribute node from pool and links into element's attr list (param_1+0x1c) |
| 4172b0 | `XmlPool_allocChildNode` | med | Allocates node via FUN_00416f80 and links as child into parent's child list (param_1+0x10) |
| 417f90 | `Utf16_copyOrPassthrough` | med | UTF-16 native path: in-place (param_5 set) or malloc+memcpy of buffer; sets unit count = bytes>>1 |
| 418ab0 | `Xml_skipDoctypeSubset` | med | Recursively skips DOCTYPE markup/internal subset: nested markup, CDATA (FUN_00418b60), quotes/comments (FUN_00418bd0) |
| 418b60 | `Xml_skipMarkedSection` | med | Recursively skips a nested <![ ... ]]> marked section until matching ']]>' terminator |
| 418bd0 | `Xml_skipQuotedOrComment` | med | Skips a quoted literal, a <?...?> PI, or a <!-- --> comment; errors via longjmp if unterminated |
| 419a80 | `Xml_shiftBufferForNewline` | med | Shifts text buffer left to collapse removed CR bytes (memmove) and advances write cursor by param_2 units |
| 41ab00 | `SpeechMap_insertEach` | med | Traverses a tree in order and calls findOrInsert per node (merge/copy map entries) |
| 4267f0 | `buyNode120` | med | Allocates 0x78-byte list sentinel node, self-links if null args |
| 4268b0 | `buyNode80` | med | Allocates 0x50-byte list node, self-links if null args |
| 4d4d80 | `Creature::moveToward` | med | Computes normalized direction from param_1 to param_2, if within range param_4 calls step/move helper |
| 4d5a80 | `World::sampleTerrainGradient` | med | Computes 2-component terrain gradient/flow from multiple value-noise samples at scaled world coords |
| 4dafe0 | `NavGraph::reconstructPath` | med | Rebuilds a path list by walking predecessor map from goal to start, pushing waypoints; enforces list cap |
| 4dcff0 | `NavGraph::openSetContains` | med | Tests whether a 3-int key (x,y,z) exists in the open-set map at this+0x1414 |
| 4d6730 | `Creature::stepAlongPath` | low | Iterative path/raycast stepping over voxel terrain sampling walkable cells up to 500 iters |
| 4dab60 | `Object::construct6` | low | Trivial 6-field constructor: 3 scalar params + 3 ints from *param_4 |
| 4dd2e0 | `NavGraph::expandNeighbors` | low | A* neighbor expansion: samples random offset, iterates object grid cells, adds reachable neighbor nodes |
| 4dde90 | `NavGraph::findPath` | low | Main A*/pathfinding: pops best open node, expands neighbors, evaluates cost, builds path to goal |
| 522840 | `World_biomeBorderDistance` | low | Computes terrain slope/shading factor at (x,y) sampling neighbor heights via noise; uses point-seg distances |
| 522e20 | `World::waterProximityInfluence` | low | Scans grid region for water/feature cells (type flag==1); accumulates smoothed proximity influence |
| 52ef00 | `Creature::resolveSeparation` | low | Physics separation/collision resolution between two creatures; normalizes overlap and applies push along axis |

## World (34)

| addr | proposed name | conf | purpose |
|---|---|---|---|
| 401060 | `Vec3_copy` | high | Copies 3 dwords (12 bytes) from param_1 into this; vec3/xyz copy assignment |
| 401080 | `Vec3_set` | high | Stores 3 dword args into this+0/4/8; vec3 component setter |
| 4010e0 | `String_ctorFromCStr` | high | std::string ctor from C string; computes strlen then calls assign helper |
| 4013a0 | `String_destroy` | high | std::string clear/free; frees heap buf if capacity>0xf then resets to empty SSO |
| 4013d0 | `getElemPtr4` | high | Returns this + param_1*4; index into dword array |
| 402bc0 | `getField_plus0x10` | high | Returns *param_1 + 0x10 |
| 421e30 | `pair_set2` | high | Stores two dwords into object (constructs a pair/2-field struct) |
| 428070 | `deref_getFirst` | high | Writes **this (first element / head) into param_1 |
| 42ff40 | `vec3b_resize` | high | Resizes vector<3byte> to param_1 elements (shrink erases, grow via 42f330); std::vector::resize; World |
| 46b250 | `noop_return` | high | Empty function; likely alignment/relocation stub; misattributed World |
| 4c8120 | `identity_return` | high | Return the argument unchanged (thunk) |
| 4d5d30 | `valueNoise2D` | high | 2D value/gradient noise with cosine interpolation and integer hash mixing; core terrain noise fn |
| 4d7870 | `World_featureTier` | high | Feature tier from distance-from-spawn-region (sqrt from map center 0x200) |
| 4f8570 | `World_temperatureBlend` | high | Per-column temperature: weighted average over 3x3 warped site window |
| 4f8b40 | `World_humidityBlend` | high | Per-column humidity: weighted average over 3x3 warped site window |
| 50b870 | `World_generateRegionSite` | high | Region-site generator: srand(regX+0x108a+regZ*0x400+base*3); fills 0x1c-byte site record |
| 50e080 | `World_generateRegionFeatures` | high | Per-region 8x8=64 feature-cell generator: srand(base+regZ*0x400+regX) then multi-pass placement |
| 522290 | `World_featureCountRange` | high | Feature-count [min,max] range from site climate floats |
| 522d80 | `World::terrainOffset2D` | high | Returns 2-component fractional terrain offset from two value-noise samples (scaled *3*256) |
| 52c820 | `World::objectFalloffWeight` | high | Distance-based falloff/influence weight of an object over a point, branching on object type (0xb-0xe special) |
| 52dee0 | `World::falloffSquared` | high | Returns (1-w)^2 clamped>=0 where w=objectFalloffWeight; smoothstep-like influence |
| 530550 | `World::getField0` | high | Trivial getter: writes *this to *param_1 |
| 411090 | `formula_inverse` | med | Game curve: (1/(1-x)-1)*20+1 |
| 41d800 | `RefCountedNode::init` | med | Init node: value=param, refcount(+4)=1, weak(+8)=0 |
| 41ebc0 | `readCombatActionFromStream` | med | Deserialize 0x28 record from recv buffer: 5 ints,2 bytes,2 ints,int64 |
| 41ed50 | `readHitFromStream` | med | Deserialize 0x14 record from recv buffer: 2 ints,int,byte,int64 |
| 42e090 | `World_findNearestEntityInRegion` | med | Scans 0x4000-unit region grid cells around (x,y) for entities, picks nearest by distance (522cc0); spatial query |
| 42f9a0 | `World_loadVoxelModel` | med | Loads voxel/model: from file (filebuf/istream read dims+data) or from memory blob; then 430230; World asset load |
| 430230 | `World_buildVoxelMesh` | med | Copies voxel RGB blob to buffer, then per-voxel scans 3 marker colors collecting Vec3i positions into 3 vectors (42feb0) |
| 4d19f0 | `World_roadField` | med | Samples terrain/noise value at world coords via chunk lookup; returns 0 if chunk type!=1 |
| 52cd50 | `World_riverClimateGate` | med | Computes terrain height/elevation at (x,y): base noise + slope + object/vegetation contributions |
| 4f9b70 | `World_baseHeightField` | low | Multi-octave terrain/biome generator: sums value-noise layers, computes climate/height and blends region data |
| 522cc0 | `World_siteDistanceSq` | low | Effectively empty stub; only runs stack-cookie check (cookie xors cancel) |
| 52d990 | `World_waterDepthField` | low | Computes climate/lighting factor at (x,y) from noise, gradient cosine terms, and water proximity |

## CombatBehavior (26)

| addr | proposed name | conf | purpose |
|---|---|---|---|
| 4029b0 | `CombatState_zeroInit` | high | Zero-inits small struct at param_1 (offsets 0,4,8,0x10,0x14) |
| 402a70 | `Struct_copy0x118` | high | Copies ~0x118-byte struct incl 0x20-iteration 8-byte-per-element loop; CombatBehavior state copy |
| 402db0 | `Vec3i64_scaleFixed` | high | Scales 3 int64 components by param (num) then divides by 0x10000; fixed-point vec3 scale |
| 407db0 | `Combat_getAbilityCooldown` | high | Returns cooldown/duration ticks for an ability id: constant/(attackSpeed * this+0x17c); many per-ability constants |
| 4096b0 | `Combat_canCastAbility` | high | Tests if an ability may be used: mana/cost (0040fb20) <= pool this+0x170 and cooldown map slot free; returns bool |
| 40a7a0 | `Combat_mapLowerBound` | high | std::map lower_bound: walks tree comparing key at node+0x10 to *param_2, returns bounding node |
| 40f2f0 | `Combat_getAbilityCastTime` | high | Per-ability cast-time table: constant/(attackSpeed*this+0x17c) with defaults 500/etc |
| 40f650 | `Combat_isRangedOrSpecialOpcode` | high | Predicate: true if action opcode (param_1+100) is in a whitelist of ability ids |
| 40f690 | `Combat_isSpiritChanneling` | high | Predicate: false for certain opcodes/spirit states, else true if spirit 0xaa9 in {0xa,0xb,0xc} |
| 40f710 | `Combat_isMeleeSwingOpcode` | high | Predicate: true when flags&0x1a00==0 and opcode (param_1+100) is one of many melee/attack ids |
| 40fb20 | `Combat_getAbilityResourceCost` | high | Returns resource/proc fraction for an ability id; scans buff list at 0x1178 for tag 9, defaults 0.3 |
| 40fc30 | `Combat_findTopThreatTarget` | high | Walks threat map at 0x13a4, returns (id,id2) pair of entry with highest score at node+6 |
| 410400 | `Combat_updateAttackState` | high | AI tick: computes ability timing, if timer>=windup commits next anim (0040f...) and resets timer |
| 411800 | `Combat_getProjectileSpawnPos` | high | Computes projectile/muzzle world position: rotates offset by yaw (cos/sin) around creature 64-bit coords |
| 411d60 | `Combat_getAbilityRecovery` | high | Per-ability recovery-time table: constant/(attackSpeed*this+0x17c) with many per-id constants |
| 412150 | `Combat_computeAttackSpeed` | high | Computes attack-speed multiplier from class/subclass, health ratio, equipment bonuses and a buff (tag 0xc) |
| 412300 | `Combat_sumEquipAttackBonus` | high | Sums attack-speed/stat bonuses (2^a*2^b/2^c*0.1) across all equipment slots via 00414350 |
| 414350 | `Combat_equipSpeedBonus` | high | Computes attack-speed bonus from an equipment slot; base 0.1/0.2 by type, scaled, min threshold 0.001 |
| 4cfcc0 | `CombatBehavior::areHostile` | high | Faction/hostility predicate between two creatures; returns bool whether they can fight (dueling/PvP flags) |
| 4d5f40 | `CombatBehavior::alertNearbyAllies` | high | On aggro, iterates creature list; for hostile creatures within range sets alert flag(0.5) and enqueues alert msg |
| 402bd0 | `Vec3i64_copyAndScale` | med | Copies 6 dwords then scales the resulting vec3-int64 by param_2/param_3 fraction |
| 4084b0 | `Combat_getWindupAndRecovery` | med | Two-stage per-ability timing: computes windup then recovery ticks via constant/(speed*this+0x17c) (body truncated) |
| 40f5a0 | `Combat_isBlockingState` | med | Predicate over creature action/state fields returning bool in AL (blocking/channel gate) |
| 410690 | `Combat_updateAbilityAndProc` | med | AI tick variant: picks ability (0x290), checks cost/proc, applies timing and buff-list procs (truncated) |
| 4ce9f0 | `CombatBehavior::pushTargetPos` | med | Copies self+param coords into local struct and appends node to a list at param_3+0x58; enforces list length cap |
| 4d6580 | `CombatBehavior::pushAlertMsg` | med | Appends a node (coords payload) to list at this[0], enforcing list size cap 0x7ffffe |

## Speech (26)

| addr | proposed name | conf | purpose |
|---|---|---|---|
| 412f80 | `Speech_scrambleBlob` | high | Obfuscates a byte buffer: table-driven Fisher-Yates-style shuffle then bitwise-NOT each byte |
| 413010 | `SpeechDb_createBlobsTable` | high | Opens sqlite DB (0467f50) and runs CREATE TABLE blobs(key TEXT PRIMARY KEY, value BLOB) |
| 417510 | `Xml_findAttributeByName` | high | Walks node's attribute list (root+0x1c, next at +0x10) comparing wide names (+4); returns matching node or 0 |
| 4175c0 | `Xml_findChildByName` | high | Walks child element list (root+0x10, next at +0x18) comparing wide names (+8); returns matching node or 0 |
| 4180a0 | `Xml_loadAndParse` | high | Top-level XML load: detect encoding, transcode to UTF-16 (FUN_00417680), parse (FUN_004189b0); sets status |
| 4189b0 | `Xml_parseWithSetjmp` | high | Sets stack cookie and setjmp3 error boundary, invokes parser (FUN_00418410), returns {status,count} |
| 41a090 | `SpeechTree_destroyRec` | high | Recursively destroys RB-tree/list nodes, freeing two wstrings per node (offsets 0x10 and 0x04) then node |
| 41a180 | `SpeechMap_eraseRange` | high | Erases iterator range from a map/set, advancing via tree successor and calling erase-node per element |
| 41b050 | `Speech_parseTextToNodes` | high | Parses dialogue text into a QuestTextNode tree, splitting on spaces and {} / [] markup markers |
| 41cba0 | `identityReturn` | high | Returns its argument unchanged (thunk/identity) |
| 428ef0 | `wistream_extractWord` | high | operator>>(wistream, wstring): skips to non-space, reads word chars until whitespace/EOF into string |
| 416b60 | `XmlDoc_ctorInit` | med | Constructor: zeroes first two fields then calls pool init (FUN_004177e0) |
| 416be0 | `Iterator_notEqual` | med | Compares two 8-byte handles (this[0..1] vs param_1[0..1]); returns true if any differ (operator!=) |
| 416c30 | `Iterator_derefAndAdvance` | med | Copies current node handle to out then advances this[0] to next via node+0x18 (linked-list iterator ++) |
| 417590 | `Xml_getFirstChildHandle` | med | Returns handle {value@node+0x10, node} for root's first item, else {0,0} |
| 417640 | `Xml_getFirstTextValue` | med | Scans node children for first CDATA/text node (type 3 or 4) with value; returns its text or empty default |
| 4177e0 | `XmlDoc_initPool` | med | Initializes XML document memory pool: frees prior, allocates aligned 0x8000 block, sets up ring links |
| 417cc0 | `XmlDoc_freePool` | med | Frees XML document pool: releases aux buffer (param_1[1]) and walks/free block chain, clears head |
| 418160 | `Xml_getNodeName` | med | Returns node tag/name pointer (this[0]+8) or empty-string default |
| 41a030 | `QuestTextNode_allocSentinel64` | med | Allocates 0x40-byte node, self-links prev/parent/next pointers, sets +0xc=0x101 (list/tree sentinel head) |
| 42c820 | `Speech_map_insertStringEntry` | med | Builds a Speech map entry (string key + list + strlist via 42b040/42b180) and inserts into map (42a260); dialogue add |
| 4ce990 | `Speech::clear` | med | Resets/clears object: frees buffer if flag&1 set, zeroes 6 indirect pointer targets and length |
| 416c20 | `compareResultToSign` | low | Returns 0 if *param_1 nonzero else -1; trivial predicate |
| 417d30 | `Xml_getRootHandle` | low | Returns handle {0, this[0]}; produces {value=0, docRoot} |
| 417e00 | `Xml_getRootValue` | low | Returns *(this[0]+0x10) (root value) or 0 if no doc |
| 429060 | `wistream_extractWord_ehExit` | low | SEH/exception cleanup tail for extractWord: sets stream state and releases streambuf sentry |

## sqlite (22)

| addr | proposed name | conf | purpose |
|---|---|---|---|
| 460d50 | `sqlite3AttachFunc` | high | ATTACH DATABASE implementation (attach.c) |
| 464420 | `sqlite3_blob_open` | high | public API: open incremental BLOB handle; errors on view/vtab/no column |
| 466210 | `sqlite3_busy_timeout` | high | install default busy handler with timeout ms (db+0x1ac/0x1dc) |
| 467dc0 | `sqlite3_blob_close` | high | close incremental BLOB handle, finalize sub-statement, free |
| 468600 | `sqlite3_wal_autocheckpoint` | high | install default WAL hook with checkpoint page threshold |
| 4687f0 | `sqlite3_errmsg` | high | return UTF-8 error message string for db |
| 46b630 | `fkActionName` | high | return FK action name string (CASCADE/SET NULL/...) for pragma |
| 46c260 | `allocateCursor` | high | vdbe: allocate VdbeCursor slot (0x68 + key/btree space) |
| 46c4b0 | `allocateSpace` | high | btree: allocate/defragment cell space on a page (corruption-checked) |
| 4884b0 | `hash_removeElement` | high | Unlinks a hash element from its list/bucket, frees it, frees table if empty (49d5c0); SQLite |
| 48b940 | `abs32` | high | Integer absolute value handling INT_MIN saturation to INT_MAX; SQLite sqlite3AbsInt32 |
| 45fa30 | `sqlite3_versionFunc` | med | SQL function returning library version string 3.7.15.2 |
| 462e80 | `sqlite3Win32GetDir` | med | Win32 VFS: return directory string ptr for index<3 (CURDIR table) else NULL |
| 465320 | `sqlite3_table_column_metadata` | med | lookup table column, return type/collation/flags or vtab method |
| 4673c0 | `sqlite3BlobReadWrite` | med | incremental BLOB read/write core: seek cell, walk overflow pages |
| 46ca90 | `sqlite3CodeRowTrigger` | med | generate VDBE ops to fire triggers/FK for a column |
| 46cc20 | `fkScanChildren` | med | generate VDBE program to scan child rows for FK constraint check |
| 46b680 | `sqlite3VdbeExpandSqlCopy` | low | copy Vdbe zSql into a Mem and append to expanded row list |
| 46b6f0 | `sqlite3VdbeAppendRow` | low | grow apRow array (nRow +0x30, apRow +0x34) and append value |
| 46b9f0 | `sqlite3ExprBuildBinary` | low | build TK(0x4c) binary Expr from two operands, check tree depth |
| 46c340 | `sqlite3BuildTableInfoBlock` | low | allocate/populate column+sort metadata block for a table ('out of memory') |
| 46c6a0 | `btreePageComputeCellIdx` | low | lazily compute page->pCellIdx pointer (page+0x50) |

## Connection (10)

| addr | proposed name | conf | purpose |
|---|---|---|---|
| 423510 | `Connection_ctor` | high | Constructs Connection: allocates ~13 list/tree sentinel heads of varying node sizes via buynode calls |
| 4239f0 | `Connection_dtor` | high | Destroys Connection: clears and frees all ~13 contained lists/trees and their nodes |
| 428080 | `Connection_destroyNestedLists` | high | Clears a list whose nodes each own an inner list (nested list-of-lists), freeing inner nodes then outer |
| 426830 | `buyNode40` | med | Allocates 0x28-byte list node, self-links if null args |
| 426870 | `buyNode28` | med | Allocates 0x1c-byte list node, self-links if null args |
| 4268f0 | `buyNode24` | med | Allocates 0x18-byte list node, self-links if null args |
| 426930 | `buyNode296` | med | Allocates 0x128-byte list node, self-links if null args |
| 426970 | `buyNode64` | med | Allocates 0x40-byte list node, self-links if null args |
| 4269b0 | `buyNode96` | med | Allocates 0x60-byte list node, self-links if null args |
| 426a30 | `buyNode16` | med | Allocates 0x10-byte list node, self-links if null args |

## Creature (7)

| addr | proposed name | conf | purpose |
|---|---|---|---|
| 401140 | `Creature_zeroInit` | high | Zero-initializes a large Creature struct (~0x890 bytes) storing vtable/type at this+0 |
| 407020 | `Creature_construct` | high | Full Creature constructor: zeroes fields, sets defaults/floats, inits appearance and slot arrays |
| 4076a0 | `Creature_destruct` | high | Creature destructor: frees SSO string, destroys tree/list containers and their nodes |
| 409e60 | `Creature_mapEraseRange` | high | Erases a range [first,last) of nodes from a std::map, rebalancing; clears map when full range |
| 409f20 | `Creature_mapEraseNode_str` | high | Erases one RB-tree node with embedded std::string, rebalances tree, frees string then node |
| 40a430 | `Creature_mapEraseRange_v2` | high | Erases node range from a std::map (variant using 0040a4f0 per-node eraser) |
| 40a4f0 | `Creature_mapEraseNode_vec` | high | Erases one RB-tree node owning a heap vector at [4], rebalances, frees vector then node |

## RandomInteractionBehavior (5)

| addr | proposed name | conf | purpose |
|---|---|---|---|
| 41b9e0 | `RandomBehavior_init` | high | Zero-initializes RandomInteractionBehavior struct, memset 0x100 buffer, sets -1 sentinels and flags |
| 42feb0 | `World_vec3i_pushBack` | high | push_back of Vec3i (12-byte) into vector, growing via 41bb80; misattributed RandomInteractionBehavior |
| 4d4c20 | `RandomInteractionBehavior::findObjectAtPos` | high | Scans structure voxel grids in a zone chunk for a solid cell (==1) whose world AABB contains target xyz |
| 41b900 | `RandomBehavior_listEmplaceCopy` | med | Emplaces a list node then copies a RandomInteractionBehavior payload into it |
| 41b970 | `RandomBehavior_copy` | med | Copies RandomInteractionBehavior: base copy via FUN_00413710 plus fields 0x118-0x12a |

## Server (2)

| addr | proposed name | conf | purpose |
|---|---|---|---|
| 401c00 | `String_erase` | high | std::string erase param_2 chars at pos param_1 via memmove; shrinks length |
| 401920 | `String_replaceRange` | med | std::string replace/assign substring of param_1 into this; handles self-assign and grow |

## Spawn (2)

| addr | proposed name | conf | purpose |
|---|---|---|---|
| 406ad0 | `Creature_initEquipmentSlots` | high | Zero-inits 16 repeated equipment/inventory slot blocks each memset 0x100 with count=1 |
| 406970 | `CreatureAppearance_initDefault` | med | Initializes creature appearance/model defaults incl float scales and 0xffff slot markers |

## QuestText (2)

| addr | proposed name | conf | purpose |
|---|---|---|---|
| 41a670 | `QuestText_assignTree` | med | Rebuilds map/set from another tree: copies node structure then recomputes leftmost/rightmost |
| 42b0e0 | `QuestText_container_copyCtor` | med | Constructs empty container (41a060 head) then copies from param via 41a670; QuestText copy-ctor |

## CompanionBehavior (1)

| addr | proposed name | conf | purpose |
|---|---|---|---|
| 4056c0 | `Vec3_fixedMatMulAcc` | med | Fixed-point multiply of vec by 3 this-components, /0x10000, accumulated; dot/transform |

## Region (1)

| addr | proposed name | conf | purpose |
|---|---|---|---|
| 4f7660 | `Region::ctor` | med | Zero-initializes a ~0x5c-byte Region struct; sets field[9]=1 as only non-zero default |

