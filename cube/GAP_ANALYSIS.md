# Semantic Gap Analysis — cube

Best-effort analysis of functions automation could not name (still `FUN_`), from the
sub-agent audit: proposed name, purpose, confidence, key variables. Inline `[AUDIT]`
comments with the same content are also written above each function in the .cpp files.

**3429 functions analyzed** — confidence: high=1578, med=1172, low=679.

## audit (1121)

| addr | proposed name | conf | purpose |
|---|---|---|---|
| 401000 | `OggPage_continued` | high | libogg ogg_page_continued: returns header byte[5] & 0x01 (continued-packet flag) |
| 401020 | `OggPage_bos` | high | libogg ogg_page_bos: returns header byte[5] & 0x02 (beginning-of-stream flag) |
| 401040 | `OggPage_eos` | high | libogg ogg_page_eos: returns header byte[5] & 0x04 (end-of-stream flag) |
| 401060 | `OggPage_granulepos` | high | libogg ogg_page_granulepos: byte-swaps 64-bit granule position from page header bytes 6..13 |
| 4010f0 | `OggPage_serialno` | high | libogg ogg_page_serialno: returns 32-bit stream serial number at header offset 0x0e |
| 401120 | `OggStream_init` | high | libogg ogg_stream_init: memset state 0x168, allocs body(0x4000)/lacing(0x1000)/granule(0x2000), sets serialno |
| 4011e0 | `OggStream_clear` | high | libogg ogg_stream_clear/destroy: frees body/lacing/granule buffers and zeroes 0x168-byte state |
| 401230 | `OggStream_lacingExpand` | high | libogg _os_lacing_expand: reallocs lacing_vals(*4) and granule_vals(*8) arrays, +0x20 headroom |
| 4012a0 | `OggPage_checksumSet` | high | libogg ogg_page_checksum_set: CRC32 over header+body using table DAT_00745900, writes into bytes 22-25 |
| 4013a0 | `OggSync_buffer` | high | libogg ogg_sync_buffer: compacts returned data, grows storage via malloc/realloc, returns write ptr |
| 401450 | `OggSync_wrote` | high | libogg ogg_sync_wrote: advances fill pointer (+8) by bytes, bounds-checked against storage |
| 401480 | `OggSync_pageseek` | high | libogg ogg_sync_pageseek: scans for 'OggS' (0x5367674f), validates CRC, extracts page header/body |
| 4015c0 | `OggStream_pagein` | high | libogg ogg_stream_pagein: submits page, appends body, expands lacing table, tracks segments/granule |
| 4018f0 | `OggSync_reset2` | high | libogg ogg_sync_reset: zeroes fill/returned/unsynced/headerbytes/bodybytes (offsets 8,c,10,14,18) |
| 401930 | `OggStream_reset` | high | libogg ogg_stream_reset: zeroes body/lacing fill+returned and packet/page counters, pageno=-1 |
| 4019c0 | `OggStream_resetSerialno` | high | libogg ogg_stream_reset_serialno: resets stream then sets new serialno at [0x54] |
| 4019f0 | `OggStream_packetOut_impl` | high | libogg _packetout: extracts/peeks one packet from lacing table, handles 0xff continuation, sets granule/pageno |
| 401b10 | `OggStream_packetout` | high | libogg ogg_stream_packetout: wrapper calling _packetout with advance=1 |
| 401b40 | `OggStream_packetpeek` | high | libogg ogg_stream_packetpeek: peeks next packet without consuming lacing values |
| 4026a0 | `RBTree_insertRebalance` | high | std::_Tree red-black insert fixup: links new node and recolors/rotates to restore invariants |
| 4028d0 | `map_insertUnique` | high | std::map insert: locates position via string-key compare, delegates to hint insert or rebalance |
| 402ac0 | `map_insertHint` | high | std::map hinted insert: descends tree comparing string keys both directions, then links node |
| 4041c0 | `map_insertOrAssignStr` | high | std::map<string,...> insert: finds lower_bound, if key absent constructs node and inserts |
| 4042e0 | `map_findOrInsertEmpty` | high | std::map operator[]-style: finds key or inserts new node with empty value |
| 4050c0 | `RBTreeNode_alloc` | high | std::_Tree node allocator: operator new 0x2c, sets 3 child/parent links to head sentinel |
| 405e10 | `RBTree_eraseRecursive` | high | std::_Tree recursive _Erase: destroys node subtree (left/right) and frees each node+string key |
| 408fc0 | `map_lowerBound` | high | std::map lower_bound over string keys: descends RB-tree returning first not-less node |
| 40c790 | `map_eraseRange` | high | std::map erase/clear: if full range calls recursive tidy, else erases nodes one by one via 40c850 |
| 40c850 | `RBTree_eraseNode` | high | std::_Tree erase single node: unlinks, red-black rebalance, frees node+string key |
| 40eaf0 | `u16string_moveConstruct` | high | MSVC std::u16string/wstring (2-byte) move-construct: moves buffer, copies len/cap, resets source |
| 40eb60 | `u16string_assignCStr` | high | std::u16string::assign(const char16*): computes length then assigns via FUN_0040f7a0 |
| 40ebc0 | `u16string_defaultInit` | high | std::u16string default construct: empty SSO (cap=7,len=0,null) |
| 40f110 | `u16string_move` | high | MSVC std::u16string _Move helper: transfers 2-byte buffer/len/cap, clears source |
| 40f170 | `u16string_grow` | high | std::u16string _Grow/reallocate: new cap (1.5x, max 0x7ffffffe), alloc*2, copy, free old |
| 40f2d0 | `u16string_setEos` | high | std::u16string _Eos: sets length and writes null terminator |
| 40f300 | `u16string_resize` | high | std::u16string::resize/_Grow(bool): grow or truncate, returns len!=0 |
| 40f490 | `u16string_data` | high | std::u16string c_str/data: returns heap ptr if cap>7 else inline |
| 40f680 | `u16string_replaceRange` | high | std::u16string replace/assign(str,pos,len): bounded copy or erase, self-assign fast path |
| 40f7a0 | `u16string_assignPtrLen` | high | std::u16string assign(ptr,len): overlap fast path or realloc+memcpy (2-byte) |
| 411270 | `u16string_erase` | high | std::u16string::erase(pos,count): memmove tail and shrink or truncate |
| 424ba0 | `wostream_insertU16string` | high | operator<<(wostream, u16string&): writes wide string with field-width padding |
| 425330 | `u16string_fillAssign` | high | std::u16string fill helper: writes 2-byte char param_3 param_2 times |
| 425390 | `u16string_append` | high | std::u16string append(count,char16): grows then fills via FUN_00425330 |
| 427a00 | `u16string_equals` | high | std::u16string operator==: returns compare(param_2)==0 |
| 428aa0 | `RBTree_next` | high | std::_Tree iterator increment: descends to leftmost of right subtree / climbs parents |
| 428db0 | `u16string_compare` | high | std::u16string::compare(pos,len,ptr,ptrlen): bounded 16-bit compare, returns <0/0/>0 |
| 42c070 | `std::vector<T16>::size` | high | Returns element count of 16-byte-element vector: (end-begin)>>4 |
| 42c740 | `rbtree::iteratorIncrement` | high | std::_Tree in-order iterator ++ (successor via right subtree / parent walk, +0xd=nil flag) |
| 42ca20 | `rbtree::destroyRec_buf` | high | Recursively frees std::map/set subtree: recurse right(+8), delete node buffer at +0x10, delete node |
| 42ca80 | `rbtree::destroyRec_simple` | high | Recursively frees plain tree subtree (recurse +8, delete node) |
| 42cac0 | `rbtree::rotate` | high | Red-black tree single rotation/rebalance splicing node into parent/child links |
| 4395c0 | `rbtree::allocNode24` | high | operator_new(0x24) self-linked tree node sentinel; _Xbad_alloc on failure |
| 439640 | `wstring::dataPtr` | high | Returns string data pointer (SSO: deref *ECX if capacity ECX[5]>7) |
| 43c870 | `rbtree::allocHead24` | high | operator_new(0x18) self-linked tree head/sentinel, sets flags +0xc=0x101 |
| 43c920 | `rbtree::destroyRec_str` | high | Recursively frees tree subtree freeing each node's SSO string at +0x14 (cap>0xf) then node |
| 43ede0 | `rbtree::eraseNode` | high | std::map/set erase: unlink node, rebalance red-black tree, operator_delete(node) |
| 43f040 | `rbtree::eraseRange_str` | high | Erases [first,last) from tree (Creature map), freeing SSO strings; via 0043f100 per node |
| 43f100 | `rbtree::eraseNode_str` | high | Erase single tree node with rebalance, freeing SSO string at +0x14 (cap>0xf) then node |
| 43f3b0 | `rbtree::eraseRange_buf` | high | Erases [first,last) from tree freeing node buffer at +0x10; via 0043f470 per node |
| 43f470 | `rbtree::eraseNode_buf` | high | Erase tree node with rebalance, freeing heap buffer at +0x10 then node |
| 43f720 | `rbtree::lowerBound` | high | Finds lower-bound tree node by int key at node+4; returns node ptr (or end) |
| 449540 | `zlib::inflateBuffer` | high | Zlib-decompresses [begin,end) into a growable output buffer (inflateInit_ "1.2.3", inflate loop 0x1f400 chunks) |
| 449c00 | `vector_uninitCopy_0x148` | high | Uninitialized copy of [param_1,param_2) into param_3, per-elem string copy via 0042c5e0, stride 0x148 |
| 449cb0 | `vector_destroyRange_0xc` | high | Destroys elements [param_1,param_2) stride 0xc calling 0044aa20, advances param_3 tail |
| 449ce0 | `vector_equal_0x148` | high | Element-wise equality compare of two 0x148-structs vectors (3 int-pairs + floats + byte + ints) |
| 449db0 | `rbtree_insertRebalance_0x148node` | high | STL _Tree insert fixup: recolor/rotate red-black tree after inserting node param_5; may throw len_error via delete |
| 449fe0 | `map_insertUnique_findPos` | high | std::map insert_unique: locate hint position with comparator 0044b5a0 then call rebalance 00449db0 |
| 44a1a0 | `map_lowerBoundInsert_strKey` | high | Descends tree comparing int+string key (memcmp 0040c590) to find insert slot, then 00449db0 |
| 44a3c0 | `vector_uninitCopy_0x11c` | high | Uninitialized copy of [param_1,param_2) stride 0x11c, first dword + string copy via 0042c5e0 |
| 44a410 | `vector_destroyRange_0xc_seh` | high | Destroys 0xc-stride range calling 0044a700 with SEH cleanup, returns advanced tail |
| 44a4b0 | `vector_uninitCopy_0x11c_ee70` | high | Uninitialized copy stride 0x11c, first dword + string move/copy via 0040ee70, null-dest guarded |
| 44a500 | `vector_defaultInit_0x11c` | high | Default-constructs param_2 elements stride 0x11c: zero header, set field +0xc=1, memset 0x100 buffer |
| 44a580 | `vector_uninitCopy_0x14` | high | Uninitialized copy of 0x14-byte (5-dword) elements [param_1,param_2)->param_3 |
| 44a600 | `vector_uninitCopy_0x11c_ee70b` | high | Uninitialized copy stride 0x11c via 0040ee70, guarded dest, twin of 44a4b0 |
| 44a650 | `vector_uninitCopy_0x148_a8c0` | high | Uninitialized copy of 0x148-elements calling 0044a8c0 per element |
| 44a700 | `vector_copyAssign_0x11c` | high | Copy-assign vector<0x11c>: reserve via 0044b5f0 then uninit-copy via 0044a4b0 |
| 44aa20 | `vector_assignFrom_0x11c` | high | Assign vector<0x11c> from another: reuse/grow buffer and uninit-copy via 0044a600/0044a3c0 |
| 44abb0 | `vector_assignFrom_0x148` | high | Assign vector<0x148> from another: grow via 0044b660 and copy via 00449c00/0044a650 |
| 44ad30 | `vector_assignFrom_0xc` | high | Assign vector<0xc> from another (0044a410/00449cb0/00639cf0), grow via 0044b6d0 |
| 44b560 | `vector_at_0x188` | high | Returns element pointer: param_1*0x188 + *ecx |
| 44b580 | `vector_pushBackSlot_0x148` | high | Returns current end and advances *ecx by 0x148 (emplace slot) |
| 44b5f0 | `vector_buyAlloc_0x11c` | high | vector _Buy: allocate param_1*0x11c, set begin/end/cap; throws length/bad_alloc |
| 44b660 | `vector_buyAlloc_0x148` | high | vector _Buy: allocate param_1*0x148 buffer; throws length/bad_alloc |
| 44b6d0 | `vector_buyAlloc_0xc` | high | vector _Buy: allocate param_1*0xc buffer; throws length/bad_alloc |
| 44b740 | `list_allocSentinel_0x48` | high | Allocates 0x48 list sentinel node, self-links prev/next, sets color bytes 0x101 |
| 44b830 | `vector_growCap_0x148` | high | Capacity growth calc (1.5x, clamp max) for vector<0x148> |
| 44b920 | `vector_reallocInsert_0x14` | high | Reallocate vector<0x14> to param_1 capacity, move-copy via 0044a580, free old |
| 44ba10 | `vector_reallocInsert_0x11c` | high | Reallocate vector<0x11c> to new capacity, move via 0044a600, free old |
| 44bb10 | `vector_reallocInsert_0x148` | high | Reallocate vector<0x148> to new capacity, move via 0044a650, free old |
| 44bc10 | `vector_reserveGrow_0x14` | high | Ensure capacity>=param_1 for vector<0x14>, computes 1.5x growth, calls realloc 0044b920 |
| 44bcc0 | `vector_reserveGrow_0x11c` | high | Ensure capacity for vector<0x11c>, 1.5x growth via 00594840, realloc 0044ba10 |
| 44bd30 | `vector_reserveGrow_0x148` | high | Ensure capacity>=param_1 for vector<0x148>, 1.5x growth, realloc 0044bb10 |
| 44be20 | `vector_clear` | high | Clear: set end (ecx[1]) = begin (*ecx) |
| 44d460 | `list_pushBack_0x48` | high | std::list push_back node via 0044449b70; throws list too long at 0xe38e37 |
| 44d4b0 | `vector_insertSelfaware_0x14` | high | push_back one 0x14 element handling self-referential source, grows via 0044bc10 |
| 44d590 | `vector_pushBack_0x148` | high | push_back one 0x148 element via 0044a8c0, grows via 0044bd30 |
| 44d660 | `vector_resize_0x11c` | high | Resize vector<0x11c> to param_1: shrink (0044a3c0) or grow (0044bcc0+default 0044a500) |
| 44e890 | `vector_size_0x188` | high | Returns element count (end-begin)/0x188 |
| 451850 | `wstring_ctorAppend` | high | std::wstring ctor+append: init SSO(cap 7), reserve, append via 0046f270/0046f170 |
| 451c70 | `map_insertVal_5x64payload` | high | Insert map value via 0046d850, copy 5x undefined8 payload (0x28 bytes) at node+8 |
| 451cc0 | `map_insertVal_strPayload` | high | Insert map value via 0046d6d0, copy 2 dwords + string (0040ee70) at node+8 |
| 451d00 | `map_insertVal_3x64payload` | high | Insert map value via 00439600, copy 3x undefined8 (0x18) at node+8 |
| 451d40 | `map_insertVal_465c00` | high | Insert map value via 0046d750, construct payload via 00465c00 |
| 451d70 | `map_insertVal_4594c0` | high | Insert map value via 0043c8a0, construct payload via 004594c0 |
| 451da0 | `map_insertVal_4595b0` | high | Insert map value via 0046d5d0, construct payload via 004595b0 |
| 451e80 | `map_insertVal_0x18payload` | high | Insert map value via 0046d650, copy 3 dwords + 4 bytes + dword at node+8 |
| 451ee0 | `map_insertVal_4599a0` | high | Insert map value via 0046d810, construct payload via 004599a0 |
| 451f10 | `map_insertVal_1val` | high | Insert map value via 0046d690, copy 1 dword + string (0040ee70) |
| 451f50 | `map_insertVal_4591b0` | high | Insert map value via 0046d590, copy 2 dwords + payload via 004591b0 (SEH) |
| 451ff0 | `map_insertVal_12dword` | high | Insert map value via 0046d710, copy 12 dwords (0x30) payload at node+8 |
| 452060 | `map_insertVal_00468670` | high | Insert map value via 0046d790, copy 3 dwords + payload via 00468670 |
| 4520a0 | `map_insertVal_00465ce0` | high | Insert map value via 0046d7d0, construct payload via 00465ce0 |
| 4520d0 | `map_insertVal_00465e60` | high | Insert map value via 0046d810, construct payload via 00465e60 |
| 452100 | `map_insertVal_00466410` | high | Insert map value via 0046d890, construct payload via 00466410 (SEH) |
| 452190 | `map_insertVal_0044a8c0` | high | Insert map value via 0046d8d0, construct 0x148 payload via 0044a8c0 |
| 4521c0 | `map_insertVal_strKey` | high | Insert map value via 00439600, init SSO string key then assign via 0040f680 (SEH) |
| 452470 | `vector_uninitCopy_0x11c_5e0` | high | Uninit copy stride 0x11c: string via 0042c5e0 + dword +0x118 |
| 4524c0 | `list_copyRange_004572c0` | high | Copy list-node range stride 2 dwords via 004572c0 (per-node copy) |
| 452540 | `rbtree_copyRecursive` | high | Recursive RB-tree copy (_Copy): clone node via 00451bf0, recurse left/right |
| 452690 | `vector_insertRangeFromList_0x10` | high | Insert list range into vector<0x10>: grow (0046dd00) + copy nodes (00456ba0/00456d60) |
| 452840 | `vector_insertRangeFromList_0x148` | high | Insert list range into vector<0x148>: grow (0044b830/0044bde0) + copy (0044a650/00456bf0) |
| 452a10 | `rbtree_insertRebalance_A` | high | RB-tree insert fixup variant, size limit 0xaaaaaa8 (node 0x18 key type) |
| 452c20 | `rbtree_insertRebalance_mapset` | high | RB-tree insert fixup, throws map/set too long at 0x3fffffd, cleanup via 0046db10 |
| 453040 | `map_insertHint_intKey` | high | std::map insert with hint for int key at +4: validates hint then rebalance 00452a10 or 004538c0 |
| 453230 | `map_insertHint_strKey` | high | Insert with hint for string key: compare via 00428db0, rebalance 00452c20 or 004539e0 |
| 453420 | `map_insertHint_2intKey` | high | Insert with hint for 2-int (64-bit) key at +4/+5: compares via 0042c8d0, rebalance 005c0420 |
| 4538c0 | `map_lowerBoundInsert_intKey` | high | Descend tree by int key (+4) to insert slot, then rebalance 00452a10 |
| 4539e0 | `map_lowerBoundInsert_strKey` | high | Descend tree by string key comparing via 00428db0, insert via 00452c20 or return dup |
| 453b40 | `map_lowerBoundInsert_2intKey` | high | Descend by 2-int key (+4/+5) to insert slot, rebalance 005c0420 |
| 453de0 | `map_findOrInsert_2intKey` | high | lower_bound by 2-int key returning existing node or new insert (00665d30) |
| 453f20 | `list_assignRange_00608a20` | high | std::list assign: push each [param_2,param_3) node via 00608a20; throws at 0xaaaaaa9 |
| 453ff0 | `list_assignRange_00451da0` | high | std::list assign copying via 00451da0; throws at 0x2222221 |
| 4540c0 | `list_assignRange_00451ee0` | high | std::list assign copying via 00451ee0; throws at 0x3333332 |
| 454260 | `list_assignRange_004e0300` | high | std::list assign copying via 004e0300; throws at 0x5555554 |
| 454330 | `list_assignRange_00452190` | high | std::list assign copying via 00452190; throws at 0xc30c2f |
| 454400 | `list_assignRange_004cb5a0` | high | std::list assign copying via 004cb5a0; throws at 0xffffffe |
| 4544d0 | `list_assignRange_00451c70` | high | std::list assign copying via 00451c70; throws at 0x5555554 |
| 4545a0 | `list_assignRange_00451e80` | high | std::list assign copying via 00451e80; throws at 0x9249248 |
| 454670 | `list_assignRange_00451f50` | high | std::list assign copying via 00451f50; throws at 0xaaaaaa9 |
| 454740 | `list_assignRange_00451cc0` | high | std::list assign copying via 00451cc0; throws at 0xdd67c7 |
| 454810 | `list_assignRange_00451d40` | high | std::list assign copying via 00451d40; throws at 0x3fffffe |
| 4548e0 | `list_assignRange_00452060` | high | std::list assign copying via 00452060; throws at 0x2aaaaa9 |
| 4549b0 | `list_assignRange_004520d0` | high | std::list assign copying via 004520d0; throws at 0x3333332 |
| 454a80 | `list_assignRange_0058d860` | high | std::list assign copying via 0058d860; throws at 0x7fffffe |
| 454b50 | `introsort_insertionPass_0x128` | high | Insertion-sort pass for 0x128 elements keyed by byte+short*6, moves via 0042c5e0/00468050 |
| 455c30 | `introsort_0x128` | high | Introsort for 0x128 elements: quicksort (00456160) + heapsort fallback (00455fb0) + insertion |
| 455e70 | `introsort_0xc` | high | Introsort for 0xc elements: partition 00456710 + heapsort 004560c0 fallback |
| 455fb0 | `heapSort_0x128` | high | Heapsort loop popping 0x128 elements via 00455760 |
| 4560c0 | `heapSort_0xc` | high | Heapsort loop for 0xc elements via sift 00451b10 |
| 4569f0 | `vector_uninitCopy_0x11c_guarded` | high | Uninit copy stride 0x11c via 0040ee70 + dword +0x118, dest-null guarded |
| 456a40 | `vector_destroyRange_8_seh` | high | Destroy 8-byte-stride range via 00459110 with SEH |
| 456ba0 | `list_copyNodesToArray_0x10` | high | Copy list-node payloads (+2..+5) into 0x10 array elements |
| 456bf0 | `vector_destroyListRange_0x148` | high | Walk list nodes destroying 0x148 payloads (+2) via 0044a8c0 |
| 456c30 | `vector_uninitCopy_0x11c_g2` | high | Uninit copy stride 0x11c via 0040ee70 + dword +0x118 (twin 4569f0) |
| 456c80 | `vector_destroyRange_0xc_seh2` | high | Destroy 0xc-stride range via 0044a700 with SEH |
| 456d60 | `list_copyNodesToVector_0x10` | high | Copy list-node payloads into 0x10-byte vector elements (dword + 3 dwords) |
| 456dc0 | `vector_destroyRange_0x128_seh` | high | Destroy 0x128 range via 0040ee70 + 004592f0 with SEH |
| 4570a0 | `list_assignReuse_005c03f0` | high | std::list assign reusing existing nodes then push extras via 005c03f0; throws at 0x38e38e2 |
| 4571d0 | `list_assignReuse_00449b70` | high | std::list assign reusing nodes (0042c5e0 payload) then push via 00449b70; throws at 0xe38e37 |
| 4572c0 | `list_assignReuse_004e0300` | high | std::list assign reusing nodes (payload +8..+0xb, string +2) via 004e0300; throws 0x5555554 |
| 4579c0 | `map_eraseNode_004dc5b0` | high | Erase RB-tree node (004dc5b0) returning successor into param_1 |
| 457a10 | `map_eraseNode_004544d0` | high | Erase RB-tree node via 004544d0 returning successor |
| 457a60 | `vector_eraseElem_0x10` | high | Erase 0x10 element (00452690), return adjusted iterator |
| 457a90 | `map_eraseNode_004dc4e0` | high | Erase RB-tree node via 004dc4e0 returning successor |
| 457b30 | `map_eraseNode_004545a0` | high | Erase RB-tree node via 004545a0 returning successor |
| 457bd0 | `map_eraseNode_00454670` | high | Erase RB-tree node via 00454670 returning successor |
| 457c20 | `map_eraseNode_00454740` | high | Erase RB-tree node via 00454740 returning successor |
| 457c70 | `map_eraseNode_00454810` | high | Erase RB-tree node via 00454810 returning successor |
| 457cc0 | `map_eraseNode_004548e0` | high | Erase RB-tree node via 004548e0 returning successor |
| 457d10 | `map_eraseNode_004549b0` | high | Erase RB-tree node via 004549b0 returning successor |
| 457d60 | `map_eraseNode_00454a80` | high | Erase RB-tree node via 00454a80 returning successor |
| 457db0 | `vector_eraseElem_0x148` | high | Erase 0x148 element (00452840), return adjusted iterator |
| 458ba0 | `sortEntry_introsort_0xc` | high | Entry to introsort_0xc computing depth limit (n) |
| 458e90 | `std::list_copyConstruct_nodeSz18` | high | SEH-guarded list copy-ctor: alloc sentinel node via _Buynode(0x18) then copy-range from source |
| 459110 | `std::list_copyConstruct_nodeSz30` | high | SEH-guarded list copy-ctor: alloc sentinel via _Buynode(0x30) then copy elements |
| 4591b0 | `std::list_copyConstruct_nodeSz150` | high | SEH-guarded list copy-ctor: alloc sentinel via _Buynode(0x150) then copy elements |
| 459250 | `std::list_copyConstruct_nodeSz_ccbf0` | high | SEH-guarded list copy-ctor via FUN_004ccbf0 node alloc; class=WorldInfo likely misattrib STL |
| 4592f0 | `std::vector_assign_stride11c` | high | Vector copy-assign, element size 0x11c: reserve via FUN_0044b5f0 then copy-construct range |
| 4593e0 | `std::vector_assign_stride0c` | high | Vector copy-assign, element size 0xc: reserve via FUN_0044b6d0 then copy range |
| 459490 | `std::vector_ctor_fillFrom` | high | Zero 3-ptr vector header then fill via FUN_0046da00(count,src) |
| 467a70 | `list_dtor_freeHeadAt8` | high | Destroy list at +8: unlink sentinel and operator_delete nodes |
| 467b60 | `list_dtor_freeHeadAt51a0` | high | Destroy list at +0x51a0 and delete nodes |
| 467c40 | `u16string_clear_off38` | high | Clear SSO wide string at +0x38 (free if cap>7, reset cap=7) |
| 467c70 | `list_dtor_freeHeadAt60` | high | Destroy list at +0x60: unlink sentinel and delete nodes |
| 467f10 | `Vector_storeElementAt20` | high | Write *param_1 into buffer[+0x4c][idx +0x20]*4, return slot ptr |
| 467f60 | `Vector_end_stride18_freeStr` | high | Return end() of stride-0x18 vector; free trailing string if not tail |
| 467fa0 | `u16string_moveClear` | high | Clear wide SSO string at this (cap7) then FUN_0040f110 if src differs |
| 468000 | `u16string_assignFromWide` | high | Assign wchar string: compute length then FUN_0040f7a0 assign |
| 468050 | `std::vector_copyAssign_stride11c` | high | Vector copy-assign stride 0x11c with grow/reuse via FUN_0044b5f0/FUN_004569f0 |
| 4681e0 | `std::vector_copyAssign_vecElem8` | high | Vector-of-vectors copy-assign, elem 8B, destroys old via FUN_0046dac0 |
| 468310 | `std::vector_copyAssign_elem8_b` | high | Vector copy-assign elem 8B with FUN_00639c50 copy and FUN_00456f70 range |
| 468430 | `std::vector_copyAssign_stride18` | high | Vector copy-assign stride 0x18 (destroy via FUN_00452650, copy FUN_00456ae0) |
| 468c60 | `vector_at_stride4` | high | Return element ptr *this + index*4 |
| 468c70 | `vector_at_stride8` | high | Return element ptr *this + index*8 |
| 468d30 | `list_popFront_node` | high | Pop node: *param_1=head, *this=head->next |
| 46d440 | `std::vector_reserveAlloc_stride8` | high | Allocate vector storage stride 8; throws _Xlength_error/_Xbad_alloc |
| 46d4b0 | `rbtree_allocHeaderNode_1c` | high | operator_new(0x1c) header node, self-link ptrs, set color/flag word 0x101 |
| 46d520 | `rbtree_allocHeaderNode_28` | high | operator_new(0x28) header node, self-link, flags 0x101; class QuestText likely misattrib |
| 46d550 | `list_buyNode_0c` | high | operator_new(0xc) list node, set next/prev |
| 46d590 | `list_buyNode_18` | high | operator_new(0x18) list node, set next/prev |
| 46d5d0 | `list_buyNode_78` | high | operator_new(0x78) list node |
| 46d610 | `list_buyNode_28` | high | operator_new(0x28) list node |
| 46d650 | `list_buyNode_1c` | high | operator_new(0x1c) list node |
| 46d690 | `list_buyNode_124` | high | operator_new(0x124) list node |
| 46d6d0 | `list_buyNode_128` | high | operator_new(0x128) list node |
| 46d710 | `list_buyNode_38` | high | operator_new(0x38) list node |
| 46d750 | `list_buyNode_40` | high | operator_new(0x40) list node |
| 46d790 | `list_buyNode_60` | high | operator_new(0x60) list node |
| 46d7d0 | `list_buyNode_c0` | high | operator_new(0xc0) list node |
| 46d810 | `list_buyNode_50` | high | operator_new(0x50) list node |
| 46d850 | `list_buyNode_30` | high | operator_new(0x30) list node |
| 46d890 | `list_buyNode_68` | high | operator_new(0x68) list node |
| 46d8d0 | `list_buyNode_150` | high | operator_new(0x150) list node |
| 46d910 | `rbtree_buyNode_copyKey20` | high | operator_new(0x20) node, init 3 ptrs from *this |
| 46d990 | `rbtree_buyNode_copyKey18` | high | operator_new(0x18) node, init 3 ptrs from *this |
| 46d9d0 | `Node_alloc_thenInit` | high | Allocate node via FUN_0046d7d0 then init defaults FUN_00465de0 if valid |
| 46da00 | `vector_fill_pairElem` | high | Reserve then fill vector with param_1 copies of 2-dword element param_2 |
| 46dac0 | `vector_destroyRange_strings` | high | Destroy string-owning elements FUN_0046f990 then delete backing |
| 46dbc0 | `rbtree_destroyRecursive` | high | Recursively destroy RB-tree: recurse left child +8, free 2 strings, delete node |
| 46dcc0 | `vector_growCap_stride4` | high | Compute new capacity (1.5x growth) for stride-4 vector |
| 46dd00 | `vector_growCap_stride16` | high | Compute 1.5x growth capacity for stride-0x10 vector |
| 46dd40 | `vector_growCap_stride128` | high | Compute 1.5x growth capacity for stride-0x128 vector |
| 46dde0 | `vector_growCap_stride18` | high | Compute 1.5x growth capacity for stride-0x18 vector |
| 46e710 | `vector_resizeGrow_stride128` | high | Ensure capacity for stride-0x128 vector, delegate to realloc |
| 46e800 | `vector_reserve_stride8` | high | Reserve capacity for stride-8 vector (1.5x or exact) |
| 46e8f0 | `vector_reserve_stride8_b` | high | Reserve capacity for stride-8 vector (variant) |
| 46ea70 | `vector_destroy_stringElems` | high | Destroy string-owning vector elements then free backing |
| 46ef60 | `std::string_replace_char` | high | Narrow-string replace(pos,len,append): bounds-check, grow, memcpy |
| 46f050 | `std::string_append_char` | high | Narrow-string append/insert with overlap check and grow |
| 46f170 | `std::u16string_replace` | high | Wide-string replace(pos,len): bounds-check, grow via FUN_0040f170, memcpy*2 |
| 46f270 | `std::u16string_append` | high | Wide-string append with overlap detection and grow |
| 46f870 | `list_clearSingleNode` | high | Reset list head and free single owned node |
| 46f910 | `list_clearNestedList` | high | Clear list head, then clear nested list at +0x10 of freed node and delete |
| 46fa50 | `list_eraseTail_stringNode` | high | Erase tail string-owning node from list via FUN_0046f990 |
| 477240 | `vector_empty` | high | Return begin==end (*this==this[1]) |
| 477250 | `u16string_endIterator` | high | Write end pointer of wide SSO string to param_1 |
| 477b80 | `list_eraseNode_front` | high | Erase list node (front): unlink, free string at +4, delete |
| 477c60 | `list_eraseNode` | high | Unlink and delete single list node if not head |
| 477cb0 | `list_eraseNode_stringField` | high | Erase list node, free SSO string at +0x10 (cap +0x15), delete |
| 477d90 | `rbtree_lowerBound_pairKey` | high | RB-tree lower_bound by (x,y) pair key; return matching node or header |
| 47f000 | `map_getPairValue` | high | Fetch entry via FUN_00453de0(key), copy dword+byte to param_1 |
| 486030 | `list_popFront` | high | Pop front node via FUN_00477b80 on list at *this+4 |
| 486080 | `list_clearFrontNode` | high | Unlink and delete front node of list at *this |
| 4860b0 | `list_pushBack_via583cb0` | high | Append node (FUN_00583cb0), inc size, cap 0x15555554 |
| 486100 | `list_pushBack_via451d70` | high | Append node (FUN_00451d70), inc size, cap 0xd4c77a |
| 486150 | `list_pushBack_via451d00` | high | Append node (FUN_00451d00), inc size, cap 0x7fffffe |
| 4861a0 | `list_pushBack_via451da0` | high | Append node (FUN_00451da0), inc size, cap 0x2222221 |
| 486240 | `list_pushBack_via451e80` | high | Append node (FUN_00451e80), inc size, cap 0x9249248 |
| 486290 | `list_pushBack_via451ee0` | high | Append node (FUN_00451ee0), inc size, cap 0x3333332 |
| 4862e0 | `list_pushBack_via5c03f0` | high | Append node (FUN_005c03f0), inc size, cap 0x38e38e2 |
| 486330 | `list_pushBack_via451f50` | high | Append node (FUN_00451f50), inc size, cap 0xaaaaaa9 |
| 4863d0 | `list_pushBack_via451ff0` | high | Append node (FUN_00451ff0), inc size, cap 0x4924923 |
| 486420 | `list_pushBack_via451d40` | high | Append node (FUN_00451d40), inc size, cap 0x3fffffe |
| 486470 | `list_pushBack_via4520d0` | high | Append node (FUN_004520d0), inc size, cap 0x3333332 |
| 4864c0 | `std::list_insert_node_32` | high | Appends a node to a std::list via FUN_0058d860; enforces 0x7fffffe length cap; splices tail sentinel |
| 486510 | `std::list_insert_node_a` | high | Appends node to std::list via FUN_00452100; length cap 0x2762761; class=GameController is STL misattribution |
| 486560 | `std::list_insert_node_b` | high | Appends node to std::list via FUN_004cb5a0; length cap 0xffffffe |
| 486600 | `std::vector_insert_one_296` | high | Inserts one 296-byte (0x128) element into vector; grows via FUN_0046e710; SEH-guarded copy/move |
| 486700 | `std::vector_insert_one_284` | high | Inserts one 284-byte (0x11c) element into a vector; grows via FUN_0044bcc0 |
| 486780 | `std::vector_insert_one_8_seh` | high | Inserts one 8-byte element into vector; grows via FUN_0046e800; SEH frame |
| 4868d0 | `std::vector_insert_one_8b` | high | Inserts one 8-byte element (two dwords) into vector; grows via FUN_005fbc10 |
| 4869d0 | `std::list_insert_node_c` | high | Appends node to std::list via FUN_004520a0; length cap 0x1555554 (24-byte payload) |
| 486d00 | `std::wstring_replace` | high | std::wstring::replace: bounds-checked 2-byte-char splice with memmove/memcpy; throws string too long/invalid position |
| 4870f0 | `std::list_resize` | high | Resizes std::list to param_1: appends nodes (FUN_0046d9d0) or erases from front; cap 0x1555554 |
| 487380 | `std::vector_resize_12` | high | Resizes a 12-byte-element vector: shrink via FUN_006413b0 or grow via FUN_0063ddc0/FUN_00427a80 |
| 487f50 | `std::vector_size_4` | high | Returns element count of 4-byte-element vector: (end-begin)>>2 |
| 487f60 | `std::vector_size_8` | high | Returns element count of 8-byte-element vector: (end-begin)>>3 |
| 487ff0 | `std::string_ctor_wrap` | high | Initializes an SSO std::string (cap 0xf, len 0) then delegates to FUN_0040c0a0 |
| 4a8f90 | `push_heap_ptr_key6c` | high | push_heap sift for pointer array keyed by float at +0x6c |
| 4a9030 | `push_heap_12_key4` | high | push_heap sift-down/up for 12-byte elements keyed by float at +4 |
| 4a9110 | `push_heap_16_key8` | high | push_heap for 16-byte elements keyed by float at +8 |
| 4a9200 | `adjust_heap_48_key28` | high | Heap sift-down for 48-byte elements keyed float at +0x28; finishes via push_heap FUN_004aa160 |
| 4a96b0 | `make_heap_ptr_key6c` | high | make_heap over pointer array keyed by float at +0x6c |
| 4a9790 | `make_heap_12_key4` | high | make_heap over 12-byte elements keyed by float at +4 |
| 4a98d0 | `make_heap_16_key8` | high | make_heap over 16-byte elements keyed by float at +8 |
| 4a9a00 | `make_heap_48_key28` | high | make_heap over 48-byte elements keyed float at +0x28; copies elem via local_38 buffer |
| 4aa160 | `push_heap_up_48` | high | Heap sift-up for 48-byte element (percolate hole to root) copying 11 dwords |
| 4aa260 | `introsort_ptr_key6c` | high | Introsort (quicksort+heapsort+insertion) of pointer array keyed float+0x6c; recursion depth param_3 |
| 4aa350 | `introsort_12_key4` | high | Introsort of 12-byte elements keyed float+4 |
| 4aa490 | `introsort_16_key8` | high | Introsort of 16-byte elements keyed float+8 |
| 4aa580 | `introsort_48_key2c` | high | Introsort of 48-byte elements keyed float+0x2c |
| 4aa6c0 | `heapsort_finish_ptr` | high | Pop-heap loop (sort_heap) finishing pointer-array introsort |
| 4aa720 | `heapsort_finish_12` | high | sort_heap finish for 12-byte elements |
| 4aa7c0 | `heapsort_finish_16` | high | sort_heap finish for 16-byte elements |
| 4aa840 | `heapsort_finish_48` | high | sort_heap finish for 48-byte elements; SEH cookie |
| 4ab870 | `uninitialized_copy_16` | high | Copies a range of 16-byte elements into raw storage (vector realloc helper) |
| 4ab8b0 | `uninitialized_copy_48` | high | Copies a range of 48-byte elements into raw storage |
| 4ab940 | `std::list_assign` | high | Assigns/copies contents from [param_1,param_2) into this list, reusing nodes then appending; 'list<T> too long' |
| 4aba70 | `std::sort_ptr_key6c` | high | std::sort entry for pointer array keyed float+0x6c (seeds introsort depth) |
| 4aba90 | `std::sort_12_key4` | high | std::sort entry for 12-byte elements |
| 4abac0 | `std::sort_16_key8` | high | std::sort entry for 16-byte elements |
| 4abae0 | `std::sort_48_key2c` | high | std::sort entry for 48-byte elements |
| 4abc10 | `vector_at_48` | high | Returns *this + param_1*0x30 (48-byte element address) |
| 4abcc0 | `std::vector_realloc_12` | high | Reallocates 12-byte-element vector to param_1 capacity; moves elements, frees old |
| 4abdb0 | `std::vector_realloc_16` | high | Reallocates 16-byte-element vector; moves via FUN_004ab870 |
| 4abe90 | `std::vector_realloc_48` | high | Reallocates 48-byte-element vector; moves via FUN_004ab8b0 |
| 4abf80 | `std::vector_reserve_12` | high | Ensures capacity for 12-byte-element vector (1.5x growth); 'vector<T> too long' |
| 4ac020 | `std::vector_reserve_16` | high | Ensures capacity for 16-byte-element vector (1.5x growth) |
| 4ac0a0 | `std::vector_reserve_48` | high | Ensures capacity for 48-byte-element vector (1.5x growth) |
| 4c1100 | `std::vector_pushback_12` | high | push_back of a 12-byte element (copies 8+4); grows via FUN_004abf80 |
| 4c1190 | `std::vector_pushback_16` | high | push_back of a 16-byte element; grows via FUN_004ac020 |
| 4c11f0 | `std::vector_pushback_48` | high | push_back of a 48-byte element (11 dwords); grows via FUN_004ac0a0 |
| 4c14d0 | `std::vector_size_48` | high | Returns element count of 48-byte-element vector |
| 4c67b0 | `uninitialized_fill_copy_280` | high | Copies/fills a range of 0x118-byte elements into raw storage |
| 4c67f0 | `vector_growCapacity_280` | high | Computes 1.5x growth capacity for 0x118-byte-element vector |
| 4c6840 | `std::vector_realloc_280` | high | Reallocates 0x118-byte-element vector; moves via FUN_004c67b0 |
| 4c6940 | `std::vector_reserveGrow_280` | high | Ensures capacity for 0x118-byte-element vector; 'vector<T> too long' |
| 4c7830 | `std::vector_eraseResize_280` | high | Erase/resize helper for 0x118-byte-element vector; destroys element (FUN_0040ee70) |
| 4c9640 | `rbtree_allocNode_14` | high | Allocates a 20-byte (0x14) tree node, initializing links from sentinel |
| 4cb0c0 | `uninitialized_copy_3` | high | Copies a range of 3-byte elements into raw storage |
| 4cb310 | `std::vector_realloc_3` | high | Reallocates 3-byte-element vector; moves via FUN_004cb0c0 |
| 4cb3f0 | `std::vector_reserve_3` | high | Ensures capacity for 3-byte-element vector (1.5x); 'vector<T> too long' |
| 4cb5a0 | `rbtree_insertPairNode` | high | Inserts a node (FUN_004ccbf0) and stores an 8-byte value pair at +8 |
| 4ccbf0 | `rbtree_allocNode_10` | high | Allocates a 16-byte list/tree node linking to sentinel; self-links if null |
| 4d9950 | `std::wstring_findSubstr` | high | std::wstring::find: searches this wstring for substring param_1 from position param_2; returns index or npos |
| 4da480 | `std::list_clear` | high | Clears a std::list: destroys nodes, resets head sentinel, frees storage |
| 4da730 | `rbtree_allocNode_28` | high | Allocates a 40-byte (0x28) tree node linking to sentinel |
| 4db110 | `vector_at_12` | high | Returns *this + param_1*0xc (12-byte element address) |
| 4dc470 | `list_copyAll_328` | high | Copies all 0x148-byte-stride list elements from source via FUN_004dc750; SEH frame |
| 4dc4e0 | `list_appendRange_a` | high | Appends a range of nodes (via FUN_00608a90) to a std::list; cap 0xaaaaaa9 |
| 4dc5b0 | `list_appendRange_b` | high | Appends a range of nodes (via FUN_00451d00) to a std::list; cap 0x7fffffe |
| 4dc680 | `list_appendRange_20` | high | Appends a range of 0x14-stride items (FUN_00451e80) to a std::list; cap 0x9249248 |
| 4dc750 | `list_appendRange_328` | high | Appends a range of 0x148-stride items (FUN_00452190) to a std::list; cap 0xc30c2f |
| 4dd700 | `std::list_insert_node_d` | high | Appends node to std::list via FUN_00452060; cap 0x2aaaaa9 |
| 4dfac0 | `vector_at_32` | high | Returns *this + param_1*0x20 (32-byte element address) |
| 4e0070 | `std::vector_size_32` | high | Returns element count of 32-byte-element vector |
| 4e0150 | `rbtree_allocNode_copyStr` | high | Allocates a map node (FUN_004050c0) and copies key int + string value |
| 4e0190 | `rbtree_allocNode_strKey` | high | Allocates an rb-tree node (FUN_004e34b0) with a string key and value fields; SEH-guarded |
| 4e0300 | `rbtree_allocNode_strVec` | high | Allocates a node (FUN_0046d850) with a string key and 4-dword value block from param_3 |
| 4e0440 | `rbtree_copyTreeNode_b` | high | Recursively copies an rb-tree subtree with node clone FUN_004e0080 |
| 4e0500 | `rbtree_insertRebalance_int` | high | std::map/set red-black insert fixup (recolor/rotate) for int-keyed tree; cap 0x5d1745b |
| 4e0730 | `rbtree_insertRebalance_b` | high | Red-black insert rebalance (rotations/recolor); cleanup via FUN_004e2a00; cap 0x4924922 |
| 4e0bc0 | `rbtree_insertHint_int` | high | std::map insert with hint for int key: checks neighbor bounds then rebalances via FUN_004e0500/11d0 |
| 4e0df0 | `rbtree_insertHint_str` | high | std::map insert with hint for string key (compare FUN_00428db0); positions and rebalances |
| 4e11d0 | `rbtree_insertUnique_int` | high | std::map insert-unique for int key: descends tree to slot, checks duplicate, inserts via FUN_004e0500 |
| 4e1310 | `rbtree_insertUnique_str` | high | std::map insert-unique for string key (compare FUN_00428db0); finds slot and rebalances via FUN_004e0730 |
| 4e37e0 | `rbtree::rotate_left` | high | Classic red-black tree left rotation about node param_1, fixing parent/child links |
| 4e6ce0 | `rbtree::min_node` | high | Returns leftmost (minimum) node of RB-tree subtree following child pointer *param_1 |
| 520620 | `sqlite3_close` | high | Thin wrapper: closes database connection via FUN_0054fc20(db,0) |
| 520760 | `sqlite3_exec` | high | Executes SQL text: prepares each statement, steps rows invoking callback param_3, frees; 'API call with...' |
| 524410 | `sqlite3_free` | high | Frees a heap allocation updating memory-usage statistics under mutex |
| 527300 | `sqlite3_step` | high | Executes/advances a prepared statement, auto-reprepares on schema change (0x11); 'API called with... statement' |
| 528920 | `btree::access_payload` | high | Reads or writes cell payload spanning local page and overflow-page chain, allocating overflow index cache |
| 529110 | `btree::allocate_page` | high | Allocates or reuses a database page (freelist or new), initializing MemPage; 'database corruption' |
| 52b7f0 | `btree::incr_vacuum_truncate` | high | Auto-vacuum: relocates trailing pages and truncates database; 'database corruption' |
| 52e9b0 | `btree::init_page` | high | Parses a MemPage header/cell-pointer array validating layout; 'database corruption' on error |
| 52eda0 | `btree::parse_cell_ptr` | high | Parses a single cell: decodes payload size and rowid varints, computes local/overflow split |
| 533960 | `sqlite3_create_collation` | high | Registers/removes a collation sequence with encoding validation; 'unable to delete/modify collation...' |
| 5343b0 | `sqlite3_step` | high | SQLite 3.7.15.2 sqlite3_step: identified by compiler-independent string-anchor match (7 unique-owner string anchors, score 37.0). Anchors: %.16g\|%s(%d)\|(blob)\|collseq(%.20s) |
| 537090 | `sqlite3::find_coll_seq` | high | Finds or creates a collation sequence by name in the hash table, allocating a new entry if requested |
| 537190 | `sqlite3::hash_find` | high | Hash-table lookup: walks bucket chain comparing case-folded names for an equal key |
| 53b980 | `btree::free_page` | high | Frees a page back to the freelist (or overflow trunk), updating headers; 'database corruption' |
| 53d2a0 | `btree::lock_and_read_page1` | high | Locks the btree and reads/validates database page 1 header; 'SQLite format 3' magic |
| 53dee0 | `btree::modify_page_pointer` | high | Updates the child/overflow page number stored in a cell referenced by the ptrmap; 'database corruption' |
| 540b70 | `openDatabase` | high | SQLite 3.7.15.2 openDatabase: identified by compiler-independent string-anchor match (2 unique-owner string anchors, score 13.3). Anchors: BINARY\|MATCH\|NOCASE\|RTRIM |
| 541500 | `pager::playback_journal` | high | Rolls back/plays back the rollback journal, restoring pages and truncating the database |
| 541bd0 | `pager::delete_master_journal` | high | Reads a master-journal file and deletes it once no child journals still reference it |
| 541e00 | `pager::end_transaction` | high | Ends a pager transaction: finalizes/deletes journal, releases lock, resets state |
| 5422c0 | `pager::playback_savepoint` | high | Plays back/copies pages to restore a savepoint, verifying master-journal name |
| 542600 | `pager::playback_or_backup_page` | high | Reads a page from journal/source, verifies checksum, and writes it into the database (playback/backup) |
| 542bc0 | `pager::write_page` | high | Writes a dirty page to the journal then the database, handling WAL and ptrmap/bitvec updates |
| 544d80 | `pager::read_db_page` | high | Reads a database page from the WAL or file into a page buffer, updating page1 header cache |
| 545a20 | `btree::overwrite_cell` | high | Overwrites/relocates a cell during balance: updates ptrmap and copies payload to the new page |
| 5473d0 | `vdbe::commit_all_btrees` | high | Commits phase one across all attached database btrees, validating file-change counters (0x11) |
| 54c710 | `btree::close` | high | Closes a btree connection: closes cursors, rolls back, frees the shared BtShared when last user |
| 54e4a0 | `btree::open` | high | Opens a btree on a database file (':memory:' handling), sharing an existing BtShared when possible |
| 54ed50 | `btree::begin_trans` | high | Begins a read/write btree transaction, acquiring locks and reading page 1; 'database corruption' |
| 5515c0 | `sqlite3_create_function` | high | Creates/replaces a user-defined SQL function, validating args and both-encoding recursion; 'misuse...' |
| 5521a0 | `sqlite3DbFree` | high | Frees a per-connection allocation, returning it to lookaside when it belongs there |
| 552230 | `sqlite3DbMallocRaw` | high | Allocates per-connection memory, using the lookaside slot freelist when the size fits |
| 552450 | `sqlite3_DbStrDup` | high | SQLite: measures strlen of param_2 then allocates via db allocator (FUN_552230) and memcpy-duplicates the string |
| 553890 | `sqlite3_ErrorWithMsg` | high | SQLite: sets db error code (+0x2c) and formats/stores error message on the db connection, allocating a Vdbe error record if needed |
| 555e30 | `sqlite3_ExprDelete` | high | SQLite: recursively frees an Expr tree (left +8, right +0xc), releasing token/list/select children per flag bits |
| 556700 | `sqlite3_ExprListDelete` | high | SQLite: frees an ExprList; loops entries (stride 5 dwords) freeing each Expr then the list array |
| 556c60 | `sqlite3_FindCollSeq` | high | SQLite: hashes collation name, searches db collation hash (+0x140) for best encoding match, optionally creates a new CollSeq |
| 5587a0 | `sqlite3_HashInsertNoResize` | high | SQLite: inserts an element into a string hash table bucket, computing bucket via char-hash of key at +0x18 |
| 559fd0 | `sqlite3_Get4byte` | high | SQLite: reads a big-endian unsigned 32-bit integer from a 4-byte buffer |
| 55a920 | `sqlite3_GetVarint` | high | SQLite: decodes a 64-bit variable-length integer (up to 9 bytes) into param_2[0:1] |
| 55aaf0 | `sqlite3_GetVarint32` | high | SQLite: fast-path decode of a 32-bit varint, falling back to GetVarint (FUN_55a920) for >3 bytes |
| 55ac70 | `sqlite3_HashClear` | high | SQLite: clears a hash table, freeing all element nodes with memory-status accounting and mutex |
| 55ad50 | `sqlite3_HashFind` | high | SQLite: looks up a key in a string hash table, returning the associated data pointer |
| 55ada0 | `sqlite3_HashInsert` | high | SQLite: inserts/updates or removes a key in a hash table, allocating a node and rehashing when load exceeds threshold |
| 55d830 | `sqlite3_LockAndPrepare` | high | SQLite: safety-checks db, enters mutex, prepares statement (FUN_5631b0), retries once on SCHEMA(0x11) error |
| 55da00 | `sqlite3_Malloc` | high | SQLite: core allocator; rejects sizes >0x7ffffefe, uses status-tracked path with mutex or raw xMalloc |
| 55eb70 | `sqlite3_PagerGet` | high | SQLite: fetches a database page into the cache (getPageNormal); handles page-1, error messages, zeroing |
| 55f050 | `sqlite3_PagerCommitPhaseOne` | high | SQLite: commit phase one; writes dirty pages, super-journal, truncates, syncs to disk or WAL frames |
| 55f390 | `sqlite3_PagerWrite` | high | SQLite: marks a page writeable (pager_write); journals original content and links page into dirty list |
| 55f550 | `sqlite3_PagerOpen` | high | SQLite: opens a pager; builds journal/wal filenames ('-journal'), allocates pager+temp buffers, opens db file |
| 55fc70 | `sqlite3_PagerSavepoint` | high | SQLite: releases or rolls back to a savepoint (param_2=op), freeing sub-savepoint bitvecs and playing back journal |
| 55fd60 | `sqlite3_PagerSetBusyhandler` | high | SQLite: stores busy-handler callback/arg (+0x98/+0x9c) and forwards it to the underlying VFS file (+0x28) |
| 55fe80 | `sqlite3_PagerSetPagesize` | high | SQLite: changes the pager page size; reallocates temp buffer and recomputes total page count via __alldiv |
| 560540 | `sqlite3ParseUri` | high | SQLite 3.7.15.2 sqlite3ParseUri: identified by compiler-independent string-anchor match (6 unique-owner string anchors, score 30.0). Anchors: %s mode not allowed: %s\|access\|cache\|invalid uri authority: %.*s |
| 560cd0 | `sqlite3_PcacheSortDirtyList` | high | SQLite: merge-sorts the dirty-page list by page number using a 32-bucket bottom-up mergesort |
| 560e50 | `sqlite3_PcacheMakeClean` | high | SQLite: makes one dirty page clean, unlinking it from the dirty list and notifying pager via DAT_00766664 |
| 560e90 | `sqlite3_PcacheFetch` | high | SQLite: fetches (and optionally creates) a page in the pcache, recycling clean pages under memory pressure |
| 561050 | `sqlite3_PcacheMakeDirty` | high | SQLite: marks a page dirty, clearing the dont-write bit and linking it onto the dirty list |
| 561130 | `sqlite3_PcacheRelease` | high | SQLite: decrements a page's ref count and, if zero, either recycles it or links it into the dirty/clean LRU |
| 5611b0 | `sqlite3_PcacheTruncate` | high | SQLite: discards cached pages with pgno > param_2 (cleaning dirty ones) and truncates the underlying pcache |
| 5631b0 | `sqlite3Prepare` | high | SQLite 3.7.15.2 sqlite3Prepare: identified by compiler-independent string-anchor match (2 unique-owner string anchors, score 10.0). Anchors: database schema is locked: %s\|statement too long |
| 563650 | `sqlite3_Put4byte` | high | SQLite: stores a 32-bit value into a 4-byte buffer in big-endian order |
| 563800 | `sqlite3_Realloc` | high | SQLite: core reallocator with status accounting and soft-heap-limit alarm; delegates to xRealloc |
| 563bf0 | `sqlite3_RegisterDateTimeFuncs` | high | SQLite: inserts the built-in date/time SQL functions ('julianday' etc.) into the global function hash |
| 563c80 | `sqlite3_RegisterBuiltinFuncs` | high | SQLite: registers all built-in scalar/aggregate SQL functions into the global hash, then date-time and LIKE funcs |
| 564f10 | `sqlite3_SafetyCheckOk` | high | SQLite: validates a db connection pointer's magic (+0x44), reporting misuse for null/unopened/invalid handles |
| 565020 | `sqlite3_SchemaClear` | high | SQLite: resets a Schema; frees trigger/table/index hash contents and their objects, clears seq table flag |
| 565140 | `sqlite3_SchemaGet` | high | SQLite: returns the Schema attached to a Btree, allocating and zero-initializing one on first use |
| 566d10 | `sqlite3_SelectDelete` | high | SQLite: frees a Select structure and its subcomponents (FUN_005303a0) if nonzero |
| 567370 | `sqlite3_SrcListDelete` | high | SQLite: frees a SrcList; loops items (stride 0x24 shorts) releasing names, exprs, selects, index/using lists |
| 567c40 | `sqlite3_StatusAdd` | high | SQLite: adds a delta to a status counter (indexed) and updates its high-water mark |
| 567c70 | `sqlite3_StatusSet` | high | SQLite: sets a status counter (indexed) to a value and bumps its high-water mark if larger |
| 567ca0 | `sqlite3_Step` | high | SQLite: executes one step of a prepared statement (sqlite3Step); runs the VDBE, updates profile timing, resets on error |
| 567e70 | `sqlite3_StrAccumAppend` | high | SQLite: appends bytes to a StrAccum string buffer, growing/reallocating the backing buffer as needed |
| 567fb0 | `sqlite3_StrAccumFinish` | high | SQLite: null-terminates a StrAccum and returns the string, copying to db memory if still in the static buffer |
| 568030 | `sqlite3_StrAccumReset` | high | SQLite: frees any dynamically-allocated StrAccum buffer and resets it |
| 568070 | `sqlite3_Strlen30` | high | SQLite: returns strlen masked to 30 bits (sqlite3Strlen30) |
| 56aa30 | `sqlite3VXPrintf` | high | SQLite 3.7.15.2 sqlite3VXPrintf: identified by compiler-independent string-anchor match (2 unique-owner string anchors, score 10.0). Anchors: 0123456789ABCDEF0123456789abcdef\|thstndrd |
| 56c290 | `sqlite3_VdbeChangeEncoding` | high | SQLite: converts a Mem's string to the target text encoding if it holds a string in a different encoding |
| 56c910 | `sqlite3_VdbeDeleteAuxData` | high | SQLite: frees per-cursor/function auxiliary data entries not protected by the retained-args mask |
| 5734d0 | `sqlite3_VdbeDelete` | high | SQLite: destroys a prepared statement; runs VdbeFreeResources, unlinks from db statement list, frees the Vdbe |
| 574600 | `sqlite3_VdbeMemExpandBlob` | high | SQLite: expands a zero-filled blob Mem into a real allocated buffer, zeroing the extension |
| 574670 | `sqlite3_VdbeMemFinalize` | high | SQLite: runs an aggregate function's xFinalize on a Mem, capturing the result into the Mem cell |
| 5748c0 | `sqlite3_VdbeMemGrow` | high | SQLite: ensures a Mem has at least param_2 bytes of writable buffer, reallocating and optionally preserving contents |
| 5749e0 | `sqlite3_VdbeMemHandleBom` | high | SQLite: detects and strips a UTF-16 byte-order mark from a string Mem, setting its encoding accordingly |
| 574af0 | `sqlite3_VdbeMemNulTerminate` | high | SQLite: appends a two-byte NUL terminator to a string Mem, expanding the blob and growing the buffer first |
| 574d40 | `sqlite3_VdbeMemReleaseExternal` | high | SQLite: releases a Mem's external resources (destructor/frame/rowset) and frees its dynamic buffer |
| 574d80 | `sqlite3_VdbeMemRelease` | high | SQLite: releases a Mem's dynamic resources by flag: frame, external destructor, aggregate, or rowset |
| 575040 | `sqlite3_VdbeMemSetStr` | high | SQLite: stores a string/blob into a Mem with given length, encoding, and destructor (static/dynamic/transient) |
| 575350 | `sqlite3_VdbeMemStringify` | high | SQLite: converts a numeric Mem into its text representation using printf ('%!.15g' or '%lld') |
| 575420 | `sqlite3_VdbeMemTranslate` | high | SQLite: transcodes a Mem string between UTF-8 and UTF-16 (LE/BE), reallocating the buffer |
| 575ca0 | `sqlite3_VdbeHalt` | high | SQLite: halts a running Vdbe (sqlite3VdbeHalt); commits/rolls back statement, moves error/result to db |
| 576a80 | `sqlite3_VdbeTransferError` | high | SQLite: copies a halted Vdbe's error code and message string into the parent db connection |
| 5776a0 | `sqlite3_KeyInfoUnref` | high | SQLite: decrements a KeyInfo/object refcount (+3) and, when zero, runs its destructor and frees it |
| 577b00 | `sqlite3_WalCheckpoint` | high | SQLite: performs a WAL checkpoint (sqlite3WalCheckpoint); acquires locks, copies frames to db, optionally truncates log |
| 577c80 | `sqlite3_WalClose` | high | SQLite: closes the WAL (sqlite3WalClose); attempts a final exclusive checkpoint, deletes wal file, frees Wal |
| 577e30 | `sqlite3_WalFrames` | high | SQLite: appends a set of dirty page frames to the WAL log (sqlite3WalFrames), building headers and checksums |
| 5782f0 | `sqlite3_WalOpen` | high | SQLite: opens/creates a Wal object (sqlite3WalOpen); opens shared-memory, sets locking mode, links the wal file |
| 578400 | `sqlite3_WalFindFrame` | high | SQLite: searches the WAL hash index for the most recent frame of a page number within the reader's mark |
| 579aa0 | `sqlite3_Config` | high | SQLite: sqlite3_config implementation; dispatches config verbs to set mutex/mem/pcache methods and buffers |
| 579f80 | `sqlite3_Initialize` | high | SQLite: sqlite3_initialize; one-time bring-up of mutex, malloc, pcache and OS subsystems under the init mutex |
| 57a870 | `sqlite3_StrHash` | high | SQLite: computes SQLite's string hash over param_2 bytes using the case-fold table DAT_007120d8 |
| 57d290 | `sqlite3_VdbeUnbind` | high | SQLite: validates a prepared statement before bind and releases the target parameter Mem (vdbeUnbind) |
| 57dc30 | `sqlite3_WalChecksumBytes` | high | SQLite: computes the 2x32-bit Fibonacci checksum over WAL data, honoring native vs byte-swapped endianness |
| 57dcf0 | `sqlite3_WalCleanupHash` | high | SQLite: rolls back the WAL hash index after aborted frames, zeroing hash slots and page-number entries past mxFrame |
| 57dda0 | `sqlite3_WalDecodeFrame` | high | SQLite: validates and decodes a WAL frame header, verifying salts and per-frame checksums, returning pgno/commit size |
| 57deb0 | `sqlite3_WalEncodeFrame` | high | SQLite: builds a WAL frame header (pgno, db-size, salts) and updates the running checksum |
| 57df70 | `sqlite3_WalIndexAppend` | high | SQLite: appends a page-number entry to the WAL hash index, resolving collisions by linear probing |
| 57e140 | `sqlite3_WalIndexPage` | high | SQLite: maps (allocating on demand) the given WAL-index shared-memory page, growing the page pointer array |
| 57e3a0 | `sqlite3_WalIndexRecover` | high | SQLite: recovers the WAL-index by scanning WAL file frames, rebuilding the hash and reporting frames recovered |
| 57e710 | `sqlite3_WalIndexTryHdr` | high | SQLite: attempts to read the wal-index header from shared memory, validating its self-checksum and copies |
| 57e910 | `sqlite3_WalIndexWriteHdr` | high | SQLite: writes the current WAL-index header (with checksum) into both shared-memory header copies |
| 57e9f0 | `sqlite3_WalIteratorInit` | high | SQLite: builds a WAL checkpoint iterator, merge-sorting each index segment's page numbers into sorted order |
| 57eb80 | `sqlite3_WalIteratorNext` | high | SQLite: advances the WAL merge iterator, returning the next (smallest pgno, frame) pair or end-of-iteration |
| 57eca0 | `sqlite3_WalMerge` | high | SQLite: merges two sorted page-number lists (dropping duplicates by page value) into an output run |
| 57ed80 | `sqlite3_WalMergesort` | high | SQLite: bottom-up merge sort of a WAL segment's page-number index producing a de-duplicated sorted order |
| 57f430 | `sqlite3_WalWriteToLog` | high | SQLite: writes a buffer to the WAL file, splitting the write at the configured wal-size boundary and syncing |
| 580050 | `sqlite3_WriteJournalHdr` | high | SQLite: constructs and writes a rollback-journal header (magic, nRec, checksum initializer, page size/sector) |
| 585760 | `Vector_Reallocate` | high | MSVC STL: reallocates a std::vector's storage to param_1 bytes, moving existing elements (new/delete) |
| 5857d0 | `Vector_Reserve` | high | MSVC STL: ensures vector capacity for param_1 more elements, computing geometric growth (_Xlength on overflow) |
| 5870c0 | `Vector_Resize` | high | MSVC STL: resizes a std::vector, shrinking (move end) or zero-filling grown region after reserve |
| 58cfe0 | `Vector_AllocCapacity18` | high | MSVC STL: allocates a std::vector backing store for param_1 elements of stride 0x18 (_Xlength/_Xbad_alloc) |
| 58d9f0 | `RBTree_InsertRebalance` | high | MSVC STL: std::map red-black tree node insert with recolor/rotation rebalancing (0x5555553 size guard) |
| 58dc20 | `RBTree_InsertRebalanceB` | high | MSVC STL: red-black tree insert-rebalance variant with different node layout (+4 buf, size guard 0x5d1745b) |
| 58de50 | `RBTree_InsertRebalanceC` | high | MSVC STL: red-black tree insert-rebalance variant (node buf +4, size guard 0x5555553) |
| 593e50 | `std_string_FreeMember` | high | MSVC STL: frees a std::string member's heap buffer (if cap>7) and resets it to empty |
| 594840 | `std::vector::_Calculate_growth` | high | Computes new vector capacity (1.5x growth, clamped to max) for elements of size 0x11c=284 bytes |
| 594890 | `std::_Tree::lower_bound_xy` | high | RB-tree/map lower_bound keyed on a 2-int (x,y) pair at node offsets 0x10/0x14; walks left/right |
| 5948d0 | `std::vector::_Reallocate_grow_11c` | high | Reallocates vector storage (element 0x11c), move-constructs via FUN_004569f0, frees old, updates begin/end/cap |
| 5949d0 | `std::vector::_Reallocate_grow_188` | high | Reallocates vector storage (element 0x188=392), moves via 0058e8e0, destroys old via 0058d970, frees |
| 594ad0 | `std::vector::_Emplace_reallocate_11c` | high | Vector grow-on-insert helper (element 0x11c); throws vector<T> too long, computes growth then reallocates |
| 594b40 | `std::vector::_Reserve_grow_188` | high | Vector reserve/grow helper (element 0x188); throws vector<T> too long past max, else reallocates |
| 59c840 | `std::vector::eraseShift_c` | high | Erases one element from vector of 0xc-byte (3-int) elements by shifting tail down, decrements end by 0xc |
| 5a0d80 | `std::vector::pushBack_0x11c` | high | std::vector push_back/insert of 0x11c-byte element; grow via FUN_00594ad0(1) when end==cap, copy elem incl +0x118 field |
| 5a0e00 | `std::vector::pushBack_0x188` | high | std::vector emplace/push_back of 0x188-byte element under SEH; grow via FUN_00594b40(1), copy via FUN_0058ea10 |
| 5a6ab0 | `rbTree_cloneNode` | high | Allocate RB-tree node (FUN_005a7b90), init color(+0xc)=0, copy vector payload (FUN_005a7990) and fields +0x1c..+0x30 from param_1 |
| 5a6ba0 | `rbTree_cloneNodeVariant` | high | Allocate RB-tree node (FUN_006819e0), init color(+0xc)=0, copy vector payload via FUN_005a7990 |
| 5a6c60 | `rbTree_copyAssign` | high | Copy a red-black tree via recursive clone (FUN_005a6da0), then fix head node's leftmost(min)/rightmost(max) pointers |
| 5a6ce0 | `rbTree_copyRecursive` | high | Recursively deep-copy RB-tree subtree, cloning each node via FUN_005a6ab0 (left=*param_1, right=param_1[2]) |
| 5a6da0 | `rbTree_copyRecursiveVariant` | high | Recursively deep-copy RB-tree subtree, cloning each node via FUN_005a6ba0; twin of 5a6ce0 |
| 5a6e60 | `rbTree_insertFixup` | high | std::_Tree insert-and-rebalance: link new node param_5 under param_3, then recolor/rotate up to root maintaining RB invariant |
| 5a7090 | `rbTree_insertFixup_setKey` | high | std::map/set insert-and-rebalance via node from FUN_005a6ba0; _Xlength guard "map/set<T> too long"; recolor/rotate to root |
| 5a7290 | `map_insertUniqueWithHint` | high | std::map/set unique insert using hint iterator param_2; lexicographic key compare (FUN_005a78a0), dispatch to 5a6e60 or fallback 5a7520 |
| 5a7520 | `map_findInsertPos` | high | Find insert position for key (lower_bound via lexicographic compare); on duplicate key, operator_delete the candidate node |
| 5a7700 | `map_insertUnique` | high | std::map/set insert-if-absent; walks tree with lexicographic compare, returns node ptr and inserted-bool (param_1[1]); calls 5a7090 |
| 5a7900 | `map_copyRange` | high | In-order traverse source range [param_1,param_2); clone each node (5a6ab0) and insert-with-hint (5a7290) into this map |
| 5a7990 | `std::vector::copyConstruct` | high | Copy-construct vector<T> from [*param_1,param_1[1]): zero begin/end/cap, reserve size (FUN_0065ae10), copy range (FUN_0065a860) |
| 5a7c10 | `std::_Tree::lowerBound_vecKey` | high | Red-black tree lower_bound walk comparing 3-int vector key lexicographically (nodes at +0x10/+0x14 payload, +0xd=nil flag) |
| 5a7e60 | `std::_Tree::lowerBound_u32` | high | RB-tree lower_bound comparing single uint key at node+0x10 (offset[4]) against *param_2; returns node into *param_1 |
| 5ade10 | `std::uninitializedCopy_T24` | high | Copies range of 24-byte (6-dword) elements [param_1,param_2) into param_3 with null guard; STL uninitialized_copy |
| 5ade60 | `std::vector<T24>::reallocate` | high | Grows vector of 24-byte elems: operator_new(n*0x18), _Xbad_alloc guard, copies old via FUN_005ade10, frees old, resets begin/end/cap |
| 5adf50 | `std::vector<T24>::reserveGrow` | high | Capacity check for 24-byte-element vector; _Xlength_error("vector<T> too long"); computes 1.5x growth then reallocates |
| 5ae0d0 | `std::destroyRange_T24` | high | Destructor for range of 24-byte elems: operator_delete of owned pointers at elem+0 and elem+0xc for each |
| 5ae140 | `std::_InsertionSort_byKey` | high | Insertion sort of int-index array by float key at (*param_3+0x18+idx*0x1c); uses memmove for shifts |
| 5ae310 | `std::_Med3_byKey` | high | Sorts 3 index pointers (param_1..3) by float key at elem+0x18; median-of-three helper for sort |
| 5ae3c0 | `std::_MedianGuess` | high | Pivot selection: median-of-3 for small ranges, ninther (median-of-medians) for >0x28 elems via FUN_005ae310 |
| 5ae460 | `std::uninitializedCopy_T28` | high | Copies range of 28-byte (0x1c) elements [param_1,param_2) into param_3 (3 qwords + 1 dword each) |
| 5ae4a0 | `std::_PushHeap_byIndex` | high | Push-heap sift-up: places *param_4 into int-index heap at param_1 keyed by float at elem+0x18 |
| 5ae540 | `std::introSort` | high | Introspective sort (quicksort + heapsort fallback + insertion sort) of int-index array by float key; depth-limited recursion |
| 5ae630 | `std::_SortHeap` | high | Heap-sort finalize: repeatedly swap front to back and sift-down over int-index array |
| 5ae690 | `std::_PartitionByMedian` | high | 3-way quicksort partition around median pivot; returns [first,second) equal-range bounds in param_1[0],[1] |
| 5ae8c0 | `std::uninitializedCopy_T12` | high | Copies range of 12-byte (3-dword) elements [param_1,param_2) into param_3 with null guard |
| 5ae950 | `std::uninitializedCopy_T28_guarded` | high | Copies range of 28-byte elements [param_1,param_2) into param_3 with null guard (3 qwords + dword) |
| 5ae9a0 | `std::uninitializedCopy_T32` | high | Copies range of 32-byte (8-dword) elements copying 7 dwords each from [param_1,param_2) to param_3 |
| 5aea70 | `std::vector::initEmpty` | high | Zero-inits container header (begin/end/cap = 0); class GameController is misattribution |
| 5aecd0 | `std::vector<T24>::destructor` | high | Vector dtor: destroy 24-byte elements via FUN_005ae0d0 then operator_delete backing storage |
| 5aedf0 | `std::vector::elementAt` | high | Returns element address *in_ECX + param_1*0x1c (28-byte-stride indexing) |
| 5aee40 | `std::vector<T28>::_Calculate_growth` | high | Computes 1.5x geometric growth for vector of 28-byte elements; clamps to max 0x9249249 and requested size |
| 5aee90 | `std::vector<T28>::_Reallocate_grow` | high | Allocates param_1*0x1c buffer, relocates elements via FUN_005ae950, frees old storage; std::_Xbad_alloc on overflow |
| 5aef90 | `std::vector<T32>::_Reallocate_grow` | high | Allocates param_1*0x20 buffer, moves elements via FUN_005ae9a0, frees old; _Xbad_alloc guard (<0x8000000) |
| 5af070 | `std::vector<T28>::_Reserve_grow` | high | vector<28-byte> grow: if capacity < needed, computes growth and reallocates; _Xlength_error("vector<T> too long") |
| 5af0e0 | `std::vector<T32>::_Reserve_grow` | high | vector<32-byte> reserve: bails if capacity suffices else reallocates via FUN_005aef90; _Xlength_error guard |
| 5bf470 | `std::vector<T32>::push_back` | high | Appends a 32-byte element (copies 7 dwords) to vector, growing via FUN_005af0e0; handles self-referential source |
| 5bf4f0 | `std::vector<T24>::push_back` | high | Appends a 24-byte element (copies 6 dwords) to vector, growing via FUN_005adf50; handles aliasing source |
| 5bffd0 | `std::vector<T28>::resize` | high | Resizes vector<28-byte> to param_1: truncates (erase via FUN_005ae460) or grows and default-fills (FUN_005ae900) |
| 5c0100 | `std::vector<T24>::size` | high | Returns element count (end-begin)/0x18 for a 24-byte-element vector (class= misattributed) |
| 5c0420 | `rbtree_insert_rebalance_3key` | high | Red-black tree insert fixup (recolor/rotate) for a std::map/set node; length guard 0x7fffffd; class= misattributed |
| 5c0630 | `rbtree_insert_hint_2key` | high | std::map/set insert-with-hint using 2-field (x,y) key compares (FUN_0046d1c0); inserts node via FUN_00639d30 |
| 5c0880 | `rbtree_insert_hint_3key` | high | std::map/set insert-with-hint using 3-field (x,y,z) key compares (FUN_005c3f30); rebalance via FUN_005c0420 |
| 5c0b10 | `rbtree_lower_bound_insert_2key` | high | Finds insert position by 2-key descent then inserts node (FUN_00639d30); erases dup via operator_delete |
| 5c0c70 | `rbtree_lower_bound_insert_3key` | high | Finds insert position by 3-key (x,y,z) descent then inserts node (FUN_005c0420); dup handling |
| 5c1260 | `make_heap_int` | high | Builds a max-heap from 12-byte int-keyed range via repeated sift (FUN_005c20f0); stack-cookie guarded |
| 5c14e0 | `make_heap_float` | high | Builds a max-heap from 12-byte float-keyed range via FUN_005c21f0 sift |
| 5c1fa0 | `uninitialized_copy_280` | high | Copies a range of 280-byte (0x118) structs from [param_1,param_2) to dest param_3 (field-by-field relocate) |
| 5c20f0 | `push_heap_int` | high | Sift-up (push_heap) for 12-byte int-keyed heap element into hole param_2 |
| 5c21f0 | `push_heap_float` | high | Sift-up (push_heap) for 12-byte float-keyed heap element |
| 5c23b0 | `introsort_int` | high | std::sort introsort recursion (int key, 12-byte): insertion sort small, partition FUN_005c2da0, heapsort fallback |
| 5c2630 | `introsort_float` | high | std::sort introsort recursion (float key, 12-byte): insertion/partition FUN_005c3360/heapsort FUN_005c29a0 |
| 5c2830 | `sort_heap_int` | high | Heapsort finalization: repeatedly pops max to end and sifts via FUN_005c0210 (int key, 12-byte) |
| 5c29a0 | `sort_heap_float` | high | Heapsort finalization popping max via FUN_005c0350 (float key, 12-byte) |
| 5c2da0 | `std::sort::unguarded_partition_vec3i` | high | MSVC std::sort median-of-3 unguarded partition over 12-byte (3-int) elements keyed on int field [2] |
| 5c3360 | `std::sort::unguarded_partition_vec3f` | high | MSVC std::sort median-of-3 unguarded partition over 12-byte (3-float) elements keyed on float field [2] |
| 5c36a0 | `std::uninitialized_copy_stride0x140` | high | std::_Uninitialized_copy for 0x140-byte objects; copy-constructs each via FUN_005c3950 when dest non-null |
| 5c36e0 | `std::uninitialized_copy_stride0x18_eh` | high | std::_Uninitialized_copy for 24-byte objects with SEH unwind; copy-ctors sub-objects at +0 and +0xc |
| 5c3790 | `std::uninitialized_copy_vec3i` | high | std::_Uninitialized_copy of 12-byte (3-int) elements from [param_1,param_2) to param_3 |
| 5c3ea0 | `rbtree_iterator_increment` | high | std::_Tree ++ (in-order successor): follows right-subtree min or walks parents using color byte at +0xd |
| 5c3fe0 | `rbtree_lower_bound_vec3i` | high | std::_Tree lower_bound for vec3i key: walks tree comparing node keys [4],[5],[6] to param_1 |
| 5c4040 | `std::vector::reallocate_stride0x140` | high | std::vector grow: operator_new(n*0x140), uninit-copy via FUN_005c36a0, delete old buffer, update ptrs |
| 5c4130 | `std::vector::reallocate_stride0x18` | high | std::vector grow: operator_new(n*0x18), uninit-copy via FUN_005c36e0, destroy+free old, update ptrs |
| 5c4320 | `std::vector::reserve_grow_stride0x140` | high | std::vector _Reserve/grow-check for 0x140 elems: _Xlength_error guard, 1.5x growth, calls FUN_005c4040 |
| 5c43d0 | `std::vector::reserve_grow_stride0x18` | high | std::vector _Reserve/grow-check for 0x18 elems: _Xlength_error guard, 1.5x growth, calls FUN_005c4130 |
| 5f77b0 | `init_struct_memset` | high | Zero-initializes a struct buffer and returns it |
| 5f79e0 | `init_struct_memset2` | high | Zero-initializes a struct buffer and returns it (sibling of FUN_005f77b0) |
| 5fb860 | `unwind_free_object` | high | SEH cleanup funclet: frees an object (operator_delete); referenced by many Catch_All handlers |
| 5fbb30 | `vector_reallocate` | high | Reallocates vector storage (operator_new + FUN_00456f70 move + operator_delete) |
| 5fbc10 | `vector_reserveGrow` | high | Vector capacity growth guard; throws length_error ('vector<T> too long') on overflow |
| 627ce0 | `security_cookie_guard_a` | high | Stack cookie check stub (validates __security_check_cookie); trivial |
| 627d50 | `security_cookie_guard_b` | high | Stack cookie check stub; trivial shared guard |
| 62f9b0 | `map_insertRebalance` | high | std::map/_Tree insert with rebalance; throws length_error ('map/set<T> too long') |
| 62fbc0 | `map_insertUnique` | high | std::map insert-unique (FUN_004c9580 compare); throws 'map/set<T> too long' on overflow |
| 632640 | `std::list<Node*>::_clear_nodes` | high | MSVC std::list: unlinks all nodes and frees the sentinel/head node via operator_delete |
| 633ce0 | `std::list<Node*>::erase_range` | high | MSVC std::list erase [first,last): splice out and free removed nodes |
| 6391e0 | `std::list::alloc_sentinel_0x34` | high | Allocate+init 0x34-byte list sentinel node (self-linked next/prev, header byte 0x101) |
| 639a70 | `std::string::rfind_substr` | high | Reverse-search: find last occurrence of substring param_1 in this string; returns index or npos |
| 639c50 | `std::uninitialized_copy_pair` | high | Copy array of 2-dword (pair) elements [first,last) to dest |
| 639c80 | `std::uninitialized_copy_triple` | high | Copy array of 3-dword elements [first,last) to dest, returns end |
| 639cc0 | `std::destroy_relocate_0xc` | high | Relocate/destroy 0xc-byte elements over range via FUN_0067a7b0 |
| 639cf0 | `std::vector::destroy_ptr_elems_stride3` | high | Destroy vector elements (stride 3 dwords) freeing owned pointer at [0] via operator_delete |
| 639d30 | `std::map::rb_insert_rebalance_vec2` | high | Red-black tree insert+recolor/rotate; key is Vector2<uint> at +0x10/+0x14 |
| 63a600 | `std::uninitialized_copy_records_0xd` | high | Copy array of 0xd-dword (0x34-byte) records [first,last) to dest |
| 63a690 | `std::vector::move_assign_stride3` | high | Move-assign vector elements (stride 3): free dest ptr, steal src, null src |
| 63a710 | `std::copy_int_range` | high | memmove a dword range [first,last) to dest, return dest end |
| 63a740 | `std::uninitialized_copy_matrix` | high | Copy array of 0x10-dword (4x4 matrix) elements to dest (skips null dest) |
| 63a780 | `std::uninitialized_copy_0xc_guarded` | high | Copy-construct 0xc-byte elements with SEH cleanup (FUN_005a7990) |
| 63a820 | `std::uninitialized_copy_dword` | high | Copy dword elements [first,last) to dest (skip null) |
| 63a850 | `std::uninitialized_copy_2dword` | high | Copy 2-dword elements [first,last) to dest |
| 63a890 | `std::uninitialized_copy_4dword` | high | Copy 4-dword elements [first,last) to dest |
| 63a8e0 | `std::uninitialized_copy_records_0xd_v2` | high | Copy 0x34-byte records to dest (null-checked variant of 63a600) |
| 63d730 | `std::map<uint,T>::subscript` | high | std::map operator[]: find uint key in RB-tree, insert default (FUN_00608a60) if absent; returns value ptr |
| 63d8c0 | `std::vector::allocate_stride0x10` | high | Allocate vector storage for n 0x10-byte elements ('vector<T> too long') |
| 63da20 | `std::vector::grow_realloc_stride4` | high | Reallocate dword vector to new capacity, memmove old, free old |
| 63daa0 | `std::vector::grow_realloc_stride0x34` | high | Reallocate 0x34-byte-element vector, copy+free old (SEH) |
| 63db90 | `std::vector::grow_realloc_stride0xc` | high | Reallocate 0xc-byte-element vector, copy+destroy+free old (SEH) |
| 63dc90 | `std::vector::reserve_stride4` | high | Grow dword vector capacity (1.5x) if needed via 63da20 ('vector<T> too long') |
| 63dd10 | `std::vector::reserve_stride0x34` | high | Grow 0x34-byte vector capacity if needed via 63daa0 |
| 63ddc0 | `std::vector::reserve_stride0xc` | high | Grow 0xc-byte vector capacity if needed via 63db90 |
| 63fe80 | `std::allocator::allocate_stride0xc` | high | Allocate raw storage for n 0xc-byte elements or throw bad_alloc |
| 6413b0 | `std::vector::erase_range_stride0xc` | high | Erase [first,last) from 0xc-byte vector: shift tail down (63a690) and destroy leftovers |
| 642610 | `std::vector::insert_one_stride0xc` | high | Insert single 0xc-byte element at position, growing (63ddc0) if at capacity |
| 6428f0 | `std::vector::resize_stride0x34` | high | Resize 0x34-byte-element vector: erase tail or append default-constructed via vfunc_6 |
| 642ab0 | `std::vector::size_stride0xc` | high | Return element count of 0xc-byte-stride vector |
| 64b3d0 | `std::list::make_node_copy_pair` | high | Construct list node (FUN_0064e3d0) then copy payload (FUN_0064d770) unless sentinel |
| 64b490 | `std::list::make_node_worldinfo` | high | Allocate node (FUN_004050c0) and copy WorldInfo string into it unless sentinel |
| 64b4c0 | `std::list::make_node_copy_pair_v2` | high | Construct list node (FUN_0046d710) then move-copy string pair (64af30) unless sentinel |
| 64b4f0 | `std::move_backward_stride4` | high | Move-backward array of 4-dword elements (for insert shift) |
| 64b540 | `std::map::rb_insert_rebalance_int` | high | Red-black tree insert+rebalance; key int at +0x10, frees oversized node payload strings on overflow |
| 64bdf0 | `std::transform_toupper_u16` | high | transform: apply functor (toupper) over u16 range, write to dest |
| 64be40 | `std::uninitialized_fill_n_stride4` | high | Fill n vector<4-dword> slots with copies of param_3 |
| 64be80 | `std::uninitialized_fill_stride4` | high | Fill [first,last) 4-dword elements with param_3 value |
| 64d0c0 | `std::vector<byte>::init_fill` | high | Zero-init byte vector header then allocate+fill (FUN_0064e450) |
| 64e310 | `std::vector<byte>::allocate` | high | Allocate n raw bytes for a byte vector or throw bad_alloc |
| 64e370 | `std::list::alloc_sentinel_0x2c` | high | Allocate+init 0x2c-byte list sentinel node (self-linked, header 0x101) |
| 64e3d0 | `std::list::alloc_sentinel_0x44` | high | Allocate 0x44-byte list sentinel node, self-link if null args |
| 64e450 | `std::vector<byte>::assign_fill` | high | Allocate byte buffer (64e310) then memset-fill with param_2 value |
| 6536d0 | `std::list::append_node_pair` | high | Append constructed node (64b4c0) to list, bump size ('list<T> too long' at 0x4924923) |
| 653720 | `std::list::append_node_worldinfo` | high | Append constructed node (64b3d0) to list, bump size (cap 0x3c3c3c2) |
| 659670 | `istream::read_wstring` | high | Read length-prefixed wide (u16) std::wstring from istream (alloc, copy, free) |
| 659ef0 | `std::map::findValue` | high | RBTree lower_bound search on key at node+0x10 (offset 4); returns mapped value at node[5] or 0 if not found. |
| 65a1c0 | `RBTree::insertNodeRebalance` | high | Links new red-black node under parent param_3 (side param_2) and rebalances tree via rotations (color byte at +0xc). |
| 65a3f0 | `std::map::insertWithHint` | high | map insert using hint iterator param_2: checks neighbors via comparator FUN_0065ad80, else falls back to full insert FUN_0065a650. |
| 65a650 | `std::map::insertUnique` | high | Full unique insert: descends tree comparing 4-part key (int,int,tuple via FUN_005a78a0), returns iterator+bool; deletes payload on dup. |
| 65a860 | `std::copyRange` | high | Copies dword range [param_1,param_2) into param_3 (null-checked per element); simple uninitialized/copy loop. |
| 65ac70 | `std::map::insertOrAssignMoveVal` | high | insert-or-assign: locates key (FUN_0065b1e0), if present skips; else creates node moving vector value and inserts, freeing moved buf. |
| 65ae10 | `std::vector<int>::allocateN` | high | Zeroes vector, allocates param_1*4 bytes via operator_new, sets begin/end/cap; throws length_error/bad_alloc. |
| 65aef0 | `std::map::equalRange3Key` | high | Computes equal_range [lower,upper) over 3-int key (offs [4],[5],[6]); returns pair of iterators in param_1. |
| 65afd0 | `std::map::equalRangeVectorKey` | high | equal_range over key (int,int,int-vector compared elementwise / FUN_005a78a0); writes lower & upper into param_1. |
| 65b180 | `RBTree::destroyRecursive` | high | Recursively frees right subtree then node, deleting owned buffer at +0x18; std::_Tree erase-all. |
| 65b1e0 | `std::map::findLowerBoundVecKey` | high | lower_bound over (int,int,int-vector) key; returns candidate node or header if not found. |
| 65d060 | `std::map::eraseRange` | high | Erases iterator range [param_2,param_3); if whole tree, recursively destroys and resets header; else erases node-by-node via FUN_0065d120. |
| 65d120 | `RBTree::eraseNodeRebalance` | high | Removes one red-black node and rebalances (recolor/rotate), fixes min/max/root pointers; frees node+its +0x18 buffer. |
| 661940 | `std::map::eraseTreeRec` | high | Recursively frees a red-black subtree: descends right child, releases node's owned string buffer then deletes the node |
| 661ae0 | `std::rbtree::eraseNode` | high | Removes a single rb-tree node with full red-black rebalance (recolor/rotate) and frees the node's string then the node |
| 665c90 | `std::_Move_backward_0x40` | high | Copy-backward of 64-byte (16-dword) elements from [param1,param2) into range ending at param3 |
| 665cc0 | `std::_Move_backward_8byte` | high | Copy-backward of 8-byte (2-dword) elements between ranges |
| 665cf0 | `std::_Move_backward_0xc` | high | Copy-backward of 12-byte (3-dword) elements between ranges |
| 665d30 | `std::_Rb_tree::_Insert_rebalance` | high | Red-black tree node insert + recolor/rotate rebalance for std::map/set |
| 665f30 | `std::map::_Insert_hint` | high | Ordered insert of unique key into map/set: lower_bound walk on (key4,key5) pair then FUN_00665d30 rebalance; returns pair<iter,bool> |
| 666080 | `std::_Uninitialized_fill_n_0x40` | high | Uninitialized fill of param_2 copies of a 64-byte element from param_3 |
| 6660b0 | `std::_Uninitialized_fill_n_8byte` | high | Uninitialized fill of param_2 copies of an 8-byte element from param_3 |
| 6660e0 | `std::_Uninitialized_fill_n_0xc` | high | Uninitialized fill of param_2 copies of a 12-byte element from param_3 |
| 666110 | `std::_Uninitialized_copy_0xc` | high | Uninitialized copy of 12-byte elements from [param1,param2) to param3; returns end |
| 666180 | `std::_Fill_0xc` | high | Fills range [param1,param2) with the 12-byte value at param_3 |
| 667a90 | `std::map::operator[]` | high | Map subscript by int key at node[4]: lower_bound search, insert new node via FUN_00665bd0 if absent, return value ptr (node+5) |
| 667e50 | `std::vector::_Calc_growth_0x40` | high | Capacity growth (1.5x, cap 0x3ffffff) for vector of 64-byte elements |
| 667e90 | `std::vector::_Calc_growth_0xc` | high | Capacity growth (1.5x, cap 0x15555555) for vector of 12-byte elements |
| 667ee0 | `std::vector::_Insert_n_4byte` | high | Insert n copies of a 4-byte value into vector, reallocating (operator_new) or shifting in place as needed |
| 668110 | `std::vector::_Insert_n_0x40` | high | Insert n copies of a 64-byte element into vector, reallocating or shifting; SEH-guarded |
| 668360 | `std::vector::_Insert_n_8byte` | high | Insert n copies of an 8-byte element into vector, reallocating or shifting; cookie-guarded |
| 6685d0 | `std::vector::_Insert_n_0xc` | high | Insert n copies of a 12-byte element into vector, reallocating or shifting; cookie-guarded |
| 668950 | `std::vector::_Reallocate_0xc` | high | Grow/reallocate vector storage for 12-byte elements, copy old contents, free old |
| 66add0 | `std::vector::push_back_4byte` | high | push_back of a 4-byte value; grows via FUN_0063dc90 if at capacity; handles source aliasing storage |
| 66aed0 | `std::vector::push_back_move_0xc` | high | push_back with move of a 12-byte element (zeroes source); grows via FUN_0063ddc0 if full |
| 66b110 | `std::vector::resize_4byte` | high | Resize vector of 4-byte elements: shrink (truncate) or grow via FUN_00667ee0 insert-fill |
| 66b180 | `std::vector::resize_0xc` | high | Resize vector of 12-byte elements: shrink via FUN_00639c80 or grow via FUN_006685d0 |
| 672e80 | `std::vector::_Reallocate_0xc_v2` | high | Grow/reallocate vector of 12-byte elements copying via FUN_005c3790, free old buffer |
| 672f70 | `std::vector::_Reserve_0xc` | high | Ensure capacity for 12-byte-element vector, delegating to reallocate FUN_00672e80 |
| 674ee0 | `std::vector::push_back_0xc` | high | push_back (copy) of a 12-byte element; grows via FUN_00672f70 if at capacity; handles source aliasing |
| 677630 | `std::_Uninitialized_copy_0xc_v2` | high | Uninitialized copy of 12-byte elements (u64+u32) from [param1,param2) to param3 |
| 677760 | `std::_Uninitialized_copy_0xc_v3` | high | Uninitialized copy of 12-byte elements with null-dest guard from [param1,param2) to param3 |
| 677800 | `std::vector::_Assign_range_0xc` | high | Copy-assign vector from source range [param1,param2) of 12-byte elements: reuse, grow (realloc), or shrink storage |
| 677990 | `std::vector::_Erase_shift_0xc` | high | Erase element at index param_1 by shifting subsequent 12-byte elements down one, decrement end |
| 677ac0 | `std::vector<string>::destroyRange` | high | Destroys a range of std::string elements (SSO buffer reset then operator_delete on heap strings) |
| 677d10 | `std::vector<string>::reallocate` | high | Reallocates a vector of 0x1c-byte string elements to param_1 capacity, copying then destroying old storage |
| 677e20 | `std::vector<string>::growIfNeeded` | high | Ensures vector of 0x1c-byte string elements can hold param_1 more, computing new capacity and reallocating |
| 678520 | `std::_Tree::allocHeadSentinel` | high | Allocates a 20-byte red-black tree/list head sentinel node with self-referential links and color/nil bytes |
| 67a7b0 | `std::vector<int>::assignRange` | high | Assigns/copies a vector<int> range into in_ECX, using memmove for in-place fit or reallocating when it must grow |
| 67e480 | `std::list::clear` | high | Clears a std::list: frees the single data node if non-nil then resets head self-links and size to 0 |
| 681260 | `std::vector::copyConstructPairs` | high | Copy-constructs a vector of 8-byte pair elements from param_1 into in_ECX, reserving capacity first |
| 6819e0 | `std::list::allocNode` | high | Allocates a 28-byte list node initialized with three links pointing at the sentinel *in_ECX |
| 681a20 | `std::_Tree::destroyHead` | high | Destroys a tree/list at param_1+0x14: frees the root data node then the head sentinel |
| 681a70 | `std::vector::reallocate8byte` | high | Reallocates a vector of 8-byte elements to param_1 capacity via operator_new+memmove, updating begin/end/cap |
| 681af0 | `std::vector::growIfNeeded8byte` | high | Ensures a vector of 8-byte elements can hold param_1 elements, computing 1.5x growth and reallocating |
| 688610 | `StreamReader::readWString` | high | Reads length-prefixed wide (UTF-16) string from istream into std::wstring (2 bytes/char, null-terminated) |
| 68d652 | `operator_new_wrapper` | high | Thin wrapper around operator_new(size) returning allocated buffer |
| 68f2f0 | `FT_Face_FindUnicodeCharmap` | high | FreeType: scan face charmap array backwards for a Unicode cmap ('unic'=0x756e6963, plat/enc 3/10 or 0/4), store into face+0x5c |
| 68f3b0 | `FT_Match_BitmapStrike` | high | FreeType: search available fixed bitmap strikes for one matching requested size (rounded to 64); return index via param_4 |
| 68f500 | `ft_recompute_scaled_metrics` | high | FreeType: scale ascender/descender/height/max_advance by size scale (via FT_MulFix 68ebc0), round to 64 grid |
| 68f560 | `ft_select_bitmap_strike_metrics` | high | FreeType: fill size metrics from a fixed bitmap strike (x_ppem/y_ppem) or from scale if scalable |
| 68f5f0 | `FT_Request_Metrics` | high | FreeType: compute pixel/point size scale from FT_Size_Request (nominal/real/bbox modes) into size metrics |
| 68f860 | `FT_Request_Size_internal` | high | FreeType: validate size request, call driver request_size hook or scalable/bitmap metric path |
| 68f8f0 | `FT_Set_Pixel_Sizes` | high | FreeType: build FT_Size_Request (pixel mode) from width/height, clamp to >=0x40, call FT_Request_Size |
| 68fa30 | `FT_Get_Kerning` | high | FreeType: call driver get_kerning hook, scale/round result per kern mode (unscaled/scaled/grid-fit) |
| 68fb90 | `FT_Get_Char_Index` | high | FreeType: map char code to glyph index via active charmap's char_index hook |
| 68fc00 | `FT_Get_Postscript_Name` | high | FreeType: query 'postscript-font-name' service and return PS name, caching service ptr at face+0x80+0x20 |
| 68fce0 | `ft_find_charmap_by_encoding` | high | FreeType: walk face charmaps linked list at +0x9c for one whose encoding (+0x18) equals param_2 |
| 68fd80 | `FT_Get_Module_By_Name` | high | FreeType: linear search library module array for module whose clazz name (+8) strcmp-matches param_2 |
| 690340 | `ft_validate_outline_contours` | high | FreeType: validate outline contour end-point indices are strictly increasing and within point count |
| 6904c0 | `FT_Outline_Translate` | high | FreeType: add (xOffset,yOffset) to every point of an outline |
| 690500 | `FT_Vector_Transform` | high | FreeType: apply 2x2 FT_Matrix to a vector using FT_MulFix (68ebc0) |
| 690560 | `FT_Outline_Transform` | high | FreeType: apply FT_Matrix to every point of an outline via FT_Vector_Transform |
| 6908c0 | `FT_Stream_Seek` | high | FreeType: seek stream to pos, using seek callback at +0x14 (disk) or bounds-check for memory stream |
| 690900 | `FT_Stream_Skip_checked` | high | FreeType: guard negative offset then delegate to FT_Stream_Seek |
| 690930 | `FT_Stream_Pos` | high | FreeType: return current stream position (stream+8) |
| 690940 | `FT_Stream_Read_buffer` | high | FreeType: read Size bytes from stream at offset into dst via memcpy or read callback; update pos |
| 690b80 | `FT_Stream_ReadUShort` | high | FreeType: read big-endian 16-bit value from stream, advance pos by 2 |
| 690cd0 | `FT_Stream_ReadULong` | high | FreeType: read big-endian 32-bit value from stream, advance pos by 4 |
| 690db0 | `ft_trig_downscale` | high | FreeType: fixed-point scale-down by trig magic 0x4585/0xb9e9 (part of CORDIC trig), preserving sign |
| 690e10 | `ft_trig_prenorm` | high | FreeType: normalize a vector's magnitude into working range, return shift count |
| 690ea0 | `ft_trig_pseudo_rotate` | high | FreeType: CORDIC pseudo-rotation of vector by angle in_EAX using arctan table DAT_007226bc |
| 690f80 | `ft_trig_pseudo_polarize` | high | FreeType: CORDIC pseudo-polarization; compute vector angle via arctan table, quantize to 32-grid |
| 691030 | `FT_Cos` | high | FreeType: compute cosine (FT_Vector at angle from x=0x4585ba3) via pseudo_rotate |
| 691070 | `FT_Sin` | high | FreeType: thin wrapper computing sine via FT_Cos/pseudo-rotate helper |
| 691090 | `FT_Atan2` | high | FreeType: compute atan2(x,y) angle via prenorm + pseudo_polarize |
| 6910d0 | `FT_Vector_Length_or_Rotate` | high | FreeType: CORDIC vector length/rotate: prenorm, polarize, downscale, apply shift |
| 6911e0 | `FT_Vector_From_Angle` | high | FreeType: set vector=(len,0) then rotate by angle (FT_Vector_Unit-like) |
| 691200 | `FT_Angle_Diff` | high | FreeType: compute normalized angle difference (param_2-param_1) into (-pi,pi] range |
| 691240 | `ft_mem_alloc_raw` | high | FreeType: FT_Mem allocate via memory->alloc (+4) with size validation; set error out |
| 691290 | `FT_Mem_Free` | high | FreeType: free block via memory->free hook at +8 |
| 691390 | `ft_list_find_by_data` | high | FreeType: FT_List_Find - walk singly-linked list for node whose data (+8) equals key |
| 6913b0 | `FT_List_Add` | high | FreeType: append node to doubly-linked FT_List (tail insert) |
| 6913e0 | `FT_List_Remove` | high | FreeType: unlink node from FT_List, fixing head/tail |
| 691410 | `FT_List_Up` | high | FreeType: unlink node then move it to front of FT_List |
| 691460 | `FT_List_Finalize` | high | FreeType: iterate FT_List calling destroy callback per node then free node, clearing list |
| 691540 | `ft_glyphslot_free_internal` | high | FreeType: free glyph slot sub-buffers (subglyphs/bitmap/other) and reset via 68f020 |
| 6915b0 | `ft_glyphslot_done` | high | FreeType: destroy a glyph slot: free internal buffers then free slot |
| 6915d0 | `ft_size_destroy` | high | FreeType: run size done hook then optionally free the size object |
| 6916f0 | `ft_size_done_inner` | high | FreeType: run driver done_size hook, clear bitmap, free size internal object at +0x9c |
| 691760 | `FT_Done_Size` | high | FreeType: remove size from face's size list and destroy it |
| 691c20 | `FT_Render_Glyph_Internal` | high | FreeType: locate renderer for glyph format ('bits'/'outl'/other), run render hook, retry on 0x13 |
| 691ce0 | `FT_Render_Glyph` | high | FreeType: render a glyph slot using the library's renderer chain |
| 691d10 | `FT_Bitmap_Free` | high | FreeType: free FT_Bitmap owned rows and zero the bitmap struct |
| 691ec0 | `FT_Stream_Read_current` | high | FreeType: read bytes at stream's current pos into buffer (thin FT_Stream_Read) |
| 692230 | `FT_Mem_QAlloc_Clear` | high | FreeType: allocate memory then zero it (FT_Mem_Alloc), returning ptr and error out |
| 692290 | `FT_Mem_QRealloc` | high | FreeType: (re)allocate item*count block with overflow check, or free when count 0 |
| 692580 | `FT_New_GlyphSlot` | high | FreeType: allocate a new glyph slot for a face, init internals, link into slot list |
| 692620 | `FT_Load_Glyph` | high | FreeType: main glyph loader - clear slot, call driver load_glyph hook, autohint/embolden, transform, render |
| 692920 | `FT_Load_Char` | high | FreeType: map char code to glyph index (if charmap) then FT_Load_Glyph |
| 6929b0 | `ft_face_destroy_inner` | high | FreeType: tear down a face: destroy sizes, charmaps, glyph slot, run driver done_face, free internal |
| 692aa0 | `ft_open_face_object` | high | FreeType: allocate/init a face object, run driver init_face hook, find unicode charmap |
| 692c40 | `ft_open_face_from_stream` | high | FreeType: build memory stream, init face via 68fded, load face, clear cache flag |
| 693180 | `FT_Remove_GlyphSlot` | high | FreeType: unlink glyph slot from face slot list, free it, destroy owning face inner |
| 6931e0 | `FT_New_Size` | high | FreeType: allocate a new FT_Size for a face, run driver init_size hook, link into size list |
| 693a60 | `FT_Mem_QRenew_Clear` | high | FreeType: reallocate cur->new count block and zero-fill the grown tail |
| 6946d0 | `ft_open_font_format_dispatch` | high | FreeType: try SFNT/TrueType then Type1 openers in sequence, filling driver-resolved object |
| 694b60 | `FT_Open_Face` | high | FreeType: main FT_Open_Face - build stream, iterate drivers, open face, normalize metrics, finalize |
| 694f00 | `FT_New_Memory_Face` | high | FreeType: FT_New_Memory_Face - build FT_Open_Args (memory, flag 4) and call FT_Open_Face |
| 694f50 | `FT_New_Face` | high | FreeType: FT_New_Face - build FT_Open_Args (pathname, flag 1) and call FT_Open_Face |
| 694fa0 | `ft_bitmapglyph_copy_from_slot` | high | FreeType: copy a rendered bitmap glyph ('bits') from slot into glyph object, or FT_Bitmap_Copy |
| 695240 | `FT_Glyph_Transform` | high | FreeType: apply matrix+delta to a glyph via its clazz transform hook, then translate advance |
| 6952a0 | `FT_Done_Glyph` | high | FreeType: destroy a glyph object via its clazz done hook then free it |
| 6952d0 | `FT_Glyph_Copy` | high | FreeType: allocate a new glyph and copy via clazz copy hook, cloning advance fields |
| 695360 | `FT_Get_Glyph` | high | FreeType: extract a glyph from a slot into a FT_Glyph object ('bits'/'outl' clazz), copy metrics |
| 695420 | `FT_Glyph_To_Bitmap` | high | FreeType: render an outline FT_Glyph into a bitmap glyph, applying origin translate, optional destroy src |
| 695620 | `ft_int_abs` | high | FreeType: return absolute value of a signed int |
| 695970 | `ft_outline_grow_arrays` | high | FreeType: grow outline builder point/tag arrays to needed capacity via QRenew |
| 6959f0 | `ft_outline_close_contour` | high | FreeType(smooth): close current subpath, optionally reverse points/tags, tag start/end flags |
| 695ab0 | `ft_outline_line_to` | high | FreeType: add a line-to point to the outline builder (or overwrite pending) |
| 695b20 | `ft_outline_conic_to` | high | FreeType: emit a conic (2 points: control+end) into the outline builder |
| 695b70 | `ft_outline_cubic_to` | high | FreeType: emit a cubic (3 points) into the outline builder |
| 695d90 | `ft_outline_builder_init` | high | FreeType: initialize an outline builder record (memory, zero counts, tag -1) |
| 695db0 | `ft_outline_builder_reset` | high | FreeType: reset outline builder position counters (n_points=0, start=-1) |
| 695dd0 | `ft_outline_builder_done` | high | FreeType: free outline builder point/tag arrays and reset counters |
| 695e10 | `ft_outline_count_contours` | high | FreeType: scan tag flags to count total points and closed contours, mark done |
| 696550 | `ft_stroke_conic_to` | high | FreeType(stroker): stroke a conic segment - compute angle, offset both sides, add line points |
| 696af0 | `ft_stroke_move_to_record` | high | FreeType(stroker): record move-to start point and reset current/first point of a subpath |
| 696bf0 | `ft_stroke_end_subpath` | high | FreeType(stroker): close/cap a subpath: either join open ends or reverse+cap the inner border |
| 696db0 | `TT_Decompose_Glyph_Outline` | high | FreeType(truetype): decompose a TrueType glyph outline (on/off curve tags) into moveto/lineto/conicto/cubicto stroker calls |
| 6970b0 | `FT_Glyph_Stroke` | high | FreeType: stroke an outline FT_Glyph: decompose, compute counts, build stroked outline, replace glyph |
| 6cc610 | `FT_Stream_Open_File` | high | FreeType: open a disk file stream (fopen rb), record size via fseek/ftell, set read/close hooks |
| 6cc6c0 | `FT_Bitmap_Init` | high | FreeType: zero-initialize a 6-word FT_Bitmap descriptor |
| 6cc700 | `FT_Bitmap_Copy` | high | FreeType: deep-copy an FT_Bitmap, (re)allocating destination buffer and memcpy rows |
| 6cfea0 | `vorbis_read_info_header` | high | Vorbis: parse identification header: channels, rate, bitrates, blocksizes (validated 64..8192) |
| 6d0230 | `vorbis_alloc_state` | high | Vorbis: allocate and zero a vorbis handle plus 0xe50-byte setup block |
| 6d0320 | `vorbis_read_bits_to_bytes` | high | Vorbis: bit-reader that fills a byte buffer, handling word crossings and EOF padding |
| 6d0610 | `vorbis_decode_packet_full` | high | Vorbis: decode one audio packet: read mode/mapping, floors, residues into channel buffers |
| 6d0b20 | `vorbis_advance_read_pos` | high | Vorbis: advance sample read position by param_2, bounds-checked against block length |
| 6d0b50 | `vorbis_get_channel_ptrs` | high | Vorbis: fill per-channel output pointer array offset to current read position, return remaining samples |
| 6d1260 | `vorbis_reset_decode_state` | high | Vorbis: reset per-decode state fields (block sizes, positions -1) from setup blocksizes |
| 6d12e0 | `vorbis_free_channel_state` | high | Vorbis(audio): free all per-channel decode buffers - floors, residues, mappings, window arrays |
| 6d1570 | `vorbis_alloc_decode_buffers` | high | Vorbis: allocate decoder working buffers (0x88 ctx, per-channel arrays, IMDCT tables via 6da1f0) |
| 6d1ab0 | `vorbis_temp_bump_alloc` | high | Vorbis: bump/arena allocator for temp buffers (8-aligned), chaining old blocks on overflow |
| 6d1b10 | `vorbis_temp_arena_flush` | high | Vorbis: free chained temp arena blocks and realloc current block to used size |
| 6d1f00 | `vorbis_lookup1_values` | high | Vorbis: compute lookup1 values = floor(entries^(1/dim)) via pow/floor with integer refinement |
| 6d1fa0 | `vorbis_compute_huffman_codes` | high | Vorbis: assign canonical Huffman codeword values from a codeword-length list, bit-reverse each |
| 6d3840 | `vorbis_read_codebook` | high | Vorbis: parse one Vorbis codebook from bitstream (sync 'BCV'=0x564342): dims, lengths, lookup table |
| 6da1f0 | `vorbis_imdct_setup_twiddles` | high | Vorbis(audio): precompute IMDCT twiddle factors (cos/sin tables) and bit-reversal table for a block size |
| 401330 | `OggSync_reset` | med | Zeroes sync/packet state: sets +4=-1 and four 8-byte slots to 0 (returned=-1 init) |
| 401360 | `OggBuffer_free` | med | Frees *param buffer and zeroes struct (returned/fill/storage) - ogg buffer teardown |
| 4021e0 | `RBTreeNode_createString` | med | Allocates map/set node (0x2c) via buynode and move-constructs a std::string key into it |
| 4054b0 | `vector_fillN` | med | Reserves via FUN_0065ae10 then copies value param_2 into param_1 slots (vector assign n) |
| 40b4e0 | `strstreambuf_tidy` | med | std::strstreambuf _Tidy: frees allocated buffer (flag &1) and clears get/put pointers |
| 40c600 | `map_insertNode` | med | std::map insert helper: lower_bound then attach node via FUN_00468910, accumulates size at +0x4c |
| 40e696 | `wostream_insertNarrow_unwind` | med | Exception cleanup landing pad for FUN_0040e440 (setstate + _Osfx) |
| 40e8d6 | `wostream_insertWide_unwind` | med | Exception cleanup landing pad for FUN_0040e6f0 |
| 40f3c0 | `strstreambuf_init` | med | std::strstreambuf init from buffer: allocates dynamic buffer (2x), sets get/put pointers, flags |
| 411b90 | `strstreambuf_initWrap` | med | Widget/strstreambuf setup: tidy (40b4e0) then init buffer (40f3c0) with mode +0x54 |
| 424d40 | `wostream_insertU16string_unwind` | med | Exception cleanup landing pad for FUN_00424ba0 |
| 424da0 | `u16string_assignCharRange` | med | Assigns char range [param_1,param_2) to u16string, widening each byte to 16-bit |
| 42bea0 | `std::vector<T8>::resize` | med | STL vector (8-byte elems) resize: shrink in place or grow appending defaults via AdaptionWidget::vfunc_6; SEH-guarded |
| 42bf80 | `std::vector<T16>::resize` | med | STL vector (16-byte elems) resize: erase tail via 00427a30 or append defaults via vfunc_6; SEH-guarded |
| 439190 | `wstring::equalsCI` | med | Measures UTF-16 param_2 length then compares to string at param_1+0x10 via 00428db0; returns equal |
| 4391d0 | `wstring::notEquals` | med | Same as 00439190 but returns compare != 0 |
| 43a270 | `wstring::replace` | med | std::wstring replace(pos,n,src): grows/moves with memmove/memcpy; throws length/position errors |
| 43a450 | `wstring::ctorFromRange` | med | Constructs wstring: init SSO header then assign chars via 0040f680 |
| 44e7a0 | `tilemap_writeGlyphColumn` | med | Writes glyph/tile cells down a column: fetch cell via 005f9620, quantize floats to bytes, store via 0044e700 |
| 451800 | `wstring_assign` | med | Assign wide string from short*: strlen then 0046f270, free temp |
| 452320 | `wstring_assignFromShortRange` | med | Assign wide string from [param_1,param_2) shorts: reserve then append each via 0040bff0 |
| 4523f0 | `map_copyAssignTree` | med | Rebuild map tree copying from param_1 via recursive 00452540, fix min/max/size links |
| 459c00 | `Store_ftol64_result` | med | Call float-to-int64 helper FUN_0068d946 and store 8-byte result into *this |
| 468910 | `rbtree_findOrInsert_intKey` | med | Red-black tree lower_bound by int key; insert new node if absent; return value ptr (node+5) |
| 468ad0 | `rbtree_findOrInsert_pairKey` | med | RB-tree find/insert by (x,y) int-pair key; return value ptr (node+6) |
| 468ee0 | `fixed_sub_ftol_64` | med | param_1(int64) = ftol64() - param_3(int64) |
| 468fc0 | `fixed_sub_ftol_rev64` | med | param_1(int64) = *this - ftol64() (64-bit subtract) |
| 46de30 | `vector_insertN_stride4` | med | std::vector insert-n-copies at position, stride 4, with realloc/grow |
| 46e150 | `vector_reallocInsert_stride128` | med | Reallocate stride-0x128 vector and move-construct elements (SEH) |
| 46e330 | `vector_reallocInsert_strElem8` | med | Reallocate stride-8 vector of string-owning elems (SEH) |
| 46e530 | `vector_reallocInsert_stride8` | med | Reallocate stride-8 vector, move elements, free old (SEH) |
| 4718b0 | `map_getTileLightOrHeight` | med | Look up tile via FUN_0042f7e0, return light/height byte at param_5 with type gating (min 5, 0xff, 0) |
| 477bf0 | `list_eraseRange` | med | Erase list node range [param_2,param_3); clear if whole, else unlink+delete |
| 4871e0 | `std::vector_resize_erase_4` | med | Resizes/erases tail of a 4-byte-element vector; memmove(_,_,0) artifact; grows via FUN_0046de30 |
| 4c9580 | `rbtree_insertValueNode` | med | Allocates a node (FUN_004c9640) and stores param value at +0x10 |
| 4e15e0 | `std::list::assign_range` | med | Copies list nodes from [param_2,param_3) into this, incrementing size; throws _Xlength_error at 0x7fffffe |
| 4e18d0 | `std::list::copy_ctor` | med | Copy-constructs list: allocates sentinel node then splices source elements via FUN_004e15e0 |
| 4e34b0 | `rbtree::alloc_node` | med | Allocates a 0x38-byte RB-tree node via operator_new, initializing 3 link slots from sentinel |
| 4e35d0 | `rbtree::destroy_recursive` | med | Recursively frees RB-tree subtree (child at +8), deleting string member at +0x14 if cap>7 |
| 4e36e0 | `rbtree::destroy_recursive_qt` | med | Recursive RB-tree subtree free calling QuestText::ctor_2 dtor then deleting node/string |
| 4e42c0 | `std::list::erase_range` | med | Erases list nodes in [param_2,param_3); relinks and frees each node and its string member |
| 4e6c60 | `rbtree::destroy_recursive_list` | med | Recursively frees RB-tree subtree destroying an embedded list member at +0x14 then node |
| 4e6d00 | `vector_u16::reallocate` | med | Reallocates a vector<uint16> to capacity param_1, memmove-copying old contents and freeing old buffer |
| 4e6d80 | `vector_u16::grow_to` | med | Ensures vector<uint16> capacity for param_1 extra, computes growth; throws 'vector<T> too long' |
| 4e7520 | `vector_u16::resize` | med | Resizes vector<uint16> to param_1 elements, growing (zero-fill) or truncating |
| 521770 | `sqlite3::exec_single` | med | Prepares and runs one SQL statement string (compute length, prepare, step), returning result code |
| 5224a0 | `sqlite3_vfs_find` | med | Finds a registered VFS by name in global list DAT_0076b3b8 under mutex |
| 523d40 | `sqlite3_log_impl` | med | Formats log message into StrAccum and dispatches to the registered log callback |
| 5240c0 | `sqlite3_str_appendf` | med | Appends a printf-formatted fragment to a StrAccum buffer via vxprintf |
| 5245e0 | `sqlite3_randomness` | med | Fills param_2 buffer with param_1 random bytes from the RC4 PRNG (FUN_00544c20) |
| 525590 | `sqlite3_open` | med | Opens a database file: forwards to openDatabase FUN_00540b70 with flags 6 |
| 525a30 | `sqlite3_error_log` | med | Emits an error log record via callback DAT_007666c4 when configured |
| 525cb0 | `sqlite3SafetyCheckOk` | med | Validates db handle magic (open/busy/sick) and returns error mask; 'API call with %s...' |
| 526480 | `sqlite3_prepare_v2` | med | Prepares an SQL statement: wrapper over FUN_0055d830 with flags 0 |
| 5267a0 | `sqlite3_bind_text` | med | Binds a text parameter: forwards to bindText FUN_0052e070 with encoding 0 |
| 526b60 | `sqlite3_bind_blob` | med | Binds a blob parameter: forwards to FUN_0052e070 with flag 1 |
| 527080 | `sqlite3_column_value` | med | Returns the Mem value for column param_2 of a stepped statement, under mutex |
| 527590 | `sqlite3_column_int` | med | Reads column value: returns int payload or a copied Mem for the requested column |
| 527610 | `sqlite3_column_int_offset` | med | Returns int column value adding row offset when the 0x4000 flag is set |
| 528070 | `sqlite3_finalize` | med | Finalizes prepared statement: resets VDBE then frees it; 'API called with finalized...' |
| 5280f0 | `sqlite3_reset` | med | Resets a VDBE program to re-executable state, clearing error/register fields under mutex |
| 528db0 | `pager::add_to_savepoint_bitvecs` | med | Marks a page number in each active savepoint's page bitvec (Bitvec set with sub-maps) |
| 52ba20 | `btree::copy_overflow_pages` | med | Copies overflow-page payload across pages when moving a cell during vacuum/balance |
| 52e070 | `sqlite3_bind_impl` | med | Binds a value into a prepared-statement parameter slot, applying affinity and error handling |
| 52e890 | `btree::release_cursor_page` | med | Releases a btree cursor's current page and unlinks from writer list; frees pager page |
| 52e950 | `btree::get_and_init_page` | med | Fetches page param_2 from pager and initializes it as a MemPage for use |
| 52ff10 | `btree::unlink_cursor` | med | Removes a cursor from its page's cursor list and clears writer/exclusive flags |
| 532670 | `sqlite3::stmt_api_exit` | med | Applies error masking and leaves db mutex on statement API exit |
| 5326d0 | `sqlite3::column_mem` | med | Returns the Mem cell for a statement column (bounds-checked), else logs misuse |
| 533ea0 | `btree::decode_page_flags` | med | Sets MemPage leaf/interior/table geometry fields from the flag byte; 'database corruption' |
| 534680 | `sqlite3::call_collation_needed` | med | Iterates schema tables invoking the collation-needed callback for unknown collations |
| 539320 | `vdbe::release_p4_value` | med | Frees a VDBE P4 auxiliary value according to its type tag (mem/keyinfo/func/vtab) |
| 539a30 | `sqlite3::hash_find_ci` | med | Case-insensitive hash bucket search returning the entry whose name matches param_3 |
| 53a7f0 | `btree::get_cell_info` | med | Parses the cell at the current cursor position into the cursor's CellInfo cache |
| 53ab00 | `btree::next_overflow_page` | med | Follows/looks up the next overflow page in a cell's chain, using the ptrmap when available |
| 53b5a0 | `pager::commit_phase_one` | med | Commits pager transaction phase one: syncs journal and writes dirty pages to the database file |
| 53bf40 | `pcache::manage_dirty_list` | med | Adds/moves a page node within the pager dirty-page linked list |
| 53dcf0 | `sqlite3::mem_malloc` | med | Allocates memory tracking usage stats, triggering soft-heap release when over the limit |
| 541270 | `pager::flush_wal_frames` | med | Flushes/checkpoints WAL frames and marks cursors stale if changes occurred |
| 5412e0 | `pager::lock_exclusive` | med | Upgrades pager file lock to EXCLUSIVE(4) via the VFS lock method |
| 541340 | `pager::lock_db` | med | Acquires the pager file lock to level param_2 via the VFS xLock |
| 541390 | `pager::write_journal_hdr` | med | Writes the journal header to the journal file after ensuring exclusive access |
| 5413e0 | `pager::unlock_if_unused` | med | Downgrades/releases the pager file lock or wal read-lock when no pages are pinned |
| 541470 | `pager::pagecount` | med | Determines database page count from the WAL header or the file size |
| 5417c0 | `pager::undo_all_dirty` | med | Undoes all dirty pages (playback one page each) during savepoint rollback |
| 541940 | `pager::playback_one_page` | med | Restores a single page from the journal into the pager during rollback |
| 541a10 | `pcache::release_page` | med | Releases a page reference, ending its transaction or freeing it when unreferenced |
| 541ab0 | `pager::wal_frames` | med | Writes a list of dirty pages as WAL frames and updates page cache/cursor state |
| 541b50 | `pager::cksum` | med | Computes the page checksum over sampled bytes for journal integrity |
| 542000 | `pager::acquire_page1` | med | Acquires and pins database page 1 for reading, allocating a page-cache slot; 'database corruption' |
| 5421b0 | `pager::open_journal` | med | Begins a write transaction: allocates the journal bitvec and opens/creates the journal file |
| 542920 | `pager::truncate_file` | med | Truncates or grows the database file to param_2 pages via VFS truncate/write |
| 542a20 | `pager::unlock` | med | Unlocks the pager: closes sub-journal file, releases file lock, resets error/state |
| 542b40 | `pager::lock_db_busy` | med | Acquires pager lock to level param_2, invoking the busy handler and retrying on SQLITE_BUSY |
| 542d70 | `pager::incr_change_counter` | med | Increments the database change counter and version fields in page 1 |
| 542df0 | `pager::write_dirty_to_wal` | med | Writes each dirty page to the WAL, updating change counter and cursor cache |
| 543f40 | `pcache1::alloc` | med | Allocates a page-cache buffer from the reuse freelist or heap, tracking stats |
| 544190 | `pcache1::free` | med | Returns a page-cache buffer to the freelist or heap, updating usage counters |
| 544570 | `pcache::remove_from_hash` | med | Removes a page node from the page-cache hash bucket and dirty/LRU lists |
| 5445e0 | `btree::ptrmap_get` | med | Reads a pointer-map entry (page type + parent page) for a given page; 'database corruption' |
| 544710 | `btree::ptrmap_pageno` | med | Computes the pointer-map page number that stores the entry for page param_2 |
| 544760 | `btree::ptrmap_put` | med | Writes a pointer-map entry for a page, reading-modifying the ptrmap page; 'database corruption' |
| 5450a0 | `pager::read_master_journal_name` | med | Reads and length/checksum-validates the master-journal name from a rollback journal |
| 5455d0 | `pager::reset_pcache` | med | Frees the pager's page-cache slot array and closes the file handle |
| 545650 | `vdbe::release_mem_array` | med | Releases an array of param_2 Mem register cells, freeing their dynamic buffers |
| 545740 | `btree::release_page` | med | Releases a btree page reference (releasePageNotNull), returning it to the page cache |
| 545b50 | `pcache1::remove_page` | med | Removes and frees a page node from the page-cache hash/LRU, decrementing counts |
| 545bb0 | `btree::shared_cache_unref` | med | Decrements a shared btree/schema refcount and frees the shared object when zero |
| 545c40 | `sqlite3::log_message` | med | Formats an error message into a StrAccum and dispatches to the log callback |
| 5472b0 | `btree::save_cursor_position` | med | Saves a cursor's key so it can be restored after tree modification, then releases its pages |
| 5489b0 | `btree::free_cell_overflows` | med | Frees the overflow-page chains of every cell on a page during page clear |
| 548d00 | `sqlite3::setup_lookaside` | med | Configures the connection's lookaside memory allocator (slot size/count), building the freelist |
| 549b00 | `sqlite3::register_builtin_functions` | med | Installs built-in functions (sqlite_rename_table/trigger) into the global function hash |
| 54a110 | `sqlite3ApiExit` | med | Masks the API result code by the connection's error mask, handling out-of-memory |
| 54ad90 | `sqlite3::run_auto_extensions` | med | Invokes each registered auto-extension init function on the new connection; 'automatic extension loading failed' |
| 54b6e0 | `btree::update_cursors_after_move` | med | Updates open cursors after a page relocation, copying overflow payload as needed |
| 54c7f0 | `btree::close_cursor` | med | Closes a single btree cursor: releases pages, unlinks from writer/cursor lists |
| 54c990 | `btree::commit_phase_two` | med | Commits phase two of a btree transaction (auto-vacuum finish, pager commit) |
| 54ca30 | `btree::rollback` | med | Rolls back a btree transaction, resetting shared page state and cursors |
| 54d260 | `btree::enter` | med | Acquires the shared btree mutex (btreeEnter), handling nested/shared-cache locking |
| 54d340 | `btree::enter_all` | med | Acquires mutexes for all attached btrees of a connection |
| 54de20 | `btree::leave_all` | med | Releases mutexes for all attached btrees of a connection |
| 54f060 | `btree::check_read_conflicts` | med | Checks for conflicting read cursors/locks before a write on the current cursor |
| 54f600 | `btree::trip_all_cursors` | med | Invalidates all cursors on a btree after an abort, releasing their pages |
| 54fcf0 | `vdbe::delete_aux_data` | med | Frees a VDBE function's auxiliary data (xDelete callbacks) and returns memory to lookaside |
| 54fdb0 | `vdbe::free_cursor_list` | med | Frees the VDBE's deferred cursor/memory free list, returning buffers to lookaside |
| 552390 | `sqlite3DbRealloc` | med | Reallocates a per-connection buffer, moving between lookaside and heap as needed |
| 5529a0 | `sqlite3_DeleteTrigger` | med | SQLite: frees a Trigger/Table object; walks step list, removes name from schema hash (DAT_007120d8 hash tab), frees exprs/selects |
| 552b20 | `sqlite3_DeleteIndexList` | med | SQLite: frees a linked list of Index structs (next at +0x20), releasing exprs, KeyInfo and id lists |
| 553a10 | `sqlite3_MarkAllCursorsInvalid` | med | SQLite: iterates btree cursor list (+4, next +0x3c) OR-ing flag 0x20 into cursor state at +0x60 |
| 55afc0 | `sqlite3_KeyInfoOrIdListFree` | med | SQLite: frees an array of pointers (IdList/KeyInfo) with lookaside accounting, then the container |
| 55da70 | `sqlite3_MallocAlarm` | med | SQLite: invokes the registered soft-heap-limit memory alarm callback with current usage |
| 55daf0 | `sqlite3_PcacheBufferSetup` | med | SQLite: initializes malloc subsystem; builds pagecache/scratch free lists from configured buffers, calls xInit |
| 55e380 | `sqlite3_MutexInit` | med | SQLite: lazily selects mutex method vtable (real vs noop by DAT_007665e4) then tail-calls xMutexInit |
| 55e900 | `sqlite3_OsClose` | med | SQLite: if handle nonzero, calls its vtable xClose (+4) and nulls the handle |
| 55e930 | `sqlite3_OsCurrentTimeInt64` | med | SQLite: gets current time as int64 ms via VFS xCurrentTimeInt64 (+0x12) or falls back to xCurrentTime*86400000 |
| 55ea60 | `sqlite3_Pcache1BufferInit` | med | SQLite: initializes the pagecache-1 bulk memory free-list from a preallocated buffer |
| 55ee50 | `sqlite3_PagerClose` | med | SQLite: closes the pager; syncs/rolls back WAL, releases page cache, closes journal and db file, frees pager |
| 55faf0 | `sqlite3_PagerBegin` | med | SQLite: begins a write transaction on the pager, acquiring reserved lock or WAL write lock |
| 55fb70 | `sqlite3_PagerReadFileHeader` | med | SQLite: zeroes buffer then reads the database file header via VFS xRead, treating short-read (0x20a) as success |
| 55fbc0 | `sqlite3_PagerSyncJournal` | med | SQLite: finalizes/syncs the journal per pager state (exclusive lock or WAL), setting IO error on failure |
| 5602d0 | `sqlite3_PagerUnrefPageOne` | med | SQLite: releases a page reference (PcacheRelease) then runs pager unref cleanup if refcount hits zero |
| 560c70 | `sqlite3_PcacheCleanAll` | med | SQLite: makes every dirty page in the cache clean (PcacheMakeClean loop), signaling the pager per page |
| 561000 | `sqlite3_PcacheMakeCleanB` | med | SQLite: variant of PcacheMakeClean; clears dirty flag and notifies pager when refcount is zero |
| 5610a0 | `sqlite3_PcacheMove` | med | SQLite: changes a page's page number (rekey via DAT_00766668) and relinks it in the dirty list if applicable |
| 5652a0 | `sqlite3_ScratchFree` | med | SQLite: frees scratch/pagecache memory; returns buffer to the scratch free-list or to xFree with status accounting |
| 5653d0 | `sqlite3_ScratchMalloc` | med | SQLite: allocates from the scratch free-list if request fits, else falls back to sqlite3Malloc with status tracking |
| 5670f0 | `sqlite3_MPrintf` | med | SQLite: formats a message via VXPrintf into a fresh db-allocated string and stores it at *param_1, freeing the old |
| 56a9b0 | `sqlite3_VMPrintfInto` | med | SQLite: formats via VXPrintf into a StrAccum backed by the caller's Vdbe/db buffer (no allocation return) |
| 56bc90 | `sqlite3_VdbeAllocErrMem` | med | SQLite: allocates and zero-initializes a 0x28-byte Mem/error record with default flags (null, enc 5) |
| 56bce0 | `sqlite3_ValueText` | med | SQLite: coerces a Mem value to text of the requested encoding, stringifying numbers and applying UTF translation |
| 56c560 | `sqlite3_VdbeFreeResources` | med | SQLite: frees a Vdbe's internal arrays (Op array, aColName, sub-programs, aVar Mem cells) with aux data cleanup |
| 574bf0 | `sqlite3_VdbeMemMakeWriteable` | med | SQLite: ensures a string Mem is NUL-terminated and its buffer is private/writable |
| 574f20 | `sqlite3_VdbeFrameRelease` | med | SQLite: unlinks/releases a Vdbe frame or RowSet stored in a Mem and resets it to null |
| 5762b0 | `sqlite3_VdbeSetNumCols` | med | SQLite: reallocates a Vdbe's result-column name Mem array (aColName) to param_2*8 cells |
| 577dd0 | `sqlite3_WalEndReadTransaction` | med | SQLite: ends a WAL read transaction, releasing the checkpoint and read-mark shared locks |
| 57a220 | `sqlite3_PcacheInitialize` | med | SQLite: initializes the default pcache implementation; queries system page size and registers the pcache group |
| 57ac30 | `sqlite3_PagerOpenJournal` | med | SQLite: begins a write transaction opening/initializing the rollback journal file and its header |
| 57e060 | `sqlite3_WalIndexClose` | med | SQLite: releases WAL shared-memory index pages, freeing heap-backed pages or invoking VFS shmUnmap |
| 57e260 | `sqlite3_WalIndexReadHdr` | med | SQLite: reads and validates the WAL-index header, triggering recovery when stale ('cannot open file' on error) |
| 57ec20 | `sqlite3_WalLimitSize` | med | SQLite: shrinks the WAL file back to a size limit via VFS truncate, reporting 'cannot limit WAL size' on failure |
| 57efa0 | `sqlite3_WalRestartLog` | med | SQLite: restarts the WAL log when fully checkpointed, bumping the salt/nCkpt and resetting read marks |
| 580010 | `sqlite3_PagerWrite32` | med | SQLite: writes a 32-bit big-endian value to the file at a given offset via the file object's xWrite (+0xc) |
| 580270 | `sqlite3_WriteMasterJournal` | med | SQLite: appends the super/master-journal filename record (with checksum) to the rollback journal |
| 58ceb0 | `WalkPath_CopyConstructVector` | med | Game/STL: copy-constructs a vector of 24-byte walk-path nodes, allocating capacity then copying (SEH-guarded) |
| 58d860 | `Map_InsertVec6` | med | Game/STL: inserts a key (FUN_00439600) and copies a 6-dword value block into the new node at +8 |
| 58e080 | `RBTree_InsertHintXY` | med | MSVC STL: std::map insert with position hint using an (x,y) key comparison, delegating to rebalance/lower_bound |
| 58e2d0 | `RBTree_InsertHintKeyed` | med | MSVC STL: std::map insert-with-hint using string key comparison (FUN_00428db0), else falls back to unique insert |
| 58e4c0 | `RBTree_InsertUniqueXY` | med | MSVC STL: std::map unique insert by (x,y) key; walks tree, checks for duplicate, then rebalances |
| 58e640 | `RBTree_InsertUniqueKeyed` | med | MSVC STL: std::map unique insert by string-compared key; locates position and rebalances or reports duplicate |
| 58e7d0 | `RBTree_LowerBoundInsertUint` | med | MSVC STL: std::map lower_bound + unique insert keyed on a uint at node+4 |
| 5946f0 | `Map_AllocSentinelNode` | med | Game/STL: allocates and self-links a 0x30-byte red-black tree sentinel/header node |
| 594720 | `MapNode_Alloc30` | med | Game/STL: allocates a 0x30-byte map node and initializes its three link pointers from in_ECX header |
| 59c800 | `std::list::eraseNode_148` | med | Relinks/erases a list node (element 0x148) via 00449c00, decrements tail pointer in_ECX+4 by 0x148 |
| 5ae040 | `std::_AdjustHeap_siftDown` | med | Heap sift-down over int-index array keyed by float at elem+0x18 (stride 0x1c), then push via FUN_005ae4a0 |
| 5ae240 | `std::_MakeHeap_byKey` | med | Builds max-heap from int-index array keyed by float at elem+0x18 (stride 0x1c) via repeated sift-down |
| 5aea90 | `std::vector<T12>::assignCopy` | med | Copy-assign vector of 12-byte elems: capacity check FUN_0044b6d0, uninitialized_copy via FUN_005ae8c0 |
| 5af160 | `std::vector<T32>::_Last_minus_one` | med | Returns end pointer minus 0x20 (address of last 32-byte element) |
| 5ef8f0 | `vector_assign_range` | med | Assigns/resizes a vector (param_1) from param_2 with optional flag param_3; memmove via external:12e |
| 5f8960 | `vector_insert_element` | med | Inserts an element into vector param_1 at param_4 (external:12e memmove) |
| 601eb0 | `list_pushBack` | med | Appends element via FUN_005a6b60 with vector grow (external:91) |
| 601f00 | `vector_pushWithGrow` | med | Pushes element into vector calling growth guard FUN_005fbc10 |
| 608a20 | `map_insertVec4Node` | med | Allocates map node (FUN_0046d590) and stores a vec4 value at +8 |
| 608a60 | `map_insertPairNode` | med | Allocates node (FUN_0046d990), zeroes +0xc, stores pair at +0x10 |
| 608a90 | `map_insertNodeSEH` | med | SEH-guarded node insert (FUN_0046d590) storing pair + FUN_00458e90 sub-init |
| 608c20 | `list_copyNode` | med | Copies a node's 3 pointers (param_1..param_3); returns param_1 |
| 608db0 | `map_insertVec4` | med | Inserts a vec4 value via FUN_00608a20 with grow (external:91) |
| 609080 | `list_buildAndFree` | med | Builds a list (FUN_00609210 alloc, FUN_00608c20 copy) freeing old (operator_delete) |
| 62fdc0 | `map_findOrInsert` | med | Finds existing key or inserts new node (FUN_0062f9b0/0062ffb0), returns node ptr |
| 62ffb0 | `map_lowerBoundInsert` | med | Locates insertion point and inserts (FUN_00630a80 alloc, FUN_0062f9b0 rebalance) |
| 636ad0 | `Node::select_glyph_by_name` | med | Recursively select/highlight the sub-glyph whose name matches param_1 in a text material (+0x34 type 3) and notify |
| 636db0 | `std::list<string>::insert_unique_sorted` | med | Insert std::string into sorted linked list at +0xe0 if not already present (memcmp dedup), 'list<T> too long' |
| 638db0 | `std::map::insert_hint_string` | med | std::map insert with hint: compare string key (FUN_00428db0) at neighbours, place or fall back to _Insert |
| 639210 | `std::map::equal_range_string` | med | Compute lower/upper bound iterator pair in string-keyed RB-tree via FUN_00428db0 compares |
| 639f40 | `std::map::insert_unique_hint_uint2` | med | Insert-unique into RB-tree with hint, key=uint pair; dispatches to 639d30 / 63a380 |
| 63a190 | `std::set::insert_unique_hint_uint` | med | Insert-unique into uint-keyed RB-tree with hint; dispatches to FUN_00452a10 / 63a4e0 |
| 63a380 | `std::map::insert_at_pos_vec2` | med | Locate insert position in vec2-keyed RB-tree and insert (639d30), freeing dup payload |
| 63a4e0 | `std::set::insert_at_pos_uint` | med | Locate position in uint-keyed RB-tree and insert (FUN_00452a10), freeing dup |
| 63c000 | `std::vector::assign_range_stride1` | med | Reallocate+assign vector from source range, element stride 4 (FUN_0063a820) |
| 63c0b0 | `std::vector::assign_range_stride2` | med | Reallocate+assign vector from source, element stride 8 (FUN_0063a850) |
| 63c160 | `std::vector::assign_range_stride4` | med | Reallocate+assign vector from source, element stride 0x10 (FUN_0063a890) |
| 63d520 | `std::vector::assign_range_stride0xc` | med | Assign vector<0xc-byte> from another, growing/shrinking with copy or relocate (SEH) |
| 6428a0 | `std::vector::default_construct_range4` | med | Loop constructing FUN_0040d9d0 over vector<4-dword> elements at +0x4c |
| 64b970 | `std::map::insert_unique_hint_int` | med | Insert-unique into int-keyed RB-tree with hint; dispatches 64b540 / 64bba0 (SEH) |
| 64bba0 | `std::map::insert_at_pos_int` | med | Locate insert position in int-keyed RB-tree and insert (64b540), freeing dup string payload |
| 64dfb0 | `std::map<int,string>::ensure_key` | med | Find int key in RB-tree, insert default empty-string entry if absent (64b970) (SEH) |
| 64e0f0 | `std::map<int,string>::ensure_key_v2` | med | Variant of 64dfb0: get-or-insert int-keyed string map entry |
| 659f50 | `std::string::assignFromString` | med | Builds a std::string copy from source string param_2 (SSO check cap>7), calls range-assign helper FUN_00452320. |
| 65a010 | `std::map::storeGlyphAt` | med | map find (FUN_0043c8e0) then writes 12-byte value (2 dwords+1 dword) from param_3 into node+8. |
| 65a040 | `std::map::insertOrAssignGuardedValue` | med | map lookup (FUN_0046d650), stores 2 dwords + string(FUN_005a7990) into found node with SEH frame. |
| 65a110 | `std::map::createNode16` | med | Allocates map node (FUN_0046d910), zeroes color at +0xc, copies 16-byte key (4 dwords) from param_1 into +0x10. |
| 65a150 | `std::map::createNodeMoveVector` | med | Allocates node (FUN_004da730), copies 2-dword key + moves a vector triple (ptr,ptr,ptr) from param_1, nulling source. |
| 65a8e0 | `std::list::initSentinel` | med | Zeroes head, allocates sentinel node (FUN_0043c870) and stores it as list head at *in_ECX. |
| 65ae80 | `RBTree::allocSentinelNode` | med | Allocates 0x20-byte tree sentinel, self-links left/parent/right, sets color+isNil word to 0x101. |
| 65b890 | `std::list::clearNodes` | med | Resets list to empty: relinks head sentinel, frees first data node (and its +0x10 buffer). |
| 65c040 | `Font::layoutAndDrawGlyphs` | med | Core glyph layout+draw: measures via FUN_0065d530, positions each char, fetches glyph, emits quads; handles 3D-mode display lists. |
| 65d3d0 | `std::map::find3KeyNode` | med | lower_bound (FUN_005c3fe0) over 3-int key at node+0x10/0x14/0x18; returns matching node or header. |
| 65d440 | `std::map::findVecKeyNode` | med | find over (int,int,int-vector) key (FUN_0065b1e0 + FUN_005a78a0 tail); returns node if exact match else header. |
| 65d4c0 | `std::map::findStringKeyNode` | med | find over string key: lower_bound (FUN_004e3790) then strncmp-style compare (FUN_00428db0, SSO cap at +0x24); returns node or header. |
| 65e340 | `Font::rasterizeGlyphBitmap` | med | Rasterizes glyph via FreeType (load/render), builds RGBA bitmap, uploads texture, caches glyph metrics struct (0x34 bytes). |
| 65e6b0 | `Font::findCachedGlyph3D` | med | RBTree find on charcode key returning cached 3D glyph at node[5]; sets in-use flag at glyph+0x30. |
| 65ea80 | `Font::rasterizeGlyph3D` | med | Rasterizes glyph with perspective/quad transform: projected bounds, area scale (sqrt), sets FT transform, renders bitmap, caches. |
| 660270 | `Font::setPixelSizeAndCacheGlyphs` | med | Sets pixel width/height (x64 fixed), calls FT set-size, and gets-or-inserts glyph nodes in size cache map allocating new entries |
| 6612f0 | `std::map::lowerBoundInsertHint` | med | Red-black tree lower_bound over string keys (strcmp via FUN_00428db0), returning insert position pair for a map/set |
| 661680 | `std::map::copyAssign` | med | Copy-assignment for a map/tree of objects: destroys existing rb-tree nodes then clones every entry from the source container |
| 661830 | `std::map::getOrInsertByKey` | med | Finds a string key via lower_bound; if absent inserts a new default-constructed rb-tree node and returns its slot |
| 661a20 | `std::map::eraseRange` | med | Erases a range of map iterators: if the whole tree, bulk-frees and resets header; otherwise erases each node in order |
| 665bd0 | `std::list::_Buynode_splice` | med | Allocates a list node (FUN_006819e0), zeroes color/flag at +0xc and swaps stored value/next/prev pointers into it |
| 666150 | `std::_Fill_0x40` | med | Fills range [param1,param2) with the 64-byte value at param_3 |
| 667dd0 | `std::map::equal_range` | med | Computes lower/upper bound iterator pair for int key (node[4]) into param_1[0],param_1[1] |
| 669250 | `std::vector::_Move_range_0x40` | med | Moves 64-byte elements [param2,param3) toward front (erase/compact), updates end ptr |
| 677660 | `std::_Rotate_0xc` | med | In-place gcd-cycle rotate of 12-byte elements around pivot param_2 |
| 677790 | `std::vector::_Copy_assign_ctor` | med | Initializes empty 12-byte-element vector (zero ptrs), stores elem meta at +0xc, then range-assigns via FUN_00677800 |
| 677970 | `std::vector::assign_0xc` | med | Sets element metadata at +0xc then range-assigns 12-byte-element vector via FUN_00677800 |
| 6779e0 | `std::vector::insertSortedKeyframe` | med | Inserts a 12-byte {ptr,int,ptr} record into a keyframe vector keeping it sorted by the int key, growing storage as needed |
| 677b00 | `std::vector<string>::uninitializedCopy` | med | Uninitialized-copies a range of ~0x1c-byte string records into destination, assigning each and copying trailing dword at +0x18 |
| 677e90 | `std::vector<string>::findOrAppendNamed` | med | Searches a 0x1c-elem vector at in_ECX+0x24 for entry whose id(+0x18)==param_2 and name(+0x10)==param_1, else appends new entry |
| 677fa0 | `std::vector<string>::insertAt` | med | Inserts a default-initialized 0x1c-byte string element at position param_1, growing storage if at capacity |
| 67eb10 | `std::_Tree::eraseRange` | med | Erases red-black tree nodes over range [param_2,param_3) walking in-order successor, then returns the stop node |
| 67fa60 | `std::map::insertWithHint` | med | Inserts a keyed node into a red-black tree using param_2 as position hint, validating against neighbors before falling back to unique insert |
| 67fc90 | `std::map::insertUnique` | med | Descends the red-black tree to locate insertion point for key, inserting a new node unless an equal key already exists |
| 681890 | `std::map::findOrInsert` | med | Red-black tree operator[]: finds node for key *param_1 returning value ptr (node+5), otherwise inserts a new default-valued node |
| 681b70 | `std::list::clearNodesWithStrings` | med | Clears a list/tree whose data node embeds two std::strings, freeing each string buffer then the node |
| 681bf0 | `std::vector::pushBack8byte` | med | Appends (or inserts a copy of) an 8-byte pair element into a vector, growing storage if at capacity |
| 688b20 | `list_allocNode` | med | Allocates a 0x48-byte list node via operator_new, links prev/next pointers (self-link if null) |
| 68d85f | `eh_vector_dtor_iterator_helper` | med | MSVC EH vector destructor unwind helper; calls __ArrayUnwind on partially destructed array |
| 68db1c | `eh_vector_ctor_iterator_helper` | med | MSVC EH vector constructor unwind helper; calls __ArrayUnwind on partially constructed array |
| 68f810 | `ft_size_reset_bitmap` | med | FreeType: select bitmap strike by index, calling driver select_size hook or fallback 68f560 |
| 68fd30 | `ft_reset_active_charmap_cache` | med | FreeType: refresh cached charmap (face+0xa4) if it doesn't match current encoding at EDX+0x48 |
| 690880 | `ft_glyphloader_node_init` | med | FreeType: initialize a loader/glyph node: set two fields, zero offsets [2],[5],[6],[8] |
| 6908a0 | `ft_call_done_hook` | med | FreeType: invoke object's finalizer function pointer at +0x18 if set |
| 691600 | `ft_glyphslot_clear_bitmap` | med | FreeType: free owned glyph bitmap (if cache flag set), clear slot+0x58 pointer |
| 691670 | `ft_glyphslot_clear_fields` | med | FreeType: clear glyph slot bitmap then zero out ~30 slot metric/outline fields |
| 691b00 | `ft_charmap_node_done` | med | FreeType: run charmap destroy hook (+8) then free charmap node |
| 691b90 | `FT_CMap_Activate` | med | FreeType: move charmap node up in list, mark 'outl' cache, run init callback param_3 times |
| 691da0 | `FT_Bitmap_Done` | med | FreeType: FT_Bitmap_Done wrapper validating library then FT_Bitmap_Free |
| 6923a0 | `ft_alloc_charmap_obj` | med | FreeType: allocate a 0x60-byte charmap/glyph object and store owner pointer |
| 6923d0 | `ft_glyphloader_add_glyph` | med | FreeType: create glyph object variant (advance/subglyph/data) based on flags, or copy file data |
| 6924b0 | `ft_glyphslot_internal_init` | med | FreeType: allocate glyph slot internal (0x28) and charmap obj, run slot init hook |
| 692960 | `ft_free_charmap_array` | med | FreeType: destroy each charmap node in face's charmap array then free the array |
| 692be0 | `ft_new_charmap_node` | med | FreeType: allocate a 0x28 charmap descriptor node, init two fields plus encoding at +0x18 |
| 693580 | `TT_Load_TTC_SubHeader` | med | FreeType: parse SFNT/TTC header offsets, detect duplicate/mac-resource layout, resolve face offset |
| 694170 | `FT_New_BitmapGlyph_Buffers` | med | FreeType: allocate three parallel per-glyph arrays (8/1/2 byte elems) sized param_2/param_3, set flag |
| 694270 | `TT_Load_CMap_Subtable` | med | FreeType: load & qsort a cmap/loca-style lookup subtable, matching param_5 selector, add base offset |
| 6947e0 | `ft_probe_type1_header` | med | FreeType: read font header block, validate Type1 magic/field bytes, dispatch open at aligned size |
| 6948f0 | `ft_probe_font_drivers_table` | med | FreeType: iterate a table of 9 format-probe callbacks (via seek), invoking each to detect format |
| 6949d0 | `ft_try_open_all_formats` | med | FreeType: loop over 9 candidate driver clazzes, alloc glyph obj and attempt open, cleaning up on fail |
| 694b00 | `ft_probe_and_open_font` | med | FreeType: run header probe (6947e0), then format open, then multi-driver fallback if flag set |
| 695200 | `ft_new_glyph_obj` | med | FreeType: allocate a glyph object of clazz-specified size, set owner/clazz fields |
| 695d60 | `ft_stroke_move_to` | med | FreeType: begin a new subpath in the stroker/outline (close prev, record start) |
| 695e80 | `ft_outline_merge_points` | med | FreeType: append one glyph's points/tags/contour-ends into an accumulating outline (memcpy) |
| 695f10 | `ft_new_outline_obj` | med | FreeType: allocate a 0x78-byte outline/stroker object and init two builders |
| 695f60 | `ft_stroker_reset_two` | med | FreeType: reset a pair of outline builders (both subpaths) |
| 695f80 | `ft_free_outline_obj` | med | FreeType: free the two builders of an outline object then free it |
| 6964d0 | `ft_stroke_arc_both_sides` | med | FreeType(smooth): emit an arc offset to both stroke sides using From_Angle + move/line |
| 696620 | `ft_stroke_conic_recursive` | med | FreeType(stroker): recursively subdivide+stroke a conic curve, emitting conic control pts both sides |
| 696830 | `ft_stroke_cubic_recursive` | med | FreeType(stroker): recursively subdivide+stroke a cubic curve emitting cubic control pts both sides |
| 696b20 | `ft_stroke_reverse_subpath` | med | FreeType(stroker): copy+reverse a stroked subpath's points/tags into the other border, flipping on/off tags |
| 696ce0 | `ft_outline_get_counts` | med | FreeType: compute total contour and point counts for a stroked outline (both borders) |
| 696d50 | `ft_stroke_export_border` | med | FreeType: export one stroker border (index 0/1) into the outline if valid |
| 696d80 | `ft_stroke_export_both` | med | FreeType: export both stroker borders into the final outline |
| 6971a0 | `ft_stroker_set_params` | med | FreeType(stroker): store stroker parameters (radius/cap/join fields) and reset builders |
| 6cf8e0 | `vorbis_read_setup_header` | med | Vorbis(audio): dispatch reading the setup header sub-packets (codebooks/floors/residues/mappings) |
| 6cfa70 | `vorbis_read_setup_maps_modes` | med | Vorbis: parse setup header: codebooks, times, floors, residues, mappings, and modes into setup struct |
| 6cfd50 | `vorbis_read_residue_config` | med | Vorbis: parse a residue configuration: classifications, cascade books, per-class books |
| 6cffb0 | `vorbis_free_setup` | med | Vorbis(audio): free entire setup structure - codebooks, floors, residues, mappings, modes |
| 6d0270 | `vorbis_get_serial_or_index` | med | Vorbis: return setup table entry at index, or -1 if setup absent |
| 6d0290 | `vorbis_free_residue_arrays` | med | Vorbis: free a residue/floor decode buffer group (4 owned pointers) |
| 6d0420 | `vorbis_get_codebook_dim_log` | med | Vorbis: return the global codebook dimension-log field (setup+0xe48) |
| 6d0470 | `vorbis_decode_mode_mapping` | med | Vorbis: read packet mode bit and window flags, resolve mode->mapping table entry |
| 6d0500 | `vorbis_start_packet_decode` | med | Vorbis: initialize per-packet decode state (mode, window flags, floor/residue selection) |
| 6d0bb0 | `vorbis_apply_window_overlap` | med | Vorbis(audio): float overlap-add / window application combining previous and current MDCT blocks |
| 6d1220 | `vorbis_init_decoder` | med | Vorbis: initialize decoder buffers; on failure free via 6d12e0, else reset state |
| 6d1920 | `vorbis_free_bitreader_state` | med | Vorbis: free bit-reader/huffman scratch (0x68 block, 15 sub-buffers), zero 0x70 state |
| 6d19d0 | `vorbis_init_bitreader_state` | med | Vorbis: init bit-reader/huffman scratch: alloc 0x48 ctx and 15 x 0x14 sub-buffers with 0x100 byte bufs |
| 6d1c20 | `vorbis_floor0_synth_curve` | med | Vorbis(floor0): synthesize floor0 LSP curve into float output using amplitude/scale (ldexp) |
| 6d21b0 | `vorbis_build_codebook_table` | med | Vorbis: build fast Huffman decode table for a codebook, bit-reversing codewords (SSE pmulld/bswap) |
| 6d29b0 | `vorbis_free_codebook_buf` | med | Vorbis: free a codebook's two owned buffers and the codebook node |
| 6d6490 | `vorbis_free_mapping` | med | Vorbis(audio): free a channel mapping structure (submaps, coupling arrays, matrices) |
| 6d8900 | `vorbis_free_floor` | med | Vorbis(audio): free a floor decode structure's buffers (0xb4 bytes) including 7 sub-arrays |
| 6da1b0 | `vorbis_free_residue_book` | med | Vorbis(audio): free a residue book helper's two owned buffers then zero header |
| 42be50 | `resizeChildBuffers_type16` | low | Same as 0042be00 but drives 16-byte-element vector resize helper 0042bf80 over child buffers |
| 4453b0 | `rbtree::traverseInorder` | low | Walks map/set (+0x139c) in-order performing no visible work (traversal/count stub) |
| 4689a0 | `rbtree_eraseByStringKey` | low | Erase map entry matched by string key (FUN_004e3790 hash, FUN_00428db0 compare); frees temp strings |
| 4e2a00 | `unwind_delete_member` | low | Exception unwind funclet: destructs sub-object then operator_delete of member pointer at ECX+0x20 |
| 522700 | `sqlite3_mutex_enter_maybe` | low | Enters mutex param_1 (via DAT_00766630) if non-null |
| 522740 | `sqlite3_mutex_leave_maybe` | low | Leaves mutex param_1 (via DAT_00766638) if non-null |
| 523d10 | `sqlite3_log` | low | Auto-inits library then forwards to log formatter FUN_00523d40 |
| 532e30 | `sqlite3::pager_has_content` | low | Returns whether the pager has an open transaction or any dirty page |
| 5399e0 | `pager::free_tmp_space` | low | Frees the pager's temporary page-copy buffer at +0x50 |
| 540b30 | `pager::pagecount_from_size` | low | Computes page count from file size and page-size fields |
| 5411b0 | `pager::zero_journal_header` | low | Zeroes/initializes the in-memory journal-header buffer for the pager |
| 541900 | `pager::sync_file_size` | low | Locks the file and queries its size, storing into the pager (+0x50) |
| 541a70 | `pager::unlock_db_vfs` | low | Releases the pager file lock via VFS xUnlock to level param_2 |
| 541fd0 | `pager::set_error_state` | low | Latches an I/O/full error into the pager's persistent error state |
| 542180 | `pcache::fetch_no_create` | low | Looks up a page in the page cache without creating it |
| 5428f0 | `pager::invalidate_cursors` | low | Marks all page cursors stale and rolls back the page cache |
| 548bd0 | `pager::set_sector_size` | low | Determines and stores the device sector size from the VFS, clamped to page-size range |
| 54ddf0 | `btree::leave_lock` | low | Releases the shared btree lock/mutex reference count |
| 54f780 | `pager::report_cantopen` | low | Logs and returns SQLITE_CANTOPEN(0xe); 'cannot open file at line %d of [%.10s]' |
| 551190 | `sqlite3::report_corrupt` | low | Logs and returns SQLITE_CORRUPT(0xb) at the given line; 'database corruption at line %d' |
| 556ba0 | `sqlite3_ColumnDefault` | low | SQLite: returns pointer to per-column slot within a page/cursor buffer at base + (col*5-5)*4 |
| 5581b0 | `sqlite3_DeleteColumnNames` | low | SQLite: part of table teardown; walks column list (+0x10), removes names from a hash, frees index KeyInfo/exprs |
| 55d180 | `sqlite3_LeaveSchemaAndClose` | low | SQLite: full connection teardown; validates magic 0x64cffc7f, clears page cache, schema hashes, savepoints, frees db |
| 55e010 | `sqlite3_StrAccumInitStatic` | low | SQLite: zero-inits a 5-dword struct (Mem/StrAccum) and sets its vtable pointer to &DAT_00712500 |
| 55ea00 | `sqlite3_OsSectorSizeCall` | low | SQLite: thin VFS/method dispatcher calling vtable slot +8 with five arguments |
| 55ea20 | `sqlite3_OsMethod0x10` | low | SQLite: thin dispatcher calling object vtable slot +0x10 with two arguments |
| 55ea40 | `sqlite3_OsMethod0xc` | low | SQLite: thin dispatcher calling object vtable slot +0xc with five arguments |
| 55f260 | `sqlite3_PagerSync` | low | SQLite: syncs the database file if in the proper journal/lock state, setting IO error state on failure |
| 560030 | `sqlite3_PagerPlaybackOrCommit` | low | SQLite: transaction finalize/rollback driver; syncs, reads/compares master journal cksum, commits or rolls back changecounter |
| 560280 | `sqlite3_PagerFileSync` | low | SQLite: syncs the db file through the VFS (xSync +0x14, or xFileControl +0x28 op8 in WAL/atomic mode) |
| 560330 | `sqlite3_PagerWritePagelist` | low | SQLite: writes/flushes a run of pages spanning a sector; fetches and cleans each affected page, marking need-sync |
| 561110 | `sqlite3_PcacheErrorCallback` | low | SQLite: if error code set at +0x28, invokes the global page-error handler DAT_0076665c |
| 5644e0 | `sqlite3_VdbeMemReleaseChain` | low | SQLite: frees a linked chain of allocations held by a Mem/aux object with lookaside accounting, then resets its fields |
| 5682d0 | `sqlite3_VdbeReprepareSwap` | low | SQLite: swaps runtime column/binding Mem cells between an old and freshly reprepared Vdbe, finalizing old externals |
| 56b910 | `sqlite3_VdbeMemFreeAndDestroy` | low | SQLite: releases a Mem's external resources (+7 flags 0x2460) and frees its dynamic buffer and the object |
| 573e30 | `sqlite3_VdbeListExec` | low | SQLite: pseudo-execution producing a column/index listing result set (EXPLAIN-like), builds Mem result cells |
| 577190 | `sqlite3_DeleteTriggerAux` | low | SQLite: teardown helper (called from DeleteTrigger); detaches WAL/trigger sub-state and frees an id-array |
| 5776d0 | `sqlite3_SchemaResetCursors` | low | SQLite: releases a schema-cookie/holder list (+0x13c) and marks all btree cursors stale (flag 0x20) |
| 577740 | `sqlite3_WalTryBeginRead` | low | SQLite: WAL begin-read-transaction retry loop; scans read-mark slots, acquires shared locks, verifies wal-index header |
| 5785a0 | `sqlite3_WalUndo` | low | SQLite: rolls back WAL frames beyond a savepoint, invoking a callback per undone page and cleaning the hash |
| 57a480 | `sqlite3_DeleteTriggerStepList` | low | SQLite: frees a Trigger's step list (from DeleteTrigger); releases per-step exprs/selects/target names |
| 57a8b0 | `sqlite3_PagerPageInJournal` | low | SQLite: tests whether pages are present in the pager savepoint bitvec set (walk of sub-bitvecs) |
| 57a9b0 | `sqlite3_SubjournalPage` | low | SQLite: writes a page's original content into the statement sub-journal, appending record with checksum |
| 57d3f0 | `sqlite3_PcacheGroupUnlink` | low | SQLite: unlinks a pcache instance from the global pcache group linked list (next at +0xc) |
| 57d830 | `sqlite3_WalDetachPagers` | low | SQLite: partitions a wal-attached pager list, splitting out entries matching a given db and relinking the rest |
| 57d880 | `sqlite3_WalBusyLock` | low | SQLite: acquires a WAL lock retrying through a busy-handler callback until success or non-busy error |
| 57d8d0 | `sqlite3_WalCheckpointCopy` | low | SQLite: checkpoint inner loop; iterates the WAL via an iterator copying frames back into the db file |
| 57f130 | `sqlite3_WalTryBeginReadB` | low | SQLite: WAL begin-read attempt; validates wal-index header, selects a read-mark slot and takes its shared lock |
| 57f400 | `sqlite3_WalUnlockShared` | low | SQLite: releases a WAL shared lock slot via the file's shmLock method (+0x38) when not in exclusive mode |
| 5830c0 | `sqlite3_PagerTruncateFile` | low | SQLite: truncates the database file to the pager's expected size, using zero-write or xTruncate per config |
| 583cd0 | `std_string_AssignRange` | low | MSVC STL: assigns a byte range [param_1,param_2) into a std::string, resizing and pushing each char (SEH-guarded) |
| 5842d0 | `Vector_ConstructResize` | low | MSVC STL: zero-inits a std::vector header then resizes it via FUN_005870c0 |
| 58ce60 | `WalkPath_CopyNodes` | low | Game/STL: copies an array of 6-dword path nodes from [param_1,param_2) into param_3 |
| 58d7a0 | `WString_Concat` | low | MSVC STL: concatenates two wide strings (stride 2) into a result string, reserving combined length (SEH) |
| 59f0a0 | `WalkPathBehavior::isAreaWalkable` | low | Tests a randomized AABB region (half-extents param_2) for solid voxels to decide if the creature can walk there |
| 59f850 | `WalkPathBehavior::sampleStepCollision` | low | Samples voxels in a random-offset box around param_1 to detect a solid collision along a candidate step |
| 608b30 | `map_insertFromField` | low | Inserts via FUN_00608db0 using field from in_ECX (SEH-guarded) |
| 60aa70 | `map_insertViaSub` | low | Inserts via FUN_00608a90 with grow (external:91) |
| 624900 | `codec_decodeCodebook` | low | Decodes a codebook/header entry (FUN_00624790/006247f0); returns 64-bit value |
| 624a70 | `codec_decodeResidueA` | low | Decodes a residue/vector stage of audio codec (FUN_004010f0/00401060) |
| 624f80 | `codec_decodeResidueB` | low | Decodes a residue stage variant (FUN_006d0470, FUN_004015c0) |
| 64e520 | `std::vector::insert_n_stride0x10` | low | Insert n 0x10-byte (matrix) elements at position, reallocating/shifting as needed (SEH, big) |
| 653ad0 | `Widget::deserialize_children_tree` | low | Recursively deserialize a widget's child widget list and attribute chunks from istream (nested chunk loop, big) |
| 694250 | `FT_BitmapGlyph_Init_wrapper` | low | FreeType: null-checked wrapper around 694170 buffer allocation |
| 6cf9e0 | `vorbis_validate_packet_crc` | low | Vorbis: validate/consume a packet field, signal error via bit-skip on mismatch |
| 6d0300 | `vorbis_init_pcm_struct` | low | Vorbis: zero a 2-word (undefined8[2]) pcm/output descriptor |

## other (799)

| addr | proposed name | conf | purpose |
|---|---|---|---|
| 401c40 | `oggpack_write` | high | libogg bitwise: write param_3 bits of param_2 into oggpack_buffer (mask DAT_00745d00) |
| 401f80 | `string_moveConstruct` | high | MSVC std::string move-construct: moves SSO/heap buffer, transfers size/cap, resets source |
| 4043c0 | `string_lessCompare` | high | std::string comparator: returns true if key1 < key2 (memcmp via FUN_0040c520) |
| 40d800 | `uivm_pop_operand` | high | Pops top operand off VM stack: destroys via FUN_004034c0, operator_delete, decrements +0x30 |
| 40ef20 | `std::basic_ostream<wchar_t>::_Osfx_unwind` | high | ostream sentry cleanup: _Osfx if not uncaught, tie flush |
| 427a80 | `zeroVec3Array` | high | Zeroes param_2 vec3 (12-byte) elements starting at param_1 |
| 428a60 | `vectorGrowCap8` | high | std::vector _Grow capacity calc for 8-byte elements (1.5x, cap 0x1fffffff) |
| 42c8d0 | `int64::less` | high | Signed compare *param_1 < *param_2 (two int64), returns bool |
| 439510 | `std::wstring::_Tidy_dtor_unwind` | high | free wstring buffer during unwind |
| 43c380 | `std::map::dtor` | high | destroy map: erase-all range then free head |
| 43c3b0 | `std::map::dtor_variant` | high | destroy map via _Erase range then free head |
| 44a8c0 | `copyAssign_0x148Fields` | high | Copy 0x148-struct fields (+0x118..+0x144) from param_1 to ecx, first via 0040ee70 |
| 44a9f0 | `std::string::_Tidy_unwind` | high | free narrow-string buffer (cap 0xf) during unwind |
| 44b3b0 | `copyAssign_0x148Fields_5e0` | high | Copy 0x148-struct key fields (+0x118..+0x144) via 0042c5e0, twin of 44a8c0 |
| 44b5a0 | `mapCompare_intStrKey` | high | Comparator: less-than on int key then string (memcmp 0040c520) |
| 44bde0 | `allocRawArray_0x148` | high | Allocate raw uninitialized param_1*0x148 buffer; throws length/bad_alloc |
| 450d90 | `std::_Func_class::_Tidy` | high | destroy std::function target via vtable +0x10 |
| 450e00 | `std::function::invoke_and_delete` | high | invoke std::function (_Xbad_function_call) then destroy+free |
| 4514b0 | `std::string::operator==_cstr` | high | compare narrow string to C-string equality (cap 0xf) |
| 451550 | `std::string::ctor_cstr` | high | construct narrow std::string from char* C-string |
| 4516e0 | `std::string::assign_cstr` | high | assign/reserve narrow string from char* (self-alias safe) |
| 451940 | `heap_siftDown_0x128` | high | Binary-heap sift-down for 0x128 elements keyed by byte+short*6, then push via 00455860 |
| 451b10 | `heap_siftDown_0xc_float` | high | Binary-heap sift-down for 0xc elements keyed by float at +4 |
| 451bf0 | `allocMapNode_ctorStrKey` | high | Allocate 0x48 map node, zero color, construct string key via 00457800 |
| 4522a0 | `node_ctor_3dword` | high | Construct node via 0046d910, zero color, copy 3 dwords into node+0x10 |
| 4522e0 | `std::map::insert_val_obj5` | high | insert map node, copy 2 dwords + object member |
| 452500 | `string_copyRange_0x18` | high | Copy string range stride 0x18 via 0040f680 |
| 452e30 | `std::_Tree<int>::_Insert_node` | high | Links new node into red-black tree and rebalances via left/right rotations & recolor (RB fixup) |
| 453670 | `std::_Tree<__int64>::insert` | high | map/set insert, 64-bit key variant (2nd instantiation); same logic as 453420 |
| 453c90 | `std::_Tree<__int64>::_Insert_hint` | high | Insert-with-hint, 64-bit key (2nd instantiation) |
| 454e30 | `insertionSort_0xc_float` | high | Insertion sort of 0xc elements keyed by float at +4 |
| 454ef0 | `makeHeap_0x128` | high | build_heap over 0x128 elements via sift 00451940 |
| 455070 | `makeHeap_0xc_float` | high | build_heap over 0xc elements keyed by float +4 |
| 4551b0 | `sort3_0x128` | high | Median-of-3 ordering of three 0x128 elements by byte+short*6 key, swap via 00458c10 |
| 455340 | `sort3_0xc_float` | high | Median-of-3 ordering of three 0xc elements by float+4, in-place swap |
| 4553c0 | `medianOf9_0x128` | high | Ninther (median-of-medians) pivot selection for 0x128 introsort via 004551b0 |
| 455510 | `medianOf9_0xc` | high | Ninther pivot selection for 0xc introsort via 00455340 |
| 4556b0 | `moveBackward_0x128` | high | Move-backward copy of 0x128 range via 0042c5e0/00468050 |
| 455760 | `popHeap_sift_0x128` | high | pop_heap: move top to back then sift 00451940 for 0x128 elements |
| 455860 | `pushHeap_siftUp_0x128` | high | push_heap sift-up for 0x128 elements keyed by byte+short*6 |
| 4559c0 | `rotate_0x10` | high | std::rotate of 0x10-byte elements using gcd-cycle algorithm |
| 455ac0 | `rotate_0x148` | high | std::rotate of 0x148 elements via gcd-cycle with 0044a8c0/0044b3b0 temp |
| 456160 | `quicksortPartition_0x128` | high | Hoare-style partition for 0x128 introsort keyed byte+short*6, swaps via 00458c10 |
| 456710 | `quicksortPartition_0xc` | high | Hoare partition for 0xc introsort keyed by float+4 |
| 456ae0 | `string_destroyRange_0x18` | high | Destroy std::string range stride 0x18 (reset SSO + 0040f680), SEH |
| 456d30 | `std::_Destroy_range<0x78>` | high | Destroy count of 0x78-byte elements (dtor FUN_00466590) |
| 456ee0 | `std::_Uninitialized_copy<0x78>` | high | Copy-construct 0x78-byte elements (copy-ctor FUN_00468790) |
| 456f20 | `copyPackedRange_6to8` | high | Copy 6-byte-stride source into 8-byte-stride dest (unpack) fields |
| 456f70 | `copyRange_2dword` | high | Copy 2-dword elements [param_1,param_2)->param_3 |
| 457040 | `moveVec3Range` | high | Move 3-dword (vec3) elements zeroing source |
| 457800 | `string_moveCtorNode` | high | Move-construct 0x48 map-node string key: steal SSO buffer and reset source |
| 458c10 | `swapElem_0x128` | high | Swap two 0x128 elements using 280-byte temp (0042c5e0/00468050) |
| 4594c0 | `Object_copyAssign_off118` | high | Copy-assign: base copy FUN_0040ee70 then fields at 0x118-0x12a (transform/flags block) |
| 4595b0 | `Struct_copy_1cDwords` | high | Field-by-field copy of ~0x1c dwords plus byte fields at 0x17/0x19 |
| 4599a0 | `Struct_copy_47Bytes` | high | Field copy ~0x11 dwords plus trailing bytes at 0x45/0x46 |
| 465c00 | `Struct_copy_0dDwords` | high | Copy ~0xd dwords plus bytes at 9/0x25 |
| 465ce0 | `Struct_copy_2dDwords` | high | Copy ~0x2e dwords (incl 0x10-count memcpy loop) plus bytes |
| 465e60 | `Struct_copy_10Dwords` | high | Copy 0x11 dwords |
| 466410 | `Struct_copy_withStringInit` | high | Copy ~0xe dwords, set +0x13=7/+0x12=0, init string via FUN_0040f680 |
| 466aa0 | `operator_delete@unwind` | high | SEH unwind funclet: operator delete(*this) |
| 468b70 | `std::map<__int64,V>::operator[]` | high | operator[] for 64-bit key with large mapped type (alloca 0x22e4 temp value) |
| 468fa0 | `std::vector<T0x148>::operator[]` | high | Return &base[i] for 0x148-byte element vector (*this + i*0x148) |
| 46d1c0 | `less_pair_int` | high | Lexicographic less-than over (x,y) int pair; returns 1 if param_1<param_2 |
| 46d950 | `std::_Tree<>::_Buyheadnode` | high | operator new 0x1180 head node; self-link 3 pointers |
| 46dd90 | `std::vector<T120>::_Calculate_growth` | high | Compute grown capacity for 120-byte(0x78) element vector |
| 46e970 | `std::vector<T24>::reserve` | high | Grow 24-byte-element vector capacity if needed |
| 486380 | `std::list<T>::push_back` | high | Append node (elem via FUN_00451cc0), ++size |
| 4a9320 | `insertion_sort_ptr_key6c` | high | Insertion sort of pointer array keyed by float at +0x6c; uses memmove |
| 4a93c0 | `insertion_sort_12_key4` | high | Insertion sort of 12-byte elements keyed by float at +4 |
| 4a9470 | `insertion_sort_16_key8` | high | Insertion sort of 16-byte elements keyed by float at +8 |
| 4a9520 | `insertion_sort_48_key2c` | high | Insertion sort of 48-byte elements keyed by float at +0x2c; SEH cookie |
| 4a9ad0 | `median3_12_key4` | high | Sorts three 12-byte elements by float at +4 (median-of-3) |
| 4a9b50 | `median3_16_key8` | high | Sorts three 16-byte elements by float at +8 (median-of-3) |
| 4a9bf0 | `guess_median_ptr_key6c` | high | Median/pseudo-median (ninther) pivot selection for pointer array keyed float+0x6c |
| 4a9db0 | `guess_median_12` | high | Median-of-3-or-9 pivot for 12-byte elements via FUN_004a9ad0 |
| 4a9e60 | `guess_median_16` | high | Median-of-3-or-9 pivot for 16-byte elements via FUN_004a9b50 |
| 4a9f00 | `guess_median_48` | high | Median-of-3-or-9 pivot for 48-byte elements; swaps via FUN_004abb10 |
| 4aa980 | `partition_ptr_key6c` | high | Quicksort 3-way partition of pointer array keyed float+0x6c |
| 4aabd0 | `partition_12_key4` | high | Quicksort 3-way partition of 12-byte elements keyed float+4 |
| 4aaeb0 | `partition_16_key8` | high | Quicksort 3-way partition of 16-byte elements keyed float+8 |
| 4ab190 | `partition_48_key2c` | high | Quicksort 3-way partition of 48-byte elements keyed float+0x2c; SEH cookie |
| 4abb10 | `swap_48` | high | Swaps two 48-byte (11-dword) elements |
| 4c9550 | `_fseeki64_wrapper` | high | Guarded wrapper around CRT _fseeki64 (returns -1 on NULL file) |
| 4cef80 | `Options_saveToCfg` | high | Save game settings to options.cfg via ofstream (fullscreen,resolution,volumes,cameraSpeed,language...) |
| 4e0080 | `QuestText_allocNode_2str` | high | Allocates a QuestText node (FUN_00630a40) and initializes two embedded strings from param |
| 51ca20 | `likeFunc` | high | SQLite 3.7.15.2 likeFunc: identified by compiler-independent string-anchor match (2 unique-owner string anchors, score 10.0). Anchors: ESCAPE expression must be a single character\|LIKE or GLOB pattern too complex |
| 51cbf0 | `winShmMap` | high | SQLite 3.7.15.2 winShmMap: identified by compiler-independent string-anchor match (3 unique-owner string anchors, score 15.0). Anchors: winShmMap1\|winShmMap2\|winShmMap3 |
| 51ce10 | `sqlite3_aggregate_context` | high | Return/allocate per-aggregate context memory of given size (zeroed on first call) |
| 51ce90 | `sqlite3_user_data` | high | Return function's user-data pointer (pApp at *ctx+4) |
| 51cea0 | `sqlite3_context_db_handle` | high | Return sqlite3* db handle for a function context (ctx+8) |
| 51d0e0 | `sqlite3_result_error_toobig` | high | Set function-result error to SQLITE_TOOBIG with 'string or blob too big' message |
| 51d170 | `sqlite3_result_error_code` | high | Set result error code and message string (errstr table; 'abort due to ROLLBACK'/'unknown error') |
| 51d400 | `winSetSystemCall` | high | SQLite os_win xSetSystemCall: override a win32 syscall pointer by name (AreFileApisANSI, CharLowerW...) |
| 51d5e0 | `winGetSystemCall` | high | SQLite os_win xGetSystemCall: return current win32 syscall pointer by name |
| 51d650 | `sqlite3_quoteFunc` | high | SQL quote() function: format value as SQL literal (NULL, real, ''-escaped text, X'..' blob) |
| 51da30 | `winNextSystemCall` | high | SQLite os_win xNextSystemCall: iterate to next overridable win32 syscall name (CharUpperW...) |
| 51dc70 | `sqlite3_hexFunc` | high | SQL hex() function: encode blob argument as uppercase hex text; 'string or blob too big' on overflow |
| 51f1f0 | `datetimeFunc` | high | SQL datetime(): format '%04d-%02d-%02d %02d:%02d:%02d' |
| 51f3c0 | `timeFunc` | high | SQL time(): format '%02d:%02d:%02d' |
| 51f4c0 | `detachFunc` | high | SQLite 3.7.15.2 detachFunc: identified by compiler-independent string-anchor match (4 unique-owner string anchors, score 20.0). Anchors: cannot DETACH database within transaction\|cannot detach database %s\|database %s is locked\|no such database: %s |
| 51f790 | `dateFunc` | high | SQL date(): format '%04d-%02d-%02d' |
| 51f970 | `strftimeFunc` | high | SQL strftime(): full format-spec date/time formatter |
| 5201b0 | `winAccess` | high | os_win.c winAccess: GetFileAttributes existence/perm check |
| 520ea0 | `winFullPathname` | high | SQLite 3.7.15.2 winFullPathname: identified by compiler-independent string-anchor match (5 unique-owner string anchors, score 25.0). Anchors: %s\%s\|GetFullPathNameA1\|GetFullPathNameA2\|GetFullPathNameW1 |
| 5218b0 | `winDlOpen` | high | os_win.c winDlOpen: LoadLibrary A/W |
| 522480 | `winDlSym` | high | os_win.c winDlSym: GetProcAddress |
| 522680 | `winDlClose` | high | os_win.c winDlClose: FreeLibrary |
| 522690 | `winClose` | high | os_win.c winClose: CloseHandle with retry loop |
| 522760 | `winRandomness` | high | os_win.c winRandomness: seed from time/PID/perfcounter |
| 522830 | `winRead` | high | os_win.c winRead: ReadFile with lock-retry |
| 522bc0 | `winSleep` | high | os_win.c winSleep: Sleep(ms) |
| 522c50 | `winCurrentTimeInt64` | high | os_win.c winCurrentTimeInt64: FILETIME to JD ms |
| 523070 | `winWrite` | high | os_win.c winWrite: WriteFile with lock-retry |
| 5231c0 | `winCurrentTime` | high | os_win.c winCurrentTime: FILETIME to julian day double |
| 5232d0 | `sqlite3_complete` | high | SQLite 3.7.15.2 sqlite3_complete: identified by compiler-independent string-anchor match (3 unique-owner string anchors, score 16.0). Anchors: create\|explain\|temporary\|trigger |
| 5239d0 | `winTruncate` | high | SQLite 3.7.15.2 winTruncate: identified by compiler-independent string-anchor match (2 unique-owner string anchors, score 10.0). Anchors: winTruncate1\|winTruncate2 |
| 523a80 | `sqlite3_get_table` | high | sqlite3_get_table: exec+accumulate rows into string array |
| 524120 | `winSync` | high | os_win.c winSync: FlushFileBuffers |
| 524570 | `winFileSize` | high | os_win.c winFileSize: GetFileSize |
| 524800 | `sqlite3_backup_init` | high | sqlite3_backup_init: 'source and destination must be distinct' |
| 5264c0 | `winUnlock` | high | os_win.c winUnlock: release file lock |
| 527740 | `winOpen` | high | os_win.c winOpen: CreateFile A/W open file handle |
| 527b60 | `winDelete` | high | os_win.c winDelete: DeleteFile with retry |
| 528350 | `sqlite3_mutex_alloc_win` | high | Win32 mutex alloc: for recursive/fast types allocate+InitializeCriticalSection, else return static mutex |
| 528470 | `sqlite3_mutex_free_win` | high | Win32 mutex free: DeleteCriticalSection then free the allocated mutex |
| 528530 | `sqlite3_mutex_enter_win` | high | Win32 mutex enter wrapper: EnterCriticalSection |
| 528710 | `sqlite3_mutex_leave_win` | high | Win32 mutex leave wrapper: LeaveCriticalSection |
| 5290e0 | `sqlite3AllSpaces` | high | Collation helper: return true if the trailing param_2 bytes of the string are all ASCII spaces |
| 529cf0 | `sqlite3DecodeIntArray` | high | analyze.c decodeIntArray: parse sqlite_stat integer list into arrays, detect trailing 'unordered' keyword flag |
| 52df70 | `sqlite3RtrimBinCollCompare` | high | Binary/RTRIM collation compare: word-wise then byte-wise memcmp of two strings, treating trailing spaces as equal |
| 52e130 | `sqlite3BlobReadWrite` | high | sqlite3_blob_read/write core: range-checks offset/size under mutex and calls read or write xfer callback |
| 532d10 | `sqlite3_computeYMD` | high | Converts stored Julian-day date to year/month/day fields (iDate/calendar math via __alldiv) |
| 532e80 | `sqlite3_constructAutomaticIndex` | high | Builds an auto-index (Index struct) from equality WHERE terms for a table scan |
| 534710 | `sqlite3_doubleToInt64` | high | Clamps a double to int64 range, else returns INT64_MIN sentinel |
| 536250 | `sqlite3_exprDup` | high | Deep-duplicates an Expr node/tree (sqlite3ExprDup core), copying token and children |
| 53a6a0 | `sqlite3_btree_get_and_init_page` | high | Fetches a btree page and initializes its MemPage; releases on init failure; 'database corruption' |
| 53b110 | `sqlite3_get_boolean` | high | Parses a boolean text token ('on/off/false/yes/true/no/full') returning 0/1 or default |
| 53b1b0 | `getTempname` | high | SQLite 3.7.15.2 getTempname: identified by compiler-independent string-anchor match (2 unique-owner string anchors, score 10.0). Anchors: %s\etilqs_\|abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 |
| 53b4b0 | `sqlite3_vdbe_grow_op_array` | high | Doubles/reallocs the Vdbe opcode array (nOpAlloc), returns SQLITE_NOMEM(7) on failure |
| 53ce20 | `localtimeOffset` | high | date.c: compute local timezone offset (emits 'local time unavailable') |
| 53dde0 | `winMbcsToUnicode` | high | os_win.c: convert MBCS filename to UTF-16 (AreFileApisANSI/MultiByteToWideChar) |
| 53ec80 | `multiSelectCollSeq` | high | select.c: recurse compound select to find collating seq for a column |
| 543120 | `isDate` | high | SQLite 3.7.15.2 isDate: identified by compiler-independent string-anchor match (3 unique-owner string anchors, score 15.0). Anchors: minute\|month\|second |
| 546ad0 | `resolveSelectStep` | high | SQLite 3.7.15.2 resolveSelectStep: identified by compiler-independent string-anchor match (3 unique-owner string anchors, score 17.0). Anchors: GROUP\|ORDER\|a GROUP BY clause is required before HAVING\|aggregate functions are not allowed in the GROUP BY clause |
| 5476b0 | `seekWinFile` | high | os_win.c: SetFilePointer to seek a Windows file handle |
| 54a9a0 | `sqlite3Atoi64` | high | util.c: string to 64-bit int with overflow check (LARGEST_INT64) |
| 54c100 | `bitvec::set` | high | Sets a bit (page number) in a Bitvec, descending sub-bitmaps and rehashing on overflow |
| 54c2e0 | `bitvec::test` | high | Tests whether a bit (page number) is set in a Bitvec, descending sub-bitmaps/hash |
| 5505a0 | `sqlite3CodeSubselect` | high | SQLite 3.7.15.2 sqlite3CodeSubselect: identified by compiler-independent string-anchor match (2 unique-owner string anchors, score 10.0). Anchors: EXECUTE %s%s SUBQUERY %d\|SCALAR |
| 558890 | `sqlite3GenerateConstraintChecks` | high | SQLite 3.7.15.2 sqlite3GenerateConstraintChecks: identified by compiler-independent string-anchor match (2 unique-owner string anchors, score 12.0). Anchors: %s.%s may not be NULL\|PRIMARY KEY must be unique\|constraint %s failed |
| 55bc20 | `sqlite3Insert` | high | SQLite 3.7.15.2 sqlite3Insert: identified by compiler-independent string-anchor match (4 unique-owner string anchors, score 20.0). Anchors: %d values for %d columns\|rows inserted\|table %S has %d columns but %d values were supplied\|table %S has no column named %s |
| 55cf00 | `sqlite3IsReadOnly` | high | SQLite 3.7.15.2 sqlite3IsReadOnly: identified by compiler-independent string-anchor match (2 unique-owner string anchors, score 10.0). Anchors: cannot modify %s because it is a view\|table %s may not be modified |
| 55d490 | `sqlite3LoadExtension` | high | SQLite 3.7.15.2 sqlite3LoadExtension: identified by compiler-independent string-anchor match (4 unique-owner string anchors, score 22.0). Anchors: error during initialization: %s\|no entry point [%s] in shared library [%s]\|not authorized\|sqlite3_extension_init |
| 5788a0 | `sqlite3WhereBegin` | high | SQLite 3.7.15.2 sqlite3WhereBegin: identified by compiler-independent string-anchor match (2 unique-owner string anchors, score 10.0). Anchors: at most %d tables in a join\|cannot use index: %s |
| 57d530 | `vtabCallConstructor` | high | SQLite 3.7.15.2 vtabCallConstructor: identified by compiler-independent string-anchor match (3 unique-owner string anchors, score 15.0). Anchors: hidden\|vtable constructor did not declare schema: %s\|vtable constructor failed: %s |
| 5c0210 | `heap_sift_down_int` | high | Sift-down for a binary heap of 12-byte int-keyed elements, then push via FUN_005c20f0 (std sort_heap helper) |
| 5c0350 | `heap_sift_down_float` | high | Sift-down for binary heap of 12-byte float-keyed elements, then FUN_005c21f0 push (std heap helper) |
| 5c0ef0 | `insertion_sort_int` | high | Insertion sort over 12-byte elements keyed by int at offset+8 (std _Insertion_sort) |
| 5c1060 | `insertion_sort_float` | high | Insertion sort over 12-byte elements keyed by float at offset+8 |
| 5c1600 | `median_of_3_int` | high | Orders three 12-byte int-keyed elements (median-of-3 pivot selection for sort) |
| 5c1690 | `median_of_3_float` | high | Orders three 12-byte float-keyed elements (median-of-3 pivot) |
| 5c1ab0 | `guess_median_int` | high | Median/ninther pivot selection: for ranges >0x28 does median-of-medians via FUN_005c1600, else med3 |
| 5c1ef0 | `guess_median_float` | high | Median/ninther pivot selection (float) via FUN_005c1690 |
| 5c3f30 | `vec3i_greater_pred` | high | Lexicographic compare of two vec3i: returns 0 if param_1>=param_2 else 1 (strict-weak-order predicate) |
| 609210 | `buffer_allocate` | high | Allocates a buffer (operator_new + external:90), returns pointer/size |
| 63d7c0 | `Vector2u::greater_comparator` | high | Return 1 if param_1 (u,v) greater-than param_2 lexicographically else 0 |
| 64d770 | `WorldInfo::copy_record` | high | Copy WorldInfo record: two std::strings (FUN_0040c0a0) plus three ints (+0x30/34/38) |
| 65ad80 | `TupleKey::less` | high | 3-field comparator: returns 1 if (a<b) lexicographically over int,int,then FUN_005a78a0 tail compare. |
| 67fdb0 | `uninitializedCopy_8byte` | high | Uninitialized-copies a range of 8-byte pair elements from [param_1,param_2) into param_3 |
| 68d593 | `_Fac_tidy_reg_t_dtor` | high | Statically-linked MSVC CRT/STL function identified by signature match (flirt-crc, crc:swap~;len=0x24). Mangled: ??1_Fac_tidy_reg_t@std@@QAE@XZ. public: __thiscall std::_Fac_tidy_reg_t::~_Fac_tidy_reg_t(void) |
| 68e489 | `__except_handler4` | high | Statically-linked MSVC CRT/STL function identified by signature match (flirt-crc, crc:swap~;len=0x23). Mangled: __except_handler4. |
| 68e604 | `__CxxUnhandledExceptionFilter` | high | Statically-linked MSVC CRT/STL function identified by signature match (flirt-crc, crc:swap~;len=0x41). Mangled: ?__CxxUnhandledExceptionFilter@@YGJPAU_EXCEPTION_POINTERS@@@Z. long __stdcall __CxxUnhandledExceptionFilter(struct _EXCEPTION_POINTERS *) |
| 68e87e | `__setdefaultprecision` | high | Statically-linked MSVC CRT/STL function identified by signature match (flirt-crc, crc:swap~;len=0x27). Mangled: __setdefaultprecision. |
| 68e9a0 | `umul32to64` | high | Computes full 64-bit product of two 32-bit uints, stores lo/hi into param_1[0/1] |
| 68ea00 | `udiv64by32_bitwise` | high | Bit-by-bit 64-bit-by-32-bit unsigned division (32 iterations), returns quotient or 0x7fffffff on overflow |
| 68ea40 | `uadd64` | high | Adds two 64-bit values (from EDI/ESI) with carry, stores result to EDX ptr |
| 68ea60 | `fixedMulDiv` | high | Signed fixed-point MulDiv: (a*b+c/2)/c with 64-bit path for large operands, sign-corrected |
| 68ebc0 | `fixedMul_16_16` | high | Signed 16.16 fixed-point multiply with rounding (0x8000), fast path for small operands |
| 68ec40 | `fixedDiv_16_16` | high | Signed 16.16 fixed-point divide (a<<16)/b with rounding, 64-bit path for large numerator |
| 693060 | `sfnt_Open_TrueType_CFF` | high | FreeType: detect and open TrueType/CFF via OTTO magic (0x4f54544f -> 'cff', else 'truetype') |
| 695630 | `gray_conic_is_flat` | high | FreeType(smooth): test if a conic arc is flat enough (dx/dy within 1), else compute split angle |
| 695710 | `gray_split_cubic` | high | FreeType(smooth): de Casteljau subdivide a cubic bezier arc in place into two halves |
| 6957c0 | `gray_cubic_is_flat` | high | FreeType(smooth): test cubic bezier flatness on both control legs, compute split points |
| 69ad50 | `gray_split_conic` | high | FreeType(smooth): de Casteljau subdivide a conic bezier arc in place |
| 6ceb90 | `inflate` | high | zlib 1.2.3 inflate: identified by compiler-independent string-anchor match (4 unique-owner anchors: incorrect data check, incorrect header check, invalid window size, unknown compression method) |
| 401d70 | `oggpack_look` | med | libogg bitwise: look at in_EDX bits without advancing cursor |
| 401e30 | `oggpack_adv` | med | libogg bitwise: advance bit cursor by in_EDX bits |
| 401e80 | `BitReader_getBits` | med | Reads up to 32 bits from a little-endian bitstream using mask table DAT_00745d00; sets error on overrun |
| 402210 | `std_vector_char_insert_wrap` | med | MSVC STL: SEH wrapper for vector<char> range insert |
| 402280 | `std_vector_int_insert_wrap` | med | MSVC STL: SEH wrapper for vector<int> range insert |
| 4022f0 | `std_destroy_ptr_range` | med | MSVC STL: destroy+operator_delete each element in [param_1,param_2) |
| 402370 | `std_vector_char_insert` | med | MSVC STL: vector<char>::insert with realloc/grow ('vector<T> too long') |
| 402500 | `std_vector_int_insert` | med | MSVC STL: vector<int>::insert with realloc/grow (4-byte elements) |
| 402d50 | `std_rotate` | med | MSVC STL: std::rotate via gcd block-swap |
| 402f80 | `uivm_pop_int` | med | UI expr VM: pop top operand, return its int value |
| 402fd0 | `uivm_pop_float` | med | UI expr VM: pop top operand, return its float value |
| 403030 | `uivm_push_int` | med | UI expr VM: allocate 12-byte operand entry and push int result |
| 405470 | `std_fill_n_bytes` | med | __thiscall: reserve n via FUN_0064e310 then memset buffer with byte *param_2 (vector<char>/string fill assign) |
| 40b730 | `uivm_op_named_push` | med | Builds temp std::string, calls FUN_0040c280/FUN_0040bff0, pushes param_2; stack cookie |
| 40bac0 | `std_list_push_back` | med | std::list push_back: allocates node via FUN_00583cb0, checks 'list<T> too long' length guard, links tail |
| 40bef0 | `uivm_sum_scaled` | med | Sums global int array of length DAT_00765008 (unrolled) and returns global_scale * sum |
| 412810 | `math::vec4_scale` | med | scale 4-float vector by scalar in place (game math) |
| 42c680 | `mem_equal_24` | med | compare 3 consecutive 8-byte pairs for equality (game) |
| 43e630 | `container_clear` | med | clear container by destroying range then reset (game/std) |
| 4490f0 | `math::mat4_copy_transpose` | med | copy 16-float matrix and reorder to columns (game math) |
| 4555c0 | `std::_Uninitialized_move<0x78>` | med | Move/copy-construct range of 0x78-byte elements (0x1e dwords each) to raw storage |
| 457ae0 | `std::list<T>::insert(pos,first,last)` | med | list insert-range wrapper (helper FUN_00453ff0) |
| 457b80 | `std::list<T>::insert(pos,first,last)` | med | list insert-range wrapper (helper FUN_004540c0) |
| 457f70 | `std::list<T>::_Deserialize<0x18>` | med | Read count then 0x18-byte records from a byte-stream reader and push_back into list |
| 458030 | `std::list<T>::_Deserialize<0x28>` | med | Read count+0x28-byte records from stream reader into list |
| 458100 | `std::list<T>::_Deserialize<0x10>` | med | Read count+16-byte records from stream reader into list |
| 4581d0 | `std::list<T>::_Deserialize<0x70>` | med | Read count+0x70-byte records from stream reader into list (memcpy chunk) |
| 458310 | `std::list<T>::_Deserialize<0x14>` | med | Read count+0x14-byte records from stream reader into list |
| 4583f0 | `std::list<T>::_Deserialize<0x48>` | med | Read count+0x48-byte records from stream reader into list |
| 458500 | `std::list<T>::_Deserialize<0x120>` | med | Read count+0x120-byte records (memset+memcpy) from stream reader into list |
| 458650 | `std::list<T>::_Deserialize<0x38>` | med | Read count+0x38-byte records from stream reader into list |
| 458780 | `std::list<T>::_Deserialize<0x58>` | med | Read count+0x58-byte records from stream reader into list |
| 458860 | `std::list<T>::_Deserialize<0x48>` | med | Read count+0x48-byte records from stream reader into list (float defaults) |
| 458940 | `std::list<T>::_Deserialize<0x18>` | med | Read count+0x18-byte records (float default) from stream reader into list |
| 458a20 | `std::list<T>::_Deserialize<0x148>` | med | Read count+0x148-byte records (memset+memcpy) from stream reader into list |
| 4593b0 | `std::_Tree<>::_Tree()` | med | map/set default-ctor: zero members, allocate head sentinel node (FUN_00487250) |
| 465b30 | `std::vector/_Tree alloc` | med | Zero members then allocate storage node (FUN_0046d8d0, 0x150 bytes) |
| 466ab0 | `dtor_free@unwind` | med | SEH unwind funclet: member dtor FUN_0046f8b0 then operator delete |
| 466ad0 | `dtor_free@unwind` | med | SEH unwind funclet: member dtor FUN_0046f910 then operator delete |
| 466af0 | `dtor_free@unwind` | med | SEH unwind funclet: member dtor FUN_0046f9f0 then operator delete |
| 466b10 | `tree_dtor_free@unwind` | med | SEH unwind funclet: destroy tree/list (FUN_004777f0) then operator delete |
| 466b40 | `string_tidy@unwind` | med | SEH unwind funclet: _Tidy two std::string members (reset SSO, free buffers) |
| 466b90 | `vector_dtor_free@unwind` | med | SEH unwind funclet: destroy vector elements (FUN_00452600) then operator delete |
| 467ab0 | `dtor_free@unwind` | med | SEH unwind funclet: dtor FUN_0046f990 then delete member at +8 |
| 467b40 | `dtor_free@unwind` | med | SEH unwind funclet: dtor FUN_0046f990 then operator delete(*this) |
| 46e430 | `std::vector<T120>::_Reallocate` | med | Reallocate 120-byte-element vector, move+free |
| 46e610 | `std::vector<T24>::_Reallocate` | med | Reallocate 24-byte-element vector, move+destroy old |
| 46e880 | `std::vector<T120>::_Reserve_grow` | med | Ensure capacity for +n 120-byte elems, return element ptr |
| 46f8b0 | `std::list<std::string>::clear` | med | Clear list freeing embedded string in each node |
| 46f9f0 | `std::list<std::string>::clear` | med | Clear list, free embedded string at node+0x40 |
| 486950 | `std::vector<T24>::insert` | med | Insert 24-byte element at position, grow+construct |
| 486b60 | `net::send_all` | med | Loop ws2_32 send() until whole buffer transmitted (winsock) |
| 4870c0 | `std::wstring::resize_shrink` | med | Truncate wstring to length, null-terminate (or grow-fill) |
| 487250 | `std::vector<T120>::resize` | med | Resize 120-byte-element vector, return end pointer |
| 4874a0 | `math::round_to_hundredths` | med | Round float to 2 decimals, recursing on negatives (game math) |
| 4aa0d0 | `move_backward_48` | med | Backward block-move of 48-byte elements (partition rotate helper for FUN_004a9520) |
| 4c83f0 | `CubeWndProc` | med | Win32 window procedure: routes input/quit/close messages |
| 4cb290 | `std::basic_filebuf<char>::~basic_filebuf` | med | Destroy filebuf: base dtor, set vtable, ios_base dtor |
| 4cbde0 | `net::Connection::read_delta_i8` | med | If dirty bit set, read byte field from received buffer (game net) |
| 4cbe50 | `net::Connection::recv_delta_i8` | med | If dirty bit set, recv 1 byte via ws2_32 recv (game net) |
| 4cbed0 | `net::Connection::read_delta_i16` | med | If dirty bit set, read short field from buffer (game net) |
| 4cbf40 | `net::Connection::recv_delta_i16` | med | If dirty bit set, recv 2 bytes via recv (game net) |
| 4cbfc0 | `net::Connection::read_delta_i32` | med | If dirty bit set, read int field from buffer (game net) |
| 4cc030 | `net::Connection::recv_delta_i32` | med | If dirty bit set, recv 4 bytes via recv (game net) |
| 4cc0b0 | `net::Connection::read_delta_struct20` | med | If dirty bit set, read 0x14 struct from buffer (game net) |
| 4cc140 | `net::Connection::recv_delta_struct20` | med | If dirty bit set, recv 0x14 bytes via recv (game net) |
| 4cc1c0 | `EntityState_deserializeField_size0xAC` | med | Copy 0xAC-byte field from packet buffer into entity struct if dirty-bit set; advances bit index |
| 4cc240 | `EntityState_recvField_size0xAC` | med | recv() 0xAC-byte entity field from socket if dirty-bit set (Ordinal_16=ws2_32 recv) |
| 4cc2c0 | `EntityState_deserializeField_size0xE38` | med | Copy 0xE38-byte field from packet buffer into entity struct if dirty-bit set |
| 4cc340 | `EntityState_recvField_size0xE38` | med | recv() 0xE38-byte entity field from socket if dirty-bit set |
| 4cc3c0 | `EntityState_deserializeField_size0x118` | med | Copy 0x118-byte field from packet buffer into entity struct if dirty-bit set |
| 4cc440 | `EntityState_recvField_size0x118` | med | recv() 0x118-byte entity field from socket if dirty-bit set |
| 4cc4c0 | `EntityState_recvField_size0x0C` | med | recv() 0x0C-byte entity field from socket if dirty-bit set |
| 4cc540 | `EntityState_deserializeField_size0x0C` | med | Copy 12-byte field (vec3) from packet buffer into entity struct if dirty-bit set |
| 4cc5c0 | `EntityState_deserializeField_size0x18` | med | Copy 0x18-byte field from packet buffer into entity struct if dirty-bit set |
| 4cc650 | `EntityState_recvField_size0x18` | med | recv() 0x18-byte entity field from socket if dirty-bit set |
| 4cc6d0 | `EntityState_deserializeField_size0x08` | med | Copy 8-byte field from packet buffer into entity struct if dirty-bit set |
| 4cc750 | `EntityState_recvField_size0x08` | med | recv() 8-byte entity field from socket if dirty-bit set |
| 4ccda0 | `EntityState_deserializeField_size0x10` | med | Copy 0x10-byte field from packet buffer into entity struct if dirty-bit set |
| 4cce20 | `EntityState_recvField_size0x10` | med | recv() 0x10-byte entity field from socket if dirty-bit set |
| 4ccea0 | `EntityState_deserializeField_size0x2C` | med | Copy 0x2C-byte field from packet buffer into entity struct if dirty-bit set |
| 4ccf20 | `EntityState_recvField_size0x2C` | med | recv() 0x2C-byte entity field from socket if dirty-bit set |
| 4ccfa0 | `EntityState_deserializeFromBuffer` | med | Master: deserialize full entity/creature state from packet buffer, walking all fields by offset |
| 4cd3e0 | `EntityState_recvFromSocket` | med | Master: receive full entity/creature state field-by-field from socket |
| 4d7be0 | `xml_skipToTag_plain` | med | Advance wide cursor over whitespace to next '<' or NUL, terminate token |
| 4d7c30 | `xml_parseText_entityDecode` | med | Scan text run to '<', decoding '&' entity refs (FUN_004d96f0), compact result |
| 4d7dc0 | `xml_parseText_newlineNorm` | med | Scan text run to '<' normalizing CRLF/CR to LF (no entity decode) |
| 4d8750 | `xml_parseAttrValue_plain` | med | Scan attribute value up to closing quote, CRLF-normalized, no entity decode |
| 4d8810 | `xml_parseAttrValue_entityDecode` | med | Scan attribute value to closing quote, decoding '&' entities |
| 4e3c70 | `std_Tree_erase` | med | std::map/set erase node with red-black rebalance; 'invalid map/set<T> iterator' check |
| 4ec0d0 | `std_list_clear_free` | med | Clear list: reset sentinel links and operator delete nodes |
| 51c760 | `sqlite3_value_bytes` | med | sqlite3 value byte length: coerce Mem to text (FUN_0056bce0) then return length (n or n+u) |
| 51c7a0 | `sqlite3VdbeRealValue` | med | Return double value of a sqlite3 Mem (real/int/text-to-real via FUN_0054a330) |
| 51c810 | `sqlite3VdbeIntValue` | med | Return 32-bit int value of a sqlite3 Mem (int/real/text-to-int) |
| 51c890 | `sqlite3VdbeIntValue64` | med | Return 64-bit int value of a sqlite3 Mem (int/real/text conversion) |
| 51c950 | `sqlite3_value_text` | med | sqlite3ValueText(pVal, SQLITE_UTF8=1): return UTF-8 text of value |
| 51c970 | `sqlite3_value_text16` | med | sqlite3ValueText(pVal, enc=2): return native UTF-16 text of value |
| 51c990 | `sqlite3_value_text16_v3` | med | sqlite3ValueText(pVal, enc=3): return UTF-16 (opposite endian) text of value |
| 51c9b0 | `sqlite3_value_type` | med | Return sqlite3 value type byte (SQLITE_INTEGER/FLOAT/TEXT/BLOB/NULL) at Mem+0x1e |
| 51c9c0 | `sqlite3_value_numeric_type` | med | Apply numeric affinity (FUN_0052b630) then return resolved value type |
| 51ceb0 | `sqlite3_get_auxdata` | med | Return cached auxiliary data for the Nth function argument, or NULL |
| 51cee0 | `sqlite3_set_auxdata` | med | Store auxiliary data + destructor for the Nth function argument (grows aux array) |
| 51cf90 | `sqlite3_result_value` | med | Set function result by copying/dup another Mem value into the result Mem |
| 51cfd0 | `sqlite3_result_blob` | med | Set function result to a BLOB (enc 0); TOOBIG error if length exceeds limit |
| 51d010 | `sqlite3_result_double` | med | Set function result to a double (sqlite3VdbeMemSetDouble) |
| 51d040 | `sqlite3_result_text` | med | Set function result to UTF-8 text (enc 1) with destructor |
| 51d0b0 | `sqlite3_result_text16le` | med | Set function result to UTF-16LE text (enc 2) |
| 51d110 | `sqlite3_result_null` | med | Set function result to NULL (sqlite3VdbeMemSetNull, release owned mem) |
| 51d1d0 | `sqlite3_result_text_const` | med | Set function result to an internal constant text string |
| 51d210 | `sqlite3VdbeMemSetInt` | med | sqlite3_result_int: set Mem to 32-bit signed integer, release old contents |
| 51d270 | `sqlite3VdbeMemSetInt64` | med | sqlite3_result_int64: set Mem to 64-bit integer |
| 51d2d0 | `sqlite3VdbeMemSetNull` | med | Release Mem contents and set NULL type (no error flags) |
| 51d350 | `sqlite3_result_text_dtor` | med | Set function result to UTF-8 text (enc 1) with caller destructor; TOOBIG guard |
| 51d390 | `sqlite3_result_text16le_dtor` | med | Set function result to UTF-16LE text (enc 2) with caller destructor |
| 51d4d0 | `sqlite3_result_text16be_dtor` | med | Set function result to UTF-16BE text (enc 3) with caller destructor |
| 51d580 | `sqlite3_result_zeroblob` | med | Set function result to a zero-filled blob of N bytes (MEM_Blob\|MEM_Zero flags) |
| 51d9c0 | `sqlite3LockAndPrepare` | med | Prepare statement under db mutex (FUN_00533960); map OOM(0xC0A) to SQLITE_NOMEM, return rc |
| 51dac0 | `sqlite3_prepare_v2` | med | Prepare statement (v2, 6 args) under db mutex; OOM mapping and rc masking |
| 51db30 | `sqlite3_prepare16` | med | Prepare UTF-16 SQL: transcode to UTF-8 (FUN_0056a850) then prepare under mutex |
| 51dbd0 | `sqlite3_progress_handler` | med | Install progress callback+interval on db under mutex (db+0xC8/0xD0/0xCC) |
| 51dc20 | `sqlite3_set_hook` | med | Install a db callback hook under mutex (db+0xCC/0xD0/0xC8), return previous arg |
| 51dde0 | `sqlite3_busy_timeout` | med | Set busy timeout: convert ms via VFS xSleep (vtbl+0x3c), scale by 1000 |
| 51de50 | `sqlite3_result_length_check` | med | Compute value byte-length, enforce SQLITE_LIMIT_LENGTH, set int result |
| 51df10 | `sqlite3_context_db_handle` | med | Mutex-guarded return of db handle from context/vm |
| 51df50 | `sqlite3_commit_hook` | med | Mutex-guarded install commit hook cb/arg at db+0xa8, return old |
| 51dfa0 | `sqlite3_rollback_hook` | med | Mutex-guarded install rollback hook cb/arg at db+0xb0, return old |
| 51dff0 | `replaceFunc` | med | SQL replace(str,pat,rep): scan+substitute all occurrences, size-checked |
| 51e270 | `memjrnlRead` | med | Read from in-memory journal 0x3fc-byte chunk linked list |
| 51e340 | `sqlite3_update_hook` | med | Mutex-guarded install update hook cb/arg at db+0xb8, return old |
| 51e960 | `sqlite3_soft_heap_limit64` | med | Mutex-guarded get/set of soft heap limit, trigger release |
| 51ea40 | `sqlite3_soft_heap_limit` | med | 32-bit wrapper clamping negative then calling soft_heap_limit64 |
| 51ea60 | `memjrnlWrite` | med | Append to in-memory journal, alloc 0x400 chunks as needed |
| 51eb70 | `juliandayFunc` | med | SQL julianday(): compute JD ms then divide by 86400000 to days |
| 51ec50 | `trimFunc` | med | SQL trim/ltrim/rtrim: strip UTF-8 charset chars from ends |
| 51f6b0 | `memjrnlTruncate` | med | Free MemJournal chunk list, reset vtable to DAT_00712500 |
| 51f890 | `pcache1SetCachesize` | med | Adjust pcache size: nMax=param, nMin=param*9/10 |
| 51f900 | `memjrnlClose` | med | Close in-memory journal (truncate to 0) |
| 51ff80 | `pcache1Fetch` | med | pcache1 page fetch/allocate with hash lookup and LRU |
| 520640 | `sumStep` | med | Aggregate sum/total step: accumulate int64/real into acc |
| 520c70 | `pcache1PinUnpin` | med | Pin/unpin pcache page, move between LRU and hash |
| 520d30 | `sumFinalize` | med | Aggregate sum finalize: set int/real result or overflow err |
| 520e20 | `avgFinalize` | med | Aggregate avg finalize: sum/count as double result |
| 5211a0 | `timeFunc_noarg` | med | 0-arg trampoline pushing 0,0 then calling timeFunc |
| 5211c0 | `totalFinalize` | med | Aggregate total() finalize: result double of sum |
| 521220 | `pcache1Rekey` | med | Rehash pcache entry from old key to new key param_4 |
| 5212a0 | `dateFunc_noarg` | med | 0-arg trampoline pushing 0,0 then calling dateFunc |
| 5212c0 | `countStep` | med | Aggregate count() step: increment 64-bit counter |
| 521320 | `datetimeFunc_noarg` | med | 0-arg trampoline pushing 0,0 then calling datetimeFunc |
| 521340 | `pcache1Truncate` | med | Truncate pcache: drop pages with key >= param_2 |
| 521440 | `sqlite3_create_function` | med | create_function trampoline calling 00533b00(...,0) |
| 521460 | `pcache1Destroy` | med | Destroy pcache group: truncate, adjust status, free |
| 5214d0 | `minmaxStep` | med | Aggregate min()/max() step via comparator |
| 5215b0 | `sqlite3_create_function16` | med | create_function16 trampoline to 00533b00 |
| 5215c0 | `sqlite3Reprepare` | med | Re-run/reprepare cached statement, swap Vdbe on success |
| 521950 | `sqlite3ValueText16` | med | Produce UTF-16 text from value, growing Mem buffer |
| 522240 | `sqlite3_clear_bindings` | med | Clear all bindings of prepared stmt (misuse-guarded) |
| 522720 | `winSectorSize_stub` | med | os_win.c winSectorSize stub (const return) |
| 523720 | `sqlite3_complete16` | med | UTF-16 wrapper of sqlite3_complete |
| 523900 | `renameQuoteFunc_a` | med | Build quoted identifier via '%.*s"%w"%s' (ALTER rename) |
| 523c30 | `sqlite3_free_table` | med | Free result array from sqlite3_get_table |
| 5241a0 | `renameQuoteFunc_b` | med | Build quoted identifier via '%s%.*s"%w"' (ALTER rename) |
| 524910 | `renameTriggerFunc` | med | Build quoted identifier via '%.*s"%w"%s' (rename trigger) |
| 525800 | `winLock` | med | os_win.c winLock: acquire file lock with retry |
| 525aa0 | `sqlite3_bind_text_helper` | med | Bind text/blob to stmt param (value convert + 00528890) |
| 525d20 | `sqlite3_extended_errcode` | med | sqlite3_extended_errcode: return extended code |
| 525d90 | `sqlite3_db_filename` | med | Return filename for named db ('unknown database: %s') |
| 525f10 | `sqlite3_errmsg16` | med | sqlite3_errmsg16: return UTF-16 error message |
| 526030 | `sqlite3_extended_result_codes` | med | Toggle extended result codes flag (misuse-guarded) |
| 5260e0 | `sqlite3_bind_blob` | med | Bind blob to param with length check |
| 526410 | `winGetReadLock` | med | os_win.c read-lock acquire helper |
| 5264a0 | `sqlite3_prepare` | med | sqlite3_prepare wrapper over 0055d830 |
| 5267c0 | `mallocWithAlarm` | med | Core malloc with alarm ('failed to allocate %u bytes') |
| 526940 | `sqlite3_bind_double` | med | Bind real value to statement parameter |
| 526b80 | `sqlite3MemRealloc` | med | Core realloc ('failed memory resize %u to %u bytes') |
| 526e40 | `sqlite3_bind_null` | med | Bind NULL / zeroblob to parameter (005758f0) |
| 526fb0 | `sqlite3_result_text_sized` | med | Set text/blob result with 'string or blob too big' check |
| 5270f0 | `sqlite3_value_bytes` | med | Return value byte length |
| 527160 | `sqlite3_result_blob_sized` | med | Set blob result with size check |
| 527220 | `sqlite3_value_text` | med | Return value UTF-8 text pointer |
| 527b00 | `sqlite3_column_bytes` | med | sqlite3_column_bytes: byte length of column |
| 527d50 | `sqlite3_column_int64` | med | sqlite3_column_int64: 64-bit int of column |
| 527dd0 | `sqlite3_column_int` | med | sqlite3_column_int: 32-bit int of column |
| 527e00 | `sqlite3_column_text16` | med | sqlite3_column_text16: UTF-16 text with size check |
| 527ea0 | `sqlite3_column_double` | med | sqlite3_column_double: real value of column |
| 527f90 | `sqlite3_column_type` | med | sqlite3_column_type: datatype code of column |
| 528270 | `sqlite3VdbeMemReleaseSetInt` | med | Release external Mem memory (if MEM_Dyn/Agg/RowSet/Frame set) then store an int and set flags=MEM_Int |
| 528320 | `sqlite3_create_function` | med | Public API wrapper: register a scalar/agg SQL function, forwarding to create_function_v2 with null xDestroy |
| 5283b0 | `sqlite3BtreeClose_sharedUnlink` | med | Unlink a Btree from the shared-cache list under mutex, free it, decrement pBt refcount and free shared BtShared on zero |
| 528490 | `sqlite3_create_function16` | med | UTF16 create_function API: convert name to UTF8, call sqlite3CreateFunc under db mutex, apiExit on nomem |
| 528550 | `sqlite3_win_lock_region` | med | Acquire/release byte-range locks on a file, scanning lock list for conflicts, updating shared/excl lock masks |
| 528720 | `sqlite3CreateFunc_v2` | med | Core create_function_v2: alloc FuncDestructor holding xDestroy+pArg, register function, cleanup+apiExit |
| 528890 | `sqlite3BtreeFetchPayload` | med | Fetch/load a b-tree cursor cell payload, moving cursor to a valid cell, updating cursor state flags |
| 5288e0 | `sqlite3BtreeCellSize` | med | Ensure cursor cell info parsed, return key/data size (adds local payload for index cursors) |
| 529de0 | `sqlite3AnalyzeAggregate` | med | analyzeAggregate: walk Expr (TK_COLUMN/AGG_FUNCTION/AGG_COLUMN) adding columns/functions to AggInfo tables |
| 52b5d0 | `sqlite3VdbeMemFinalizeType` | med | Finalize a Mem value by mode char 'a'/'b'/other: release cache, clear cache flags, expand or nul-terminate blob |
| 52b630 | `sqlite3VdbeMemExpandBlob` | med | expandBlob: if Mem holds a zero-padded/deferred blob, materialize it into real memory and set MEM flags |
| 52b750 | `sqlite3ParseRegisterCache` | med | Look up or create a cached register mapping for (param_3 object) in a Parse-owned list, allocating 16-byte node, return reg |
| 52cf10 | `sqlite3WhereEstimateFullScanCost` | med | Estimate and possibly select full-table-scan WHERE cost using log row estimate, updating best-cost plan fields |
| 52d020 | `sqlite3WhereBestBtreeIndex` | med | bestBtreeIndex: score candidate b-tree indexes/terms for a WHERE loop, computing cost/rows and flags |
| 52d990 | `sqlite3WhereOrTermCost` | med | Recursive OR-clause cost helper: dispatch to virtual best-index or btree best-index per subterm, accumulate cost |
| 52d9f0 | `sqlite3WhereBestOrIndex` | med | bestOrClauseIndex: estimate cost of an OR-of-ANDs WHERE optimization over cursor terms, update best plan, stack cookie |
| 52dd50 | `sqlite3WhereBestVirtualIndex` | med | bestVirtualIndex: build sqlite3_index_info, invoke vtab xBestIndex, evaluate returned cost/usage, set best plan |
| 52ebe0 | `sqlite3ProgressCheck` | med | invokeProgressHandler: calls the registered xProgress callback every N vdbe ops, resets/increments counter |
| 52ec30 | `sqlite3BtreeMovetoUnpacked` | med | btreeMoveto: builds an UnpackedRecord (stack or heap) from a key blob and seeks the cursor to it |
| 52ed40 | `sqlite3_btree_page_from_dbpage` | med | Wraps a pager page (via PagerGet) into an initialized MemPage for the given page number |
| 52ef30 | `sqlite3_pager_has_content_check` | med | getPageNormal/hasContent: lazily allocates a 512-byte bitmap and tests whether a page already has content |
| 52f320 | `sqlite3_column_lists_overlap` | med | Case-insensitively checks whether any name in one column list also occurs in another (returns 1 if overlap) |
| 530010 | `sqlite3BtreeClearCell` | med | clearCell: frees the overflow-page chain of a btree cell, with corruption checks |
| 530200 | `sqlite3ClearDatabasePage` | med | clearDatabasePage: recursively frees all pages of a btree table, optionally counting rows in param_4 |
| 5303a0 | `expr::delete_recursive` | med | Recursively frees an Expr/list tree node and its sub-nodes/token strings |
| 530a70 | `sqlite3_code_compare` | med | codeCompare: emits a comparison VDBE op between two operands, computing collation and comparison affinity |
| 530f60 | `sqlite3WhereCodeOneLoopStart` | med | codeOneLoopStart: generates the VDBE loop body for one WhereLevel (index scan / seek / constraints) |
| 532390 | `sqlite3_code_trigger_program` | med | codeTriggerProgram: generates VDBE code for a chain of trigger steps (insert 'i'/delete 'j'/update 'k'/select) |
| 5328e0 | `sqlite3_comparison_affinity` | med | comparisonAffinity: computes the comparison affinity of a binary Expr from its operand affinities |
| 532980 | `sqlite3_date_compute_hms` | med | computeHMS: derives hour/minute/second/fractional-second fields from a DateTime's millisecond value |
| 532a40 | `sqlite3_date_compute_jd` | med | setDateTimeToCurrent/computeJD: seeds a DateTime from the OS clock and applies local timezone offset |
| 5336b0 | `sqlite3_vdbeMemGrowCheck` | med | Enforces SQLITE_LIMIT_LENGTH then grows a Mem blob/string buffer; sets SQLITE_TOOBIG(0x12) |
| 533b00 | `sqlite3_createModule` | med | Registers a virtual-table module in db->aModule hash (sqlite3_create_module_v2 core) |
| 534860 | `sqlite3_dupedExprNodeSize` | med | Computes byte size needed to duplicate a single Expr node (token/list flags) |
| 5348d0 | `sqlite3_dupedExprSize` | med | Recursively sums duplicate size of an Expr subtree (left/right children) |
| 534970 | `sqlite3_evalConstExpr` | med | Rewrites a constant Expr into a cached OP_ target register (op set to TK_REGISTER 0x84) |
| 5353c0 | `sqlite3_btreeCursorIsEmpty` | med | Returns true if btree cursor's page holds zero cells (EOF/empty test) |
| 535400 | `sqlite3_exprAnalyze` | med | Analyzes one WHERE term: extracts operator, operands, affinity, prereq bitmasks |
| 535b00 | `sqlite3_exprAnalyzeOrTerm` | med | Analyzes an OR/AND WHERE term, building OR-optimization sub-WhereClauses |
| 5361d0 | `sqlite3_exprCommute` | med | Swaps left/right operands of a comparison Expr and inverts the operator |
| 536480 | `sqlite3_exprListTableUsage` | med | Returns cursor bitmask of tables referenced by an ExprList |
| 5365e0 | `sqlite3_exprSelectTableUsage` | med | Returns cursor bitmask of tables used across a Select's clauses/subqueries |
| 536750 | `sqlite3_exprSetHeightAndFlags` | med | Computes and stores an Expr node's height from its children/select subtree |
| 536850 | `sqlite3_exprTableUsage` | med | Recursively returns cursor bitmask of tables referenced by an Expr (sqlite3ExprUsage) |
| 537230 | `sqlite3_exprlist_find_index` | med | Searches an ExprList for a column expr matching table/column/collation; returns index or -1 |
| 5372f0 | `sqlite3_where_find_term` | med | Scans WhereClause term chain for a term matching cursor/column/operator mask and collation |
| 538660 | `sqlite3_fk_scan_children` | med | Builds WHERE Expr trees (TK_STRING/TK_REGISTER) to scan child rows for FK enforcement |
| 539460 | `sqlite3_btree_allocate_page` | med | Allocates a btree page from freelist or end-of-file, handling autovacuum pointer-map updates |
| 539a00 | `func::destroy_ref` | med | Decrements a function-def refcount and destroys it (calling its xDestroy) when it reaches zero |
| 53a850 | `sqlite3_date_get_digits` | med | Parses fixed-width numeric fields from a date/time string per a min/max/separator spec table |
| 53a8f0 | `sqlite3_win_get_last_error_msg` | med | Formats a Windows OS error code into a message via FormatMessageW/A; 'OsError 0x%x (%u)' |
| 53aab0 | `sqlite3_where_get_mask` | med | Returns a 64-bit Bitmask with the bit set at the index of a cursor in the WhereMaskSet array |
| 53ac70 | `sqlite3_pager_write_journal_nonce` | med | Fills journal header buffer with random bytes / nonce and writes it via the OS write callback |
| 53ad90 | `sqlite3_code_row_trigger` | med | Builds a sub-Parse (0x230) and codes a row trigger program; '-- TRIGGER %s' |
| 53b730 | `sqlite3_expr_list_height` | med | Scans an ExprList updating a running maximum of child expression heights |
| 53b770 | `sqlite3_expr_height` | med | Walks an Expr tree computing its maximum height across all sub-expressions and lists |
| 53c010 | `sqlite3_expr_is_constant` | med | Walks an Expr to determine if it is constant (rejecting column/agg/select TK node types) |
| 53c0e0 | `sqlite3_select_is_simple_count` | med | Tests whether a SELECT is a simple aggregate over one table (min/max/count fast-path eligibility) |
| 53c140 | `isDate` | med | date.c: parse function argument(s) into a DateTime struct (Julian day) |
| 53c6d0 | `winGetVersion` | med | os_win.c: query Windows version via GetVersionExA |
| 53d040 | `fkLocateIndex` | med | fkey.c: locate parent index for FK ('foreign key mismatch', BINARY coll) |
| 542f30 | `parseDateOrTime` | med | date.c: parse date/time string or numeric into DateTime |
| 542ff0 | `parseHhMmSs` | med | date.c: parse HH:MM:SS[.fff] time component |
| 543a20 | `parseYyyyMmDd` | med | date.c: parse YYYY-MM-DD date component |
| 543b00 | `parseDateOrTimeInner` | med | date.c: parse combined date+time string |
| 544050 | `sqlite3MallocZero` | med | malloc.c: allocate zeroed memory |
| 544c20 | `prng::rc4_next_byte` | med | Produces the next RC4 keystream byte, lazily seeding the PRNG state from the VFS randomness |
| 544e80 | `wal::read_frame_or_journal` | med | Reads a WAL/journal frame at a computed offset, validating the frame magic |
| 5452d0 | `hash::rehash` | med | Rebuilds a hash table's bucket array to a new size, re-linking all entries |
| 546890 | `resolveCompoundOrderBy` | med | resolve.c: resolve ORDER BY on compound select (term out of range) |
| 548b20 | `setDateTimeToCurrent` | med | date.c: fill DateTime from current time (no-arg case) |
| 549610 | `sqlite3AffinityType` | med | build.c: map declared type name to affinity char |
| 54a160 | `strAccum::append_spaces` | med | Appends param_2 space characters to a StrAccum, growing the buffer in 29-char runs |
| 54a2b0 | `sqlite3KeyInfoAlloc` | med | build.c/vdbe: allocate KeyInfo (alloc+memset) |
| 54a330 | `computeYMD` | med | date.c: convert Julian day to year/month/day (alldiv) |
| 54bf60 | `bitvec::clear` | med | Clears a bit (page number) in a Bitvec structure, rehashing hash chains as needed |
| 54c040 | `bitvec::destroy` | med | Recursively frees a Bitvec structure and its sub-bitmaps |
| 550b60 | `schema::compact_hash` | med | Removes empty entries from a schema hash array and reclaims small tables back to inline storage |
| 5ae900 | `initZero_T28` | med | Zero-initializes array of param_2 elements of 28 bytes (7-dword stride, 6 dwords cleared each) |
| 630850 | `tree_buildFromData` | med | Builds a tree/map from source data (FUN_0062f690/0062f8c0/0062fdc0), frees temp |
| 68e83e | `__RTC_Initialize` | med | Statically-linked MSVC CRT/STL function identified by signature match (fid+flirt, score=14.67;n=2;nocrc). Mangled: __RTC_Initialize. |
| 68e85e | `__RTC_Initialize_2` | med | Statically-linked MSVC CRT/STL function identified by signature match (fid+flirt, score=14.67;n=2;nocrc). Mangled: __RTC_Initialize. |
| 68f020 | `copyMatrix9` | med | Copies a 9-word block from struct+0x14 to struct+0x38 (e.g. matrix/transform snapshot) |
| 68f250 | `game_misc::alignLayout64` | med | Aligns/rounds layout rectangle fields (pos/size at +0x18..+0x34) to 64-byte (0x40) grid; two branches by param_1 |
| 691840 | `T1_Read_PFB_Segments` | med | FreeType/Type1: parse PFB font ('typ1'/CID/'TYP1' 0x43494420/0x54595031 tags), accumulating segment offsets |
| 692d00 | `T1_Open_Face` | med | FreeType: probe/open a Type1 or CID font ('cid'/'type1'), skip PFB header |
| 695be0 | `gray_render_arc_flatten` | med | FreeType(smooth): flatten a rotated arc/curve into line segments using FT_Sin/Cos |
| 695fc0 | `gray_arc_segment_emit` | med | FreeType(smooth): compute angle diff and flatten one arc segment via 695be0 |
| 696020 | `gray_render_cubic_arc` | med | FreeType(smooth): render a cubic-derived arc (modes 0/1/2) as flattened line segments |
| 6961a0 | `gray_render_conic_half` | med | FreeType(smooth): render half of a conic arc, choosing chord vs subdivide by curvature scale |
| 696270 | `gray_render_conic_full` | med | FreeType(smooth): render a conic arc segment with adaptive subdivision (curvature-dependent) |
| 696480 | `gray_render_arc_dispatch` | med | FreeType(smooth): dispatch arc rendering: if degenerate skip, else conic-half then conic-full |
| 402e50 | `std_copy_low_byte` | low | MSVC STL: copy low byte of each dword element in [param_1,param_2) to param_3 |
| 403ee0 | `eh_cleanup_delete_node` | low | MSVC EH: unwind funclet - destroy then operator_delete node |
| 404040 | `eh_cleanup_release` | low | MSVC EH: unwind funclet - virtual release of held object |
| 404060 | `std_ostream_sentry_dtor` | low | MSVC STL: ostream sentry destructor (_Osfx unless uncaught exception) |
| 404650 | `uivm_op_index_add` | low | UI expr VM: pop 2, push (b*DAT_00765004 + a) index computation |
| 404760 | `uivm_op_signed_combine` | low | UI expr VM: pop 2, push a+b or scaled-diff by sign |
| 404890 | `uivm_op_binary_call` | low | UI expr VM: pop 2, push result of helper FUN_0040bbb0(b,a,1) |
| 4049a0 | `uivm_op_add` | low | UI expr VM: pop 2 ints, push sum |
| 404ab0 | `uivm_op_scale` | low | UI expr VM: pop 2, push (int)((a+b)*3.25*0.3077) scaling |
| 404be0 | `uivm_op_logical_and` | low | UI expr VM: pop 2, push 1 if both nonzero else 0 |
| 404cf0 | `uivm_op_bool_and` | low | UI expr VM: pop 2, push (a!=0)*(b!=0) |
| 404e00 | `uivm_op_masked_and` | low | UI expr VM: pop 2, push ((a*b)&0x7ffffff)!=0 |
| 404f10 | `uivm_op_cond_and` | low | UI expr VM: pop 2, if both nonzero push via handler else push 0 |
| 405100 | `uivm_op_push_arg` | low | UI expr VM: push param_2 onto operand stack |
| 405120 | `widget_checkbutton_ctor` | low | UI/widget: build 'checkbutton' widget then push (string 'checkbutton') |
| 4051b0 | `uivm_op_push_or_zero` | low | UI expr VM: push param_2 (0 when zero) |
| 4051e0 | `uivm_op_push_scaled` | low | UI expr VM: push param_2 - (DAT_0076af00*param_2)/3 |
| 405210 | `uivm_dispatch_loop` | low | UI expr VM: bytecode dispatch loop over opcode handler table (ctx+0x40) |
| 405290 | `uivm_op_push_via_helper` | low | UI expr VM: push param_2 through helper FUN_0040c390 |
| 4052b0 | `uivm_op_store_state` | low | Stores param_2 into global state, accumulates *10 into another global, forwards to FUN_0040c390 |
| 4052e0 | `widget_caption_format_cos` | low | Builds a "caption" stringbuf from cos(param_2*0.1); widget label/value formatter |
| 4053b0 | `uivm_op_dispatch3` | low | 3-way switch on param_2 (0/1/2) each forwarding to FUN_0040c390 with side-effect on case 2 |
| 405640 | `uivm_op_load_indexed` | low | Reads operand-stack entry at signed index param_2, pushes its dereferenced dword back onto operand stack |
| 405700 | `uivm_op_idiv` | low | Pops two ints off operand stack, pushes integer quotient iVar1/iVar3 |
| 405850 | `uivm_op_ieq` | low | Pops two ints, pushes boolean (iVar1==iVar3) |
| 405960 | `uivm_op_ieq_sqdiff` | low | Pops two ints, pushes ((a-b)^2 < 1) i.e. integer equality test via squared diff |
| 405a70 | `uivm_op_ieq_scaled` | low | Pops two ints, pushes (iVar1*10 == iVar3*10) i.e. equality |
| 405ba0 | `uivm_op_ieq_offset` | low | Pops two ints, pushes ((a+3)-(b-1)==4) i.e. equality (a==b) |
| 405e70 | `uivm_op_fadd` | low | Pops two floats, pushes their sum |
| 405f90 | `uivm_op_fdiv` | low | Pops two floats, pushes local_14/fVar2 |
| 4060b0 | `uivm_op_feq` | low | Pops two floats, pushes boolean (a==b) |
| 4061e0 | `uivm_op_fle` | low | Pops two floats, pushes boolean (fVar1<=local_14) |
| 406300 | `uivm_op_flt` | low | Pops two floats, pushes boolean (fVar1<local_14) |
| 406420 | `uivm_op_fge` | low | Pops two floats, pushes boolean (local_14<=fVar1) |
| 406540 | `uivm_op_fgt` | low | Pops two floats, pushes boolean (local_14<fVar1) |
| 406660 | `uivm_op_push_const` | low | Pushes constant param_2 onto the operand stack |
| 4066f0 | `uivm_op_ftoi` | low | Pops one float, pushes truncated (int)fVar1 |
| 4067c0 | `uivm_op_ftoi_scaled` | low | Pops one float, pushes (int)(f*3*0.0142*10/0.426) scaled conversion |
| 4068b0 | `uivm_op_series_sum` | low | Pops one int, adds an arithmetic series computed over global DAT_0076500c, pushes result |
| 4069c0 | `uivm_op_identity_wrap` | low | Returns FUN_0040b9f0(a,b)*2/2 (identity wrapper around a subcomputation) |
| 4069e0 | `uivm_op_fmul` | low | Pops two floats, pushes their product |
| 406b00 | `uivm_op_fne` | low | Pops two floats, pushes boolean (a!=b) |
| 406c30 | `uivm_op_fsub` | low | Pops two floats, pushes local_14-fVar2 |
| 406d50 | `uivm_list_push_depth` | low | Computes operand-stack depth minus param_2, inserts as node into std::list via FUN_00583cb0 ("list<T> too long") |
| 406dc0 | `uivm_list_push_depth_off` | low | Like uivm_list_push_depth but adds global DAT_0076af04 to the computed depth before list insert |
| 406e30 | `uivm_list_push_cond` | low | If param_2>0 delegate to FUN_0040bac0 else insert (depth + DAT_0076502c*param_2) into std::list |
| 406ec0 | `uivm_list_push_depth2` | low | Inserts (operand-stack depth - param_2) as a node into std::list via FUN_00583cb0 |
| 406f30 | `uivm_op_ile` | low | Pops two ints, pushes boolean (iVar2<=local_14) |
| 407040 | `uivm_op_ile2` | low | Pops two ints, pushes boolean (iVar3<=iVar1) |
| 407170 | `uivm_op_ige` | low | Pops two ints, pushes boolean (iVar3>=iVar1) |
| 407290 | `uivm_op_ilt_flagged` | low | Pops two ints, pushes (a-b<0) optionally negated via global DAT_00765000/FUN_0040bb90 |
| 4073d0 | `uivm_op_icmp_special` | low | Pops two ints; if equal pushes squared-diff test else FUN_00403030(iVar3<=local_14) branch |
| 407510 | `uivm_op_load_scaled_index` | low | Loads operand-stack entry at index (param_2/DAT_00765010) and pushes it via FUN_0040d910 |
| 407570 | `uivm_op_load_scaled_index2` | low | Loads operand-stack entry at index ((DAT_0076af00+1)*param_2), copies via FUN_004034c0 and pushes |
| 407620 | `uivm_op_load_index_ret` | low | Loads/pushes operand-stack entry at index param_2, returns DAT_00765008-0xd |
| 407680 | `uivm_op_load_index` | low | Loads/pushes operand-stack entry at signed index param_2 |
| 4076d0 | `uivm_op_igt` | low | Pops two ints, pushes boolean (iVar1>iVar3) via flag-bit extraction |
| 4077f0 | `uivm_op_cmp_gt_adjusted` | low | Pops two operands from expr VM stack, adjusts first (==-10?-3:+7), pushes bool of >7 gap |
| 407910 | `uivm_op_cmp_scaled_lt` | low | Pops two ints, pushes bool(i3*const < i1*const) using DAT float scalers |
| 407a50 | `uivm_op_less_dispatch` | low | Opcode handler w/ param_2 selector (cases 3-6 push scaled consts); default pops two, pushes bool(i3<lhs) |
| 407c40 | `uivm_op_cmp_range` | low | Pops two operands, pushes bool(-3 < (i1-(i3+2))-1) |
| 407e00 | `uivm_fold_add_helper` | low | Numeric helper: folds param_1 toward 0 via loop, returns param_1+param_2 as float |
| 407e30 | `uivm_op_push_int_identity` | low | Pushes (param_2*3)/3 (== param_2) onto expr VM stack |
| 407ed0 | `uivm_op_push_folded` | low | Calls fold helper(2,param_2), pushes result int onto VM stack |
| 407f80 | `uivm_op_push_computed_array` | low | Builds 3x3 stack int matrix from param_2, pushes (arr[7]-2)/3 |
| 408080 | `uivm_op_int_to_float` | low | Pops int operand, pushes it as float onto expr VM stack |
| 408150 | `uivm_identity_int` | low | Returns param_2*2>>1 (identity), trivial int passthrough |
| 408160 | `uivm_op_mod5_stub` | low | Computes abs(param_2)%5 then security-cookie check; effectively no-op stub |
| 4081b0 | `uivm_map_small_int` | low | Maps param_2: 0->0, 1->1, else param_2-DAT const |
| 4081e0 | `uivm_identity_passthrough` | low | Returns param_2 unchanged (identity opcode) |
| 408230 | `uivm_op_select_if_zero` | low | Pops int; returns param_2 if popped==0 else 0 |
| 408280 | `uivm_op_accumulate` | low | Pops count; loops param_2 += running index (early-exit on DAT flag) |
| 4082f0 | `uivm_op_zero_if_nonzero` | low | Pops int; if nonzero forces param_2=0 |
| 408350 | `uivm_op_zero_if_nonzero_f` | low | Pops int; if abs(float sum of i,2i,3i)>0 forces param_2=0 |
| 4083f0 | `widget_btncheck_eval` | low | Pops int; if nonzero scans "btn:check" for ':' (returns index); widget check-button handler |
| 408460 | `uivm_op_cmp_push_const` | low | Pops two; if lhs<rhs pushes DAT-2 else pushes conditional const via push helper |
| 4085a0 | `uivm_op_cmp_push_vec` | low | Pops two ints, pushes bool(sum<-3), then inserts operand into VM stack vector (grow via FUN_0063ddc0) |
| 4088a0 | `uivm_op_series_compare` | low | Pops two; runs DAT_00765074-bounded accumulation loop, pushes bool(sumL<=sumR) |
| 408a00 | `uivm_op_le` | low | Pops two ints, pushes bool(i1+3 <= i3+3) i.e. i1<=i3 |
| 408b10 | `uivm_op_lt` | low | Pops two ints, pushes bool((i1-i3)*10<0) i.e. i1<i3 |
| 408c20 | `uivm_op_lt_double` | low | Pops two ints, pushes bool((double)i1 < (double)i3) |
| 408d50 | `uivm_op_cmp_push_scaled` | low | Pops two; if lhs<rhs pushes DAT*i2*2 else pushes scaled/negated const via push helper |
| 408eb0 | `uivm_op_lt_2` | low | Pops two ints, pushes bool(l14 < i2) |
| 4090b0 | `uivm_op_mod` | low | Pops two ints, pushes i1 % i3 |
| 4091c0 | `uivm_op_mul` | low | Pops two ints, pushes ((i1*2)/2)*i3 == i1*i3 |
| 4092e0 | `uivm_op_mul_2` | low | Pops two ints, pushes i3 * i1 |
| 4093e0 | `uivm_op_affine` | low | Pops two ints, pushes (DAT+1+i2)*(DAT+i3-1) |
| 409500 | `uivm_op_ne_offset` | low | Pops two ints, pushes bool((i1+8)-(i3-DAT) != 0xc) |
| 409620 | `uivm_op_diff` | low | Pops two ints; if i2!=i3 sets i3=i2-1, pushes i2-i3 |
| 409730 | `widget_frame_text_eval` | low | Evaluates "frame:text" via FUN_0040bef0, pops two, pushes bool(count==0); widget frame:text handler |
| 409860 | `uivm_op_abs_compare` | low | Pops two ints, pushes bool(abs(i1-i3) sign-normalized nonzero & >=0) |
| 409970 | `uivm_op_ne` | low | Pops two ints, pushes bool(i3 != i1) |
| 409a80 | `uivm_op_is_zero` | low | Pops one int, pushes bool(i1 == 0) (logical NOT) |
| 409b50 | `uivm_op_is_zero_scaled` | low | Pops one int, pushes bool(DAT*i1 == 0) |
| 409c20 | `uivm_op_abs_le_zero` | low | Pops one int, pushes bool(abs(i)<=0) via sign-fold |
| 409cf0 | `uivm_op_cond_flag` | low | Pops one int; if nonzero pushes 0 else pushes bool(DAT_00765028>0) |
| 409de0 | `uivm_op_is_zero` | low | Pops one operand off VM operand stack, pushes bool(v*v==0) i.e. v==0 test |
| 409eb0 | `uivm_op_logical_or` | low | Pops two operands, pushes 1 if either nonzero else 0 (logical OR) |
| 409fc0 | `uivm_op_absum_positive` | low | Pops two operands, pushes 1 if abs(a)+abs(b) > 0 |
| 40a0e0 | `uivm_op_logical_or2` | low | Pops two operands, pushes 1 if either nonzero else 0 (logical OR variant) |
| 40a200 | `uivm_op_logical_or_call` | low | Pops two operands, invokes FUN_004054b0, pushes logical-OR of the two values |
| 40a350 | `uivm_pop_n_operands` | low | Pops param_2 operands off VM operand stack in a loop, deleting each |
| 40a3a0 | `uivm_pop_operands_alt` | low | Loops param_2 times popping operands, alternating between two temp buffers |
| 40a430 | `uivm_op_push_zero_wrapper` | low | Zeroes a temp, calls FUN_004054b0 then FUN_004022f0 to push/emit result |
| 40a4c0 | `uivm_pop_operands_switch` | low | Pops param_2 operands with special-cased unrolling for counts 1 and 2 |
| 40a560 | `uivm_op_push_indexed` | low | Pushes operand read from ctx array at +0x2c indexed via +0x38 table and param_2 |
| 40a600 | `uivm_op_push_int` | low | Pushes param_2 as a new 4-byte operand onto the VM operand stack |
| 40a690 | `uivm_op_button_press_push` | low | Compares literal 'button:press' (tautology) then pushes param_2 operand |
| 40a740 | `uivm_op_push_repeat` | low | Pushes param_2 as operand 4 times, popping stack each iteration (unrolled loop) |
| 40a860 | `uivm_op_dispatch_or_push` | low | Switch on param_2: calls FUN_00403030 for cases 0/1/3/4, else pushes param_2 |
| 40a9c0 | `uivm_pop_and_process` | low | Pops one operand off stack then hands it to FUN_004040d0 for processing |
| 40aa50 | `uivm_eval_and_emit` | low | Evaluates via FUN_0040bef0 + FUN_0040bb30, then emits result via FUN_004040d0 |
| 40aaf0 | `uivm_eval_wrapper` | low | Wrapper over uivm_eval_and_emit; returns (result & 0xf7) * global scale |
| 40ab10 | `uivm_build_and_emit` | low | Builds a temp operand container, calls FUN_00402210, then emits via FUN_004040d0 |
| 40abf0 | `uivm_pop_and_emit` | low | Pops one operand off stack then emits it via FUN_004040d0 |
| 40ac80 | `uivm_compute_offsets` | low | Builds int array of size param_2 of accumulated field-width differences, calls FUN_00402280 |
| 40ad70 | `uivm_op_build_buffer_push` | low | Computes per-element offsets, builds byte buffer via memcpy, pushes onto operand stack |
| 40af30 | `uivm_op_compute_push` | low | Computes per-element offsets into byte buffer and pushes result operand onto stack |
| 40b0a0 | `uivm_op_wrap_offset` | low | Thin wrapper calling uivm_compute_push_range with a global base offset added |
| 40b0c0 | `uivm_op_compute_eval_push` | low | Computes offsets, evaluates via FUN_0040bef0, pushes operand; has stack cookie |
| 40b270 | `uivm_op_sub` | low | Pops two operands, pushes their difference (a - b) |
| 40b380 | `uivm_op_sub_wrap` | low | Thin wrapper forwarding to uivm_op_sub_variant (FUN_0040bd50) |
| 40b390 | `uivm_op_sub2` | low | Pops two operands, pushes their difference (a - b) |
| 40b550 | `uivm_op_push_int2` | low | Pushes param_2 as a new operand onto the VM operand stack |
| 40b5e0 | `uivm_op_push_adjusted` | low | Pushes global_count + (param_2 - global_base) - 0x13 as operand |
| 40b680 | `uivm_op_push_or_offset` | low | If (param_2 & mask)==3 pushes param_2, else forwards to uivm_op_push_offset |
| 40b9f0 | `uivm_op_float_to_int` | low | Pops one float operand, pushes its truncated int value |
| 40bb30 | `uivm_operand_construct` | low | Constructs 3-word operand container; if param_3==0 pops else inits and calls FUN_00405470 |
| 40bb90 | `uivm_op_not_array` | low | Loops param_2 times negating each dword in place: *p = (*p==0) |
| 40bbb0 | `add_int` | low | Trivial helper returning param_1 + param_2 |
| 40bbc0 | `uivm_compute_pop_range` | low | Computes offsets over (param_2-param_3) elements, then pops/adjusts operand stack |
| 40bd50 | `uivm_op_sub_variant` | low | Pops two operands, pushes their difference (a - b) |
| 40be60 | `uivm_op_push_offset` | low | Pushes global_count + param_2 as a new operand |
| 40c390 | `uivm_map_lookup_pop` | low | RB-tree lower-bound lookup by key; if key absent pops operands+pushes 0, else calls node vfunc |
| 40d860 | `uivm_pop_and_list_erase` | low | Erases a list node at ctx+0x38, pops operand, calls FUN_00487380 and FUN_004040d0 cleanup |
| 411d00 | `get_field_ptr_0x2e4` | low | return this+0x2e4 (game accessor, not lib) |
| 42b810 | `CharCreation::cycle_hairstyle_prev` | low | game char-customization prev button: play sound, wrap index, refresh |
| 42b860 | `CharCreation::cycle_hairstyle_next` | low | game char-customization next button (index+1 wrap 3) |
| 42b8b0 | `CharCreation::apply_color_set` | low | copy 3 color bytes then refresh model (game) |
| 42b910 | `CharCreation::adjust_dec_0x198` | low | decrement customization field 0x198, refresh (game) |
| 42b950 | `CharCreation::adjust_inc_0x198` | low | increment customization field 0x198, refresh (game) |
| 42b990 | `CharCreation::toggle_field_0x194` | low | toggle/wrap field 0x194, refresh (game) |
| 42b9e0 | `CharCreation::adjust_dec_0x19c` | low | decrement field 0x19c, refresh (game) |
| 42ba20 | `CharCreation::adjust_inc_0x19c` | low | increment field 0x19c, refresh (game) |
| 42ba60 | `CharCreation::cycle_prev_0x18c` | low | decrement field 0x18c wrap 7, refresh (game) |
| 42bab0 | `CharCreation::cycle_next_0x18c` | low | increment field 0x18c wrap 8, refresh (game) |
| 42bd90 | `CharCreation::reset_defaults` | low | reset char-customization state fields to defaults (game) |
| 43ec90 | `lookup_float_by_id` | low | switch mapping id to float constant (game data table) |
| 444860 | `Ability::get_cooldown` | low | switch mapping ability id to cooldown/duration float (game) |
| 446950 | `set_vec3_offset_by_id` | low | switch setting vec3 constant by id (game data) |
| 446e80 | `Creature::compute_stat_pow` | low | compute stat using pow() over modifier list (game) |
| 459660 | `T::T()` | low | Default-ctor of struct: init fields to -1 / default floats (0x3f000000 etc) |
| 465b60 | `T::T()` | low | Default-ctor: init header fields then memset 0x100-byte buffer to 0 |
| 46eb80 | `GameController::set_field_1b4` | low | Store param into object field +0x1b4 (game object setter) |
| 46f390 | `GameController::set_camera_transform` | low | Copy 6 float/double transform fields into obj+0x170 and apply |
| 4814f0 | `GameController::cycle_active_tab` | low | Advance active UI tab selection among widget group (game) |
| 4815c0 | `GameController::on_tab_selected` | low | If arg matches active tab id, invoke handler (game UI) |
| 4815e0 | `GameController::create_edit_textbox` | low | Create 'edit' text input widget in UI (game) |
| 481d30 | `GameController::delete_selected_world_saves` | low | DeleteFile Save\world_/Save\map_ for selected slot (game) |
| 481fe0 | `GameController::show_rename_dialog` | low | Build 'edit' widgets for world rename UI (game) |
| 483e70 | `GameController::load_or_new_character` | low | Load selected character save or reset to defaults (game) |
| 484170 | `GameController::reset_editor_camera` | low | Reset editor camera/target vectors to defaults (game) |
| 484230 | `GameController::toggle_sp_mp_worlds` | low | Toggle singleplayer/multiplayer world list label (game) |
| 488bd0 | `GameController::toggle_widget_8008c0` | low | Toggle a UI flag and refresh dependent widget (game) |
| 488c00 | `GameController::toggle_widget_8008bc` | low | Toggle UI flag, run two handlers, clear related flag (game) |
| 488c70 | `GameController::apply_editor_settings` | low | Copy editor param block into world object on toggle (game) |
| 488d00 | `GameController::toggle_widget_800910` | low | Toggle UI flag and clear a mutually-exclusive flag (game) |
| 4c04c0 | `render::build_projectile_mesh` | low | Generate swept projectile/trail geometry via sin/cos (game render) |
| 4c5a00 | `GameController::increment_tab_value` | low | Increment value of active tab entry if below max (game UI) |
| 4c5a60 | `GameController::navigate_next_tab` | low | Move to next UI tab, log 'tab:' to cout, refresh (game UI) |
| 4c5bb0 | `GameController::set_slider_from_mouse` | low | Map mouse X to slider value in active tab (game UI) |
| 4c60f0 | `GameController::decrement_tab_value` | low | Decrement value of active tab entry if above zero (game UI) |
| 4c7ed0 | `Creature::roll_random_stat` | low | Roll random stat in range using rand() (game) |
| 4ce6c0 | `std_istream_sentry_unwind_thunk` | low | Exception cleanup thunk: invoke streambuf vtable[+8] (sync) on unwind for istream ops |
| 4d4650 | `OptionsMenu_applyAndClearSelection` | low | Apply options (FUN_0046f390) then reset a selection index in the active UI list |
| 4d4cb0 | `UiCarousel_selectPrev` | low | Decrement (clamp>=0) circular option index and update selected value pair from list |
| 4d4d20 | `UiCarousel_selectNext` | low | Increment (clamp<size) circular option index and update selected value pair from list |
| 4d8ef0 | `xml_scanAttrValue_variant0` | low | Attribute-value scanner variant (encoding/flag jump-table target from FUN_004d7a60) |
| 4d8f40 | `xml_scanAttrValue_variant1` | low | Attribute-value scanner variant with entity decode (jump-table target) |
| 4d9000 | `xml_scanAttrValue_variant2` | low | Attribute-value scanner variant (jump-table target) |
| 4d90d0 | `xml_scanAttrValue_variant3` | low | Attribute-value scanner variant with entity decode (jump-table target) |
| 4d91d0 | `xml_scanAttrValue_variant4` | low | Attribute-value scanner variant (jump-table target) |
| 4d9340 | `xml_scanAttrValue_variant5` | low | Attribute-value scanner variant with entity decode (jump-table target) |
| 4e29a0 | `node_erase_and_free` | low | Erase a node then operator delete (FUN_004e3840) |
| 4e29d0 | `node_erase_and_free_v2` | low | Erase a node then operator delete (FUN_004e3bb0) |
| 4e2a70 | `object_dtor` | low | Destroy object and operator delete |
| 4e2aa0 | `object_dtor_v2` | low | Destroy object (ctor_2 cleanup) then operator delete |
| 4e3630 | `tree_free_recursive_v2` | low | Recursively free tree nodes (payload FUN_0046f990) then delete |
| 4e3bb0 | `map_erase_node` | low | Erase one map node (FUN_004e3c70 rebalance) then free (FUN_004e3630) |
| 4e5e70 | `object_dtor_v3` | low | Destroy object then operator delete (FUN_00452650) |
| 4e6af0 | `object_dtor_v4` | low | Destroy object (FUN_004e6e60) then operator delete |
| 51d320 | `sqlite3_scalarFunc_intValue` | low | SQL scalar function: read arg int value then store result (FUN_00525a30) |
| 51d3d0 | `sqlite3_scalarFunc_length` | low | SQL scalar function: text arg -> compute (FUN_005203c0) -> set int result |
| 51d510 | `sqlite3_result_error_thunk` | low | Thunk forwarding to result-error helper (FUN_00574570) |
| 51d520 | `sqlite3_scalarFunc_lookupConst` | low | SQL scalar function: index constant string table (CURDIR...) by int arg, set text result |
| 51de20 | `sqlite3_value_flag_byte` | low | Return byte at value+0x36 (a Mem flag/type accessor) |
| 51de30 | `sqlite3SafeDeref_u32` | low | Return *param or 0 if null (null-safe dword deref helper) |
| 51e950 | `sqlite3_global_state_set` | low | Store param into global DAT_007666a4 (config/state setter) |
| 51f310 | `sqlite3MallocStatusObj_init` | low | Allocate+init small status/allocator struct (0x30 core) |
| 51f920 | `pcache1_flush` | low | Reset pcache list count then restore under mutex |
| 51ff10 | `sqlite3_status_get` | low | Mutex-guarded read of status counter at obj+0x24 |
| 51ff50 | `sqlite3PcacheGetXY` | low | Copy two dwords (offset 8,0xc) into out struct |
| 5203c0 | `sqlite3TempStoreOptMatch` | low | Match string vs SQLITE_/CURDIR/TEMP_STORE=1 option list |
| 5204f0 | `sqlite3_...pathResultFunc` | low | Fetch value text, transform via 0057a1b0, set text result |
| 521390 | `sqlite3VdbeMemFinalizeMove` | low | Move/finalize Mem, copy int64 fields into out struct |
| 521820 | `sqlite3VdbeMemRelease_helper` | low | Release Mem then mutex leave helper |
| 522310 | `sqlite3_finalize_wrap` | low | Reset stmt (00528070) then release |
| 522370 | `sqlite3_vfs_stub_a` | low | Tiny VFS/method stub (no strings/callees) |
| 522390 | `sqlite3_value_wrap_a` | low | Thin wrapper over 0052e130 value helper |
| 5223b0 | `sqlite3VdbeMemResultText` | low | Set text result with size check ('string or blob too big') |
| 522460 | `sqlite3_value_wrap_b` | low | Thin wrapper over 0052e130 value helper |
| 522540 | `sqlite3PagerHelper_a` | low | Calls mutex check + 0057d3f0 (pager/os helper) |
| 5225c0 | `sqlite3_leaf_stub_a` | low | Leaf helper, no callees |
| 522640 | `sqlite3_mutex_guard_b` | low | Mutex-enter check (00579f80) helper |
| 522660 | `sqlite3_leaf_stub_b` | low | Leaf helper, no callees |
| 522820 | `winSleep_or_charstub` | low | Small os_win const/stub method |
| 5229f0 | `sqlite3_midsize_helper_a` | low | Mid helper, no captured callees |
| 522bf0 | `sqlite3MisuseError` | low | Log misuse at line via 00525a30 |
| 522ca0 | `sqlite3_helper_548d00` | low | Thin wrapper over 00548d00 |
| 522d40 | `winShmMethod_or_hash` | low | Larger os_win/hash routine (no captured strings) |
| 523050 | `sqlite3_leaf_stub_c` | low | Leaf helper |
| 523220 | `winShm_stub` | low | os_win.c shm/method stub |
| 523260 | `winGetLastErrorHelper` | low | GetLastError + 0053a8f0 error map |
| 523280 | `win_stub_d` | low | os_win tiny stub |
| 523290 | `win_stub_e` | low | os_win tiny stub |
| 5232a0 | `win_stub_f` | low | os_win tiny stub |
| 5232b0 | `win_stub_g` | low | os_win tiny stub |
| 5237f0 | `sqlite3_leaf_stub_d` | low | Leaf helper |
| 523dd0 | `sqlite3VdbeValueCopyHelper` | low | Copy/convert value helper (00574570/00574d40) |
| 524160 | `sqlite3Malloc_helper_a` | low | Alloc helper (mutex + 0055da00) |
| 524180 | `sqlite3Malloc_helper_b` | low | Alloc/resize helper (mutex + 00563800) |
| 5244c0 | `sqlite3_leaf_stub_f` | low | Leaf helper |
| 5244e0 | `sqlite3_result_type_integer` | low | Set 'integer' typed result/name |
| 524640 | `sqlite3_leaf_stub_g` | low | Leaf helper |
| 5246a0 | `sqlite3Btree_helper_b` | low | Btree helper (005644e0) |
| 5247b0 | `sqlite3_leaf_stub_h` | low | Leaf helper |
| 5253b0 | `sqlite3_leaf_stub_i` | low | Leaf helper |
| 525500 | `sqlite3_leaf_stub_j` | low | Leaf helper |
| 525510 | `sqlite3_leaf_stub_k` | low | Leaf helper |
| 525580 | `sqlite3_leaf_stub_l` | low | Leaf helper |
| 5255b0 | `sqlite3VdbeSetResultErr` | low | Set error result string via 00540b70/00575040 |
| 5256b0 | `cdate_int_helper` | low | Date/int helper with 'integer overflow' guard |
| 5259c0 | `sqlite3_leaf_stub_m` | low | Leaf helper |
| 525a20 | `sqlite3_errcode_helper_b` | low | Wrapper over 00540b70 (error-state) |
| 525a50 | `sqlite3_leaf_stub_n` | low | Leaf helper |
| 525ff0 | `sqlite3_leaf_stub_p` | low | Leaf helper |
| 5260c0 | `sqlite3_leaf_stub_q` | low | Leaf helper |
| 526590 | `sqlite3PagerHelper_b` | low | Wrapper over 00563550 (pager) |
| 5265b0 | `sqlite3PagerHelper_c` | low | Wrapper over 00563550 (pager) |
| 5265d0 | `sqlite3_leaf_stub_r` | low | Leaf helper |
| 5265f0 | `sqlite3_midsize_helper_b` | low | Mid helper, no captured callees |
| 526810 | `sqlite3_context_result_a` | low | Context result setter (0057d290 + 00574df0) |
| 526870 | `sqlite3_context_result_b` | low | Context result setter (0057d290 + 00574ec0) |
| 5268d0 | `sqlite3_leaf_stub_s` | low | Leaf helper |
| 5268e0 | `sqlite3_context_result_c` | low | Context result setter (0057d290 + 00574ec0) |
| 526b00 | `sqlite3_context_helper_d` | low | Context/status helper (0057d290) |
| 526b40 | `sqlite3_leaf_stub_t` | low | Leaf helper |
| 526be0 | `sqlite3MemSize_b` | low | Malloc-subsystem size wrapper (0052e070) |
| 526c00 | `sqlite3_context_helper_e` | low | Context/status helper (0057d290) |
| 526d60 | `sqlite3_context_helper_f` | low | Context helper (0057d290 + 00575240) |
| 526db0 | `sqlite3_leaf_stub_u` | low | Leaf helper |
| 526dc0 | `sqlite3_leaf_stub_v` | low | Leaf helper |
| 526df0 | `sqlite3_leaf_stub_w` | low | Leaf helper |
| 526e20 | `sqlite3_leaf_stub_x` | low | Leaf helper |
| 526e80 | `sqlite3_column_value` | low | Copy a column's Mem value to caller |
| 526f90 | `sqlite3_leaf_stub_y` | low | Leaf helper |
| 527290 | `sqlite3_value_text_b` | low | Value text/blob accessor (0056bce0) |
| 527570 | `sqlite3_leaf_stub_z` | low | Leaf helper |
| 527670 | `sqlite3_column_name` | low | Column name/metadata accessor |
| 527f30 | `sqlite3_column_blob16_a` | low | Column value16 accessor |
| 527f60 | `sqlite3_column_blob16_b` | low | Column value16 accessor |
| 527fc0 | `sqlite3_column_bytes16` | low | sqlite3_column_bytes16 / decltype helper |
| 528030 | `sqlite3_column_type_b` | low | Column type/int accessor |
| 5281b0 | `sqlite3_column_decltype` | low | Column decltype/name accessor (00574d80/005521a0) |
| 528800 | `sqlite3_stmt_get_db_ptr` | low | Accessor returning field at *(stmt+0x30)+0x18 (Vdbe.db or error offset) |
| 528810 | `sqlite3_expr_is_flag_helper` | low | Return true when Expr pointer is null or property flag 0x20 is set |
| 528830 | `sqlite3ExprCompare_helper` | low | Compare two Expr/Column nodes by field 0x4c, propagate flag 0x20 for reduced nodes, delegate deep compare |
| 52b7d0 | `sqlite3VdbeCodeOffset` | low | Emit VDBE op 0x77 (offset/next) with param_2/param_3 when param_2 is positive |
| 52efa0 | `sqlite3_invoke_rollback_update_hooks` | low | Invokes registered rollback/update hook callbacks, building a transient cursor/value for the update hook |
| 530580 | `sqlite3_select_result_codegen` | low | Generates VDBE code for a result/GROUP-BY expression list, tracking column names and affinities |
| 530850 | `sqlite3_apply_affinity_codegen` | low | Trims blob-affinity padding then emits OP_String/affinity ops for a value into a register |
| 530cf0 | `sqlite3_codegen_result_column` | low | Generates code to output one result column (literal 'L'/'I' or table column) in the select inner loop |
| 533710 | `msvc_crt_osver_dispatch_helper` | low | CRT helper: caches OS version via GetVersionExA then dispatches to a variant routine |
| 533880 | `util::copy_buffer_cond` | low | memcpy in one direction, or sync (FUN_00560330) then copy the other, based on param_4 |
| 5342a0 | `sqlite3_vdbeExprDecRef` | low | Walks parent-cursor chain clearing a flag and decrementing reference counts (stride 0x28) |
| 534920 | `sqlite3_estLog10` | low | Returns count of decimal magnitude steps (n where 10^n exceeds input); numeric estimate |
| 536090 | `sqlite3_codeExprVectorTerm` | low | Constructs temp Expr nodes (ops 'N'/'E'/'P') and codes them into a register |
| 536500 | `sqlite3_exprNodeIsConstant` | low | Walker callback: marks expr non-constant unless op is a constant/bound kind, returns 2 |
| 5367f0 | `sqlite3_analyzeAggWalker` | low | Walker callback tallying aggregate/column reference counters on matching op nodes |
| 53b920 | `sqlite3_expr_walk_agg_cb` | low | Expr-walker callback: for TK_AGG nodes (-0x67) adjusts an aggregate-depth counter |
| 53c270 | `fkLocateIndexMatch` | low | fkey.c: match a foreign-key parent index by walking Expr/column token list |
| 53c3f0 | `fkChildIsModified` | low | fkey.c: FK helper testing whether referenced child columns changed |
| 53c4e0 | `sqlite3FkCheck` | low | fkey.c: generate FK constraint enforcement code for a row op |
| 53c730 | `sqlite3ExprSkipCollate` | low | expr.c: small Expr accessor/skip helper |
| 53c840 | `whereClauseInsert` | low | where.c: expr traversal / clause insertion helper |
| 53cc30 | `journal::hdr_offset` | low | Computes the next journal header offset via 64-bit page-size rounding |
| 53cd40 | `sqlite3ExprListFlags` | low | expr.c: small accessor with no callees |
| 53e110 | `sqlite3ValueNew` | low | vdbemem.c: allocate a Mem/sqlite3_value |
| 53e1b0 | `valueNewWrap` | low | vdbemem.c: wrapper around value allocator |
| 53e230 | `sqlite3BtreeXXX` | low | btree.c: cursor/page helper invoking pager rollback path |
| 53e280 | `valueNewWrap2` | low | vdbemem.c: wrapper around value allocator |
| 53e310 | `sqlite3VdbeMemFromBtree` | low | vdbemem.c: build Mem value, releases page via pager path |
| 540b00 | `sqlite3PagerRefcount` | low | pager.c: small ref/count accessor |
| 541210 | `sqlite3PagerFilename` | low | pager.c: return pager filename |
| 541240 | `sqlite3PagerJournalMode` | low | pager.c: journal-mode accessor |
| 541820 | `pagerWalFrames` | low | pager.c/wal.c: append dirty pages as WAL frames |
| 543be0 | `sqlite3ExprDelete` | low | expr.c: recursively free an Expr tree |
| 5440c0 | `sqlite3DbMallocZero` | low | malloc.c: db-scoped zeroed allocation |
| 544290 | `sqlite3DbFreeNN` | low | malloc.c: free db allocation (non-null) |
| 5442c0 | `sqlite3MallocSize` | low | malloc.c: return allocation size |
| 544320 | `sqlite3DbMallocSize` | low | malloc.c: return db allocation size |
| 544360 | `dbReallocFinish` | low | malloc.c: db realloc copy+free helper |
| 544470 | `sqlite3DbFreeVec` | low | malloc.c: free helper |
| 544540 | `sqlite3HeapNearlyFull` | low | malloc.c: memory pressure accessor |
| 544d30 | `file::read32_be` | low | Reads a 4-byte big-endian integer at a file offset via the VFS read method |
| 5451e0 | `sqlite3VdbeAddOp` | low | vdbeaux.c: emit VDBE opcode helper |
| 546090 | `sqlite3ResolveExprNames` | low | resolve.c: expr accessor/small resolve helper |
| 546470 | `sqlite3ExprListDup` | low | expr.c: getter/list helper |
| 5469d0 | `sqlite3ExprIsConstantOrFunction` | low | expr.c: constness/predicate walk helper |
| 5471b0 | `sqlite3VdbeMemMove` | low | vdbemem.c: move/copy Mem (recursive helper) |
| 547210 | `sqlite3VdbeMemCopy` | low | vdbemem.c: deep-copy Mem (recursive helper) |
| 547720 | `sqlite3ExprCode` | low | expr.c: code-generate an Expr into a register |
| 547860 | `sqlite3ExprCodeCopy` | low | expr.c: wrapper over Expr code generation |
| 548960 | `sqlite3SelectOpName` | low | select.c: small select accessor |
| 548ba0 | `clearSelect` | low | select.c: recursively free Select structures |
| 549380 | `sqlite3AddCollateType` | low | build.c: set collating sequence for column |
| 54ab50 | `sqlite3AuthContextPush` | low | auth.c: authorization helper ('not authorized') |
| 54b260 | `codeAttach` | low | attach.c: generate VDBE code for ATTACH/DETACH |
| 54bc80 | `sqlite3FinishCoding` | low | build.c: small codegen helper |
| 54bcc0 | `sqlite3ExprDupSel` | low | expr.c: duplicate helper |
| 54bd10 | `sqlite3PagerOpenSavepoint` | low | pager.c: allocate/open pager savepoints (Bitvec+malloc) |
| 58d8f0 | `MapNode_CreateA` | low | Game/STL: allocates a map node (FUN_004050c0) and copies one dword field from param_1+0x18 |
| 58e8e0 | `Array_CopyStructs188` | low | Game: copies an array of 0x188-byte structs, deep-copying each via FUN_0058ea10 (SEH-guarded) |
| 62f690 | `tree_nodeInsertLeaf` | low | Inserts a leaf node (FUN_0040c0a0 alloc, external:00000111) |
| 62f8c0 | `tree_allocLeaf` | low | Allocates a leaf node (FUN_00630a40 + FUN_0064af30) |
| 659fe0 | `makeTextureRefWrapper` | low | Wraps FUN_00425390(1,param_3) result via FUN_0040eaf0; returns param_1 unchanged (constructs a resource handle). |
| 692de0 | `T1_Build_CharString_Table` | low | FreeType/Type1: assemble a Type1 subrs/charstrings buffer (0x180/0x380 markers), open as 'type1' |

## game_misc (567)

| addr | proposed name | conf | purpose |
|---|---|---|---|
| 402e20 | `copyBytes` | high | Byte copy loop from [param_1,param_2) into param_3 (char std::copy) |
| 4030c0 | `swap_u32` | high | std::swap of two 4-byte values |
| 4032e0 | `string_moveConstruct2` | high | MSVC std::string move-construct (variant): moves buffer, copies len/cap, resets source |
| 404090 | `string_moveAssign` | high | std::string move-assign with self-check: frees own buffer then moves source |
| 405420 | `string_fillAssign` | high | std::string fill: writes param_3 char param_2 times (single store or memset) |
| 40bff0 | `string_appendFill` | high | std::string append(count,char): grows then fills with FUN_00405420 |
| 40c280 | `string_assignPtrLen` | high | std::string assign(ptr,len): overlapping-range fast path or realloc+memcpy |
| 40c380 | `string_data` | high | std::string c_str/data: returns heap ptr if cap>0xf else inline buffer |
| 40c590 | `memcmp_traits` | high | char_traits memcmp: 4-byte-unrolled byte compare, returns -1/0/1 |
| 40d9d0 | `vectorInt_resize` | high | std::vector<int>::resize: shrinks (memmove) or grows zero-filling to param_1 elements |
| 40e440 | `wostream_insertNarrow` | high | operator<<(wostream, const char*): widens each char via ctype, applies field width padding |
| 40e940 | `useFacet_ctypeW` | high | std::use_facet<ctype<wchar_t>>: locates/registers ctype facet in locale, throws bad_cast on failure |
| 40ea30 | `setPair_a` | high | Stores 2 dwords into object (assign vec2/pair) |
| 40ee40 | `setColor4b` | high | Copies 3 bytes from param_1 and sets 4th byte to param_2 (RGBA set) |
| 40ef80 | `vec2_scale` | high | Scales 2-component float vector in place by param_1 |
| 40f8c0 | `std::wstring::operator_delete_wrapper` | high | deallocate wstring buffer via operator delete |
| 411d10 | `powf_f` | high | Returns powf(param_1,..) via libm_sse2_pow_precise |
| 411e10 | `copy16bytes` | high | Copies two 8-byte values into object (16-byte/2x double copy) |
| 412320 | `vec2_dot` | high | Returns 2D dot product of this and param_1 |
| 423e70 | `mat4_identity` | high | Sets object to 4x4 identity matrix |
| 423ee0 | `vec2_length` | high | Returns sqrt(x^2+y^2) (2D vector length) |
| 424090 | `vec2_normalize` | high | Normalizes this vec2 in place (divide by length) |
| 424b30 | `asinf_f` | high | Returns asinf(param_1) via libm_sse2_asin_precise |
| 424f30 | `mat4_mulRight` | high | 4x4 matrix multiply: param_1 = param_1 * param_2 (copies this then multiplies) |
| 427a30 | `copyVec4Array` | high | Copies array of 16-byte (vec4/4-dword) elements [param_1,param_2) to param_3 |
| 427ab0 | `copyVec2Array` | high | Copies array of 8-byte (vec2/2-dword) elements [param_1,param_2) to param_3 |
| 427af0 | `copyVec4Array2` | high | Copies array of 16-byte elements [param_1,param_2) to param_3 (null-dst tolerant) |
| 428c80 | `vectorReserveCheck8` | high | std::vector reserve growth guard for 8-byte elements, throws _Xlength_error if too long |
| 428d00 | `vectorReserveCheck16` | high | std::vector reserve growth guard for 16-byte elements, throws _Xlength_error if too long |
| 42b7a0 | `vectorErase8` | high | std::vector erase of 8-byte elements: shifts tail down [param_2,param_3) and adjusts end |
| 42bd20 | `std::vector::push_back_16` | high | push_back one 16-byte element, reserve if full |
| 42c4a0 | `vec3i64::toFloat` | high | Converts three int64 fixed-point coords to float via ×1/65536 (1.5258789e-05) |
| 42c5b0 | `vec6::copy` | high | Copies 6 dwords param_1->ECX (3x int64 / 192-bit vector copy) |
| 42c7a0 | `vec3i64::copySub` | high | Copies 6 dwords then subtracts param_2 as three int64 (borrow chains) |
| 42c800 | `vec3i64::copyAdd` | high | Copies 6 dwords then adds param_2 as three int64 (carry chains) |
| 42f040 | `vec3i64::toIntFloor` | high | Converts three 16.16 fixed int64 to int with floor rounding (/0x10000, -1 if negative) |
| 4348c0 | `getFlagBit6` | high | Returns bit 6 of byte at ECX+3 |
| 434d10 | `world::getRegionCell64` | high | World coords->64-grid cell: validates <0x10000 >>6, resolves via 00434a90, returns ptr at +0x10018 (4-byte) |
| 43c820 | `ptr::equalsFirst` | high | Returns *ECX == *param_1 (compare first pointer field) |
| 43c8e0 | `list::allocNode20` | high | operator_new(0x14) self-linked node sentinel; _Xbad_alloc on fail |
| 43c980 | `curve::diminishing01` | high | Returns diminishing-returns curve 1 - 1/(n*0.1+1), 0 if n<1 |
| 43e2c0 | `curve::diminishingx3p1` | high | Returns (1-1/(n*0.1+1))*3+1, 0 if n<1 |
| 43e660 | `curve::diminishingN1` | high | Returns 1 - 1/((n+1)*0.1+1) curve |
| 43f770 | `curve::diminishingx3p15` | high | Returns (1-1/(n*0.1+1))*3+1.5, 0 if n<1 |
| 444230 | `weapon::isSpecialRune` | high | Returns 1 if weapon rune byte +0xaa9==3-class and subtype in set |
| 445f60 | `math::pow2Mul` | high | Returns 2^a * 2^b (two libm pow calls, product) |
| 445ff0 | `math::pow2Div` | high | Returns (2^a * 2^b) / 2^c (three pow calls) |
| 446aa0 | `curve::diminishingP1` | high | Returns (1-1/(n*0.1+1))+1, 0 if n<1 |
| 4476a0 | `curve::diminishingHalf` | high | Returns (1-1/(n*0.1+1))*0.5+0.5, 0.5 if n<1 |
| 4496a0 | `blob::deobfuscate` | high | Deobfuscates a byte buffer: table-driven (006ffa68) shuffle/unswap then bitwise-complement each byte |
| 44a970 | `reset_0x148Struct` | high | Reset/init a 0x148 struct: set [8]=1, zero header, memset 0x100 buffer, magic 0x3d924925 |
| 44af00 | `dtor_13Strings_0x118` | high | Destructs 13 sub-objects at stride 0x118 via 0042c5e0 (array of string-bearing structs) |
| 44b7b0 | `allocNode_0x48_copyHead` | high | Allocates 0x48 node, copies *ecx into 3 link slots |
| 44be30 | `isNonNegativeFlag` | high | Returns ~(byte[ecx+3]>>7)&1 (sign bit test / is-red or is-positive) |
| 450f00 | `bytesToVec3Float` | high | Convert 3 bytes to 3 floats (color/normal decode) |
| 451210 | `std::operator>>(wistream,wstring)` | high | extract wstring from wistream skipping via ctype (_Ipfx,getloc) |
| 451380 | `std::operator>>_wstring_unwind` | high | exception cleanup epilog for wstring extraction |
| 451470 | `strEqual_cstr` | high | strlen(param_2) then memcmp vs field+0x10; returns ==0 |
| 451dd0 | `std::map::insert_val_wstr` | high | insert map entry, copy pair + wstring value (_Assign FUN_0040f680) |
| 452650 | `dtor_stringRange_0x18` | high | Destroy std::string range stride 0x18: free SSO-overflow buffers |
| 454190 | `std::list<T>::_Insert_range` | high | Copy-append node range into list; length_error guard |
| 454d60 | `std::_Insertion_sort<0x10>` | high | Insertion sort, 16-byte elements, int key at +4 |
| 454fe0 | `std::_Make_heap<0x10>` | high | Build max-heap over 16-byte elements (int key), _Adjust_heap FUN_00451a60 |
| 455270 | `std::_Med3<0x10>` | high | Median-of-3 for 16-byte elements, int key |
| 455470 | `std::_Guess_median<0x10>` | high | Median-of-medians pivot selection, 16-byte elements |
| 455710 | `std::_Move_backward<0x10>` | high | Move-backward range of 16-byte elements |
| 455940 | `std::_Push_heap<0x10>` | high | Sift-up 16-byte element into heap, int key |
| 456e90 | `std::_Copy<0x10>` | high | Copy-assign 16-byte elements from list-node payloads into array |
| 456fb0 | `moveStringRange_0x18` | high | Move-construct std::string range stride 0x18 (steal buffer or memmove SSO) |
| 457ea0 | `pair_assign_2dword` | high | Assign pair of 2 dwords (param_2, param_3) |
| 459530 | `Struct_reset_with256buf` | high | Zero-init struct incl memset 0x100 buffer at +10, set flags and 0xffffffff sentinels |
| 459800 | `Struct_copy_acBytes` | high | Copy large struct up to offset 0xa8 (mixed dword/word fields) |
| 459a30 | `Struct_reset_off14to46` | high | Zero fields from offset 0x14 through 0x46 |
| 459ab0 | `Struct_copy_skipIdx1` | high | Copy dwords 0,2..0xe (skips index 1) |
| 465c70 | `Struct_reset_0dDwords` | high | Zero ~0xd dwords plus word at +9 |
| 465ed0 | `Struct_init_off3c_3f` | high | Set +0x3c=0.0f and +0x40=3.0f |
| 465fb0 | `Struct_init_off10_scale1` | high | Set +0x10=1.0f and +0x14=1.0f (scale defaults) |
| 466510 | `Struct_init_withFactory78` | high | Zero-init via FUN_00466590 then set +0x78 from FUN_0043c870, zero 0x80-0x9c |
| 466590 | `Struct_reset_1cDwords_flag` | high | Zero ~0x1b dwords and set byte +0x1c=1 |
| 468790 | `Struct_copy_1cDwords_b` | high | Copy ~0x1d dwords (skips index 3 and 0x15) plus byte |
| 4688f0 | `predicate_notFUN_2f4a0` | high | Return logical NOT of FUN_0042f4a0 result |
| 468f20 | `vec2_add` | high | param_1 = param_2 + *this over 2 floats |
| 469020 | `vec3_divScalar` | high | param_1 = *this / param_2 over 3 floats |
| 46d370 | `Container_dtor_at78` | high | Destroy container at +0x78 via FUN_0067eb10 then delete |
| 46ef20 | `array_alloc_stride18` | high | Allocate array of stride 0x18 elements; throws on overflow/oom |
| 46f990 | `listNode_free_ownsString` | high | Reset list head then free node that owns an SSO string at +8 |
| 46fa90 | `ios_setstateFailIfZero` | high | If FUN_0040c4c0 returns 0, set failbit(2) on basic_ios (STL glue) |
| 486830 | `ChunkBuffer_vector_insert_8` | high | Inserts one 8-byte element into a ChunkBuffer vector, copying 8 bytes field-by-field; grows via FUN_0046e8f0 |
| 486ba0 | `WorldInfo_clearUnderLock` | high | Enters critical section at +0x250, destroys several intrusive lists (call vfunc(1)) and buffers, then leaves lock |
| 487f80 | `fixed16_vec_lengthSquared` | high | Computes fixed-point 16.16 squared length of a 2-component 64-bit vector via allmul/alldiv by 0x10000 |
| 4c14f0 | `acosf_wrap` | high | Wrapper returning acos(param_1) as float |
| 4cb080 | `move_range_3` | high | Copies/moves a range of 3-byte elements |
| 4cb490 | `AdaptionWidget_vector_resize_3` | high | Resizes a 3-byte-element vector (AdaptionWidget); grow via reserve+vfunc_6 or shrink+move |
| 4cc7d0 | `int3_notEqual` | high | Compares two 3-int (12-byte) records for inequality (memcmp-like) |
| 4ce460 | `std_use_facet_ctype_char` | high | std::use_facet<ctype<char>>: fetch ctype facet from locale, throws bad_cast if absent |
| 4d6f10 | `utf16_appendCodepoint` | high | Write one Unicode codepoint as UTF-16 (surrogate pair if >=0x10000), return advanced ptr |
| 4d72a0 | `utf8_to_utf16_alloc` | high | Count UTF-16 units for UTF-8 input, allocate, decode UTF-8 to UTF-16 |
| 4d7400 | `utf32le_to_utf16_write` | high | Convert UTF-32LE codepoints to UTF-16 into caller buffer (surrogate expansion) |
| 4d7460 | `utf32be_to_utf16_write` | high | Convert byte-swapped UTF-32BE codepoints to UTF-16 into caller buffer |
| 4d74f0 | `utf8_countCodepoints` | high | Count Unicode codepoints in a UTF-8 buffer (1..4 byte sequences, word-at-a-time ASCII fast path) |
| 4d75f0 | `utf8_to_utf16_write` | high | Decode UTF-8 buffer to UTF-16 into caller buffer (handles 1-4 byte seqs, surrogates) |
| 4d78a0 | `xml_detectEncoding` | high | Detect text encoding from BOM/'<?xml' heuristic, return encoding id (1..6) |
| 4d96f0 | `xml_decodeEntityRef` | high | Decode an '&...;' XML entity reference (named/numeric) to UTF-16 into output |
| 4d9a40 | `QuestText_cloneNode` | high | Clones a QuestText map node (FUN_004da730) and copies its string value; SEH-guarded |
| 4d9c50 | `std_Tree_insert_rebalance` | high | std::map/set red-black tree insert fixup (rotations/recoloring); _Xlength_error on overflow |
| 4d9e50 | `std_Tree_insert_rebalance_v2` | high | std::map/set RB-tree insert fixup for a second value type; _Xlength_error guard |
| 4dc8b0 | `struct_copy3_andCall` | high | Copies 3 dwords from param into this and calls FUN_00468670(param_2) |
| 4e0940 | `QuestText_insertRebalance` | high | QuestText red-black tree insert rebalance (rotations/recolor); cap 0x4924922 |
| 4e4350 | `QuestText::substitute_placeholders` | high | Recursively substitutes dialogue placeholders ($creature/$name/$item/$object/$zone/$stress/$number) via lookup maps |
| 4e7290 | `VoxelModel::load_from_file_or_buffer` | high | Loads .cub voxel model: reads dims from istream (param_2==0) or decompressed buffer, then FUN_004e7650 |
| 4ebb40 | `map::insert_rebalance` | high | Inserts a new node into map/set at given parent then performs red-black insert fixup; 'map/set<T> too long' |
| 587f30 | `Vec3_IntToFloat` | high | Game: converts a 3-component integer vector to a 3-component float vector |
| 58d6c0 | `Vec2_DoubleToInt` | high | Game: converts a 2-element double array to two ints stored at in_ECX |
| 58d710 | `Pair_Copy2` | high | Game: copies a 2-dword pair (param_1[0],param_1[1]) into in_ECX |
| 5945d0 | `Vec3_Add` | high | Game: adds two 3-component integer vectors (param_2 + in_ECX) into param_1 |
| 594600 | `Array_ElementPtr12` | high | Game: computes pointer to the param_2-th element of a stride-0xc array (*in_ECX base) |
| 594660 | `Vec2_Less` | high | Game: lexicographic less-than comparison of two 2-field (y,x) points |
| 594690 | `Vec2_LessEqual` | high | Game: lexicographic less-or-equal comparison of two 2-field (y,x) points |
| 598930 | `VoxelChunk::cellAt` | high | Returns pointer to voxel cell at (x,y,z) in chunk grid (12-byte cells) after clamping/bounds check |
| 59c480 | `World::enterCriticalSection` | high | Enters the world/global critical section at in_ECX+0x8000d8 |
| 59f070 | `Terrain::getBlockPacked` | high | Fetches block at param_2 via 0058e7d0 and copies its 4-byte + 1-byte fields into param_1 |
| 59ff50 | `getField14` | high | Trivial getter returning the dword at in_ECX+0x14 |
| 5a5a10 | `Structure::getWidthByRotation` | high | Return dimension at +0x68 or +0x64 selected by rotation-parity bit0 of flags (+4) |
| 5a5a30 | `Structure::getHeightByRotation` | high | Return dimension at +0x64 or +0x68 (opposite selection of 5a5a10) by rotation-parity bit of flags (+4) |
| 5a5a50 | `getField_0x6c` | high | Trivial getter: return dword at in_ECX+0x6c |
| 5a5b10 | `vec2_lengthSquared` | high | Return squared magnitude x*x+y*y of a 2D double vector at in_ECX |
| 5a5b40 | `transformCoordsByRotation` | high | Transform (x,y) in place by rotation code (flags+4 &3, cases 1-3: swap/mirror) plus flip flag (+8), using dims +0x64/+0x68 |
| 5a6a00 | `moveConstruct9Field` | high | Move-construct: zero dest, steal 3-ptr buffer from source (nulling src[0..2]), copy remaining fields src[3..8] |
| 5a6c30 | `allocNodeMovePayload` | high | Allocate RB-tree node (FUN_005a7b90), init color(+0xc)=0, move-construct payload via FUN_005a6a00 |
| 5a78a0 | `lexicographicalLess` | high | Lexicographic less-than of two int ranges [p1,p2) vs [p3,p4); returns 1 if first<second (vector<int> key compare) |
| 5a7a40 | `initStruct6Fields` | high | Initialize 6-field struct: three scalar params into in_ECX[0..2], vec3 from param_4[0..2] into in_ECX[3..5] |
| 5a9d40 | `AStar::octileHeuristic` | high | Octile/weighted-Manhattan distance heuristic from 3 abs deltas using 10/4/10 weights *2 |
| 5adde0 | `vec4_floatToInt` | high | Truncates 4 floats to ints, reading source at (param_1 - in_ECX) offset into dest in_ECX |
| 5ae000 | `fixedPointToInt_xy` | high | Divides two pairs of 16.16 fixed-point coords by 0x10000 (__alldiv) to ints, writes to in_ECX[0],[1] |
| 5aea50 | `setVec4` | high | Trivial: writes 4 dwords (param_1..4) into in_ECX[0..3] |
| 5aec90 | `structConstruct7Dword` | high | Copies 6 dwords from param_1 then appends param_2 as 7th dword into in_ECX |
| 5c38a0 | `set4` | high | Stores 4 args into in_ECX[0..3]; 16-byte struct/vec4 field setter |
| 5c3950 | `copyctor_obj0x140` | high | Copy-constructor for 0x140-byte object: copies field[0], sub-object via FUN_0040ee70, ints [0x47..0x4f] |
| 5c39e0 | `ctor_obj0x140` | high | Default-constructs 0x140-byte object: zeroes header, memset(+6,0,0x100), sets [0x47]/[0x48]=-1 |
| 5c3a90 | `ctor_zero6i` | high | Default ctor zeroing 24-byte (6-int) struct |
| 5c3b70 | `ctor_from_two_vec3` | high | Constructs 24-byte struct from two 3-int vectors (param_1->[0..2], param_2->[3..5]) |
| 5c3bb0 | `Region_ctor` | high | Region constructor: zero-inits ~0x60-byte struct, sets flag [9]=1 |
| 5c3c70 | `dtor_free_two_buffers` | high | Destructor freeing two heap buffers via operator_delete (in_ECX[3] then in_ECX[0]); container teardown |
| 5c3de0 | `map3i_at` | high | map<vec3i,T> operator[]: cache-check node vs 3D key at [0x10/0x14/0x18], else insert node |
| 5c3e80 | `array24_at` | high | Element accessor: returns base + index*0x18 into array of 24-byte elements |
| 5c3ef0 | `uint128_sub` | high | 128-bit subtraction with borrow of two 4-word operands (param_1 -= param_2) |
| 5c46f0 | `voxelVolume_at` | high | 3D voxel-volume accessor: transforms coord (FUN_005fa3c0), bounds-checks dims at +0xc/+0x10/+0x14, returns 2-byte cell ptr |
| 5c4770 | `clampRGB` | high | Clamps a vec3/RGB color (param_2) into [0,255] and writes to param_1 |
| 5c8310 | `getTemperatureAt` | high | Returns temperature at coord: cache lookup FUN_004347a0 (field+4) else compute via FUN_005c4800 |
| 5c8350 | `getHumidityAt` | high | Returns humidity at coord: cache lookup FUN_004347a0 (field+8) else compute via FUN_005c4dd0 |
| 5cb550 | `World_fillVoxelBox` | high | Triple nested loop filling a param_4-sized box of voxels with value 0x46 via FUN_0044e7a0 |
| 5f7400 | `dtor_geometryBuffer` | high | Destructor: clears geometry vector (FUN_0063dc90) and frees storage (operator_delete) |
| 5f7820 | `dtor_listBuffer` | high | Destructor: clears list (FUN_0066add0) and frees (operator_delete) |
| 5fa3c0 | `swap_two_int_ptrs` | high | Copies/swaps two int fields between param_1 and param_2 |
| 5fa440 | `copy_two_int_ptrs` | high | Copies two int fields from param_2 to param_1 |
| 601ea0 | `leave_critical_section_b` | high | Leaves a critical section (external:00000019); shared unlock wrapper |
| 6089c0 | `copy_two_words` | high | Copies two 16-bit fields from param_2 to param_1, returns param_1 |
| 608d40 | `vec3_copy` | high | Copies a 3-field record from param_2/param_3 into param_1 |
| 630a40 | `tree_nodeAlloc` | high | Allocates a tree/list node via operator_new (external:90) |
| 630b60 | `tree_destroyRecursive` | high | Recursively destroys tree nodes (self-call + operator_delete); std::_Tree teardown |
| 6326a0 | `Node::is_ancestor_chain` | high | Walk parent chain via +0x28 checking if a given node appears; returns 1 if found |
| 636810 | `AdaptionWidget::apply_to_attributes` | high | Invoke FUN_00664c10 on each populated attribute slot (+0x34/38/3c) then recurse children |
| 6368e0 | `Node::set_font_slot` | high | Set attribute/font slot at +0x3c: release old (refcount==1 -> FUN_00650460) and retain new |
| 636b70 | `Node::set_style_slot` | high | Set attribute slot at +0x38: release old (refcount==1 -> FUN_00650890) and retain new |
| 636c40 | `Node::clear_layout_flag_2d` | high | Recursively clear layout flags (+0x2d on slots, +0x134 on adaption) when node dirty bit set |
| 636ef0 | `Node::set_adaption_slot` | high | Set/clear adaption slot +0x40: if param!=0 assign (FUN_0062de20) else null it |
| 636f10 | `AdaptionWidget::apply_attributes_v2` | high | Invoke FUN_00664cc0 on populated attribute slots then recurse active children |
| 64aec0 | `WorldInfo::move_string` | high | Move-construct one std::string (SSO-aware) from param_1 into this+4, resetting source |
| 64af30 | `NamedValue::move_two_strings` | high | Move-construct two std::strings (name+value pair) from param_1, resetting sources |
| 64b000 | `NamedValue::move_construct_pair` | high | Move-construct pair of std::strings from two separate source strings |
| 64bec0 | `NamedValue::assign_pair_free` | high | Move-assign string pair (64b000+64af30) freeing temporaries (SEH cookie) |
| 64cd70 | `istream::read_u32` | high | Read one 4-byte little-endian value from istream (returns via ECX) |
| 64dd90 | `NamedValue::dtor_free_strings` | high | Destructor: free the two std::string buffers (name+value) if heap-allocated |
| 64de80 | `Node::dtor_free_vectors` | high | Destructor tail: free vector at +0x64 and destroy+free container at +0x58 |
| 64e790 | `Widget::set_flag_bit8_0x128` | high | Set or clear bit3 (0x8) of flags dword at +0x128 |
| 64e7b0 | `Widget::set_flag_bit4_0x128` | high | Set or clear bit2 (0x4) of flags dword at +0x128 |
| 64e7d0 | `Registry::push_node_locked_0x8c` | high | Under CS, append a new list node to list at +0x8c and return payload |
| 64eb60 | `Registry::push_node_locked_0x08` | high | Under CS, append list node to list at +8 |
| 64ebd0 | `Registry::push_node_locked_0x74` | high | Under CS, append list node to list at +0x74 |
| 64ecc0 | `Registry::push_node_locked_0x84` | high | Under CS, append list node to list at +0x84 |
| 64f080 | `Button::new_instance` | high | Factory: operator_new(0x238) + plasma::Button::ctor_1 |
| 64f180 | `DiscreteAttributeInt::new_instance` | high | Factory: operator_new(0x210) + plasma::DiscreteAttribute<int>::ctor_0 |
| 64f200 | `Edit::new_instance` | high | Factory: operator_new(0x17c) + plasma::Edit::ctor_0 |
| 64f280 | `GenericShape::new_instance` | high | Factory: operator_new(0x8c) + plasma::GenericShape::ctor_0 |
| 64f300 | `ListWidget::new_instance` | high | Factory: operator_new(0x160) + plasma::ListWidget::ctor_0 |
| 6500d0 | `PopUpButton::new_instance` | high | Factory: operator_new(0x240) + plasma::PopUpButton::ctor_0 |
| 650160 | `ScrollButton::new_instance` | high | Factory: operator_new(0x24c) + plasma::ScrollButton::ctor_0 |
| 6501e0 | `ScrollSlider::new_instance` | high | Factory: operator_new(0x254) + plasma::ScrollSlider::ctor_0 |
| 650360 | `ContinuousAttributeVec3::new_instance` | high | Factory: operator_new(0x234) + plasma::ContinuousAttribute<Vector<3,float>>::ctor_1 |
| 650460 | `FontNode::unregister_and_release` | high | Under CS, unlink font node from registry list at +0x8c and release (vtbl[0]) |
| 650890 | `StyleNode::unregister_and_release` | high | Under CS, unlink node from registry list at +0x84 and release |
| 6509f0 | `Widget::pop_render_layer` | high | End current render/draw layer: call vtbl 0x68, save top sub-widget, decrement frame index |
| 650a20 | `istream::read_chunk_header` | high | Read 4-byte size then tellg; compute chunk end position (128-bit pos) returned via param_1 |
| 650e0b | `__ehepilogue_restore_cookie` | high | Exception unwind epilogue: restore ExceptionList and run stack cookie check |
| 661260 | `Image::setPixelData` | high | Stores width/height, copies pixel-format descriptor, allocates 3-or-4 bytes-per-pixel buffer and memcpys source image data |
| 662690 | `Spline::setTimeAndEvaluate` | high | Stores the absolute time then evaluates the spline at that time |
| 6626b0 | `Spline::resetTime` | high | Resets the spline's current time to zero |
| 663150 | `vector::destroyStringRange` | high | Destroys a range of string elements (0x18 stride), releasing each element's buffer |
| 664bf0 | `list::sumFieldAcrossNodes` | high | Walks a std::list summing an integer field (payload+8) across all nodes |
| 664cc0 | `Widget::resetAnimations` | high | Clears the dirty flag and iterates the controller list resetting each animation's time to zero |
| 67bd00 | `Widget::setByteField380` | high | Stores a byte parameter into the object field at offset 0x380 |
| 67bd40 | `thunk_vector_int_assign` | high | Thin wrapper that forwards to the vector<int> assign/copy routine FUN_0067a7b0 |
| 681220 | `istream::readValue` | high | Reads sizeof-value bytes from the object's istream (at +8) into a stack temporary and returns it |
| 681240 | `istream::readFloat` | high | Reads a float from the object's istream (at +8) and returns it |
| 68d946 | `__ftol2` | high | Statically-linked MSVC CRT/STL function identified by signature match (flirt-crc, crc:swap~;len=0x75). Mangled: __ftol2. |
| 402e80 | `vectorString_popBack` | med | Destroys and pops last std::string element of a vector (dtor + shrink end by 0xc) |
| 4034c0 | `vectorString_copyElem` | med | Copy-constructs a std::string element into slot after reserving (FUN_0064e310) |
| 4040d0 | `std_container_assign_range` | med | MSVC STL: vector/string assign from [param_1,param_1[1]) via memmove/grow |
| 405cc0 | `filebuf_endWrite` | med | std::basic_filebuf flush: codecvt::unshift then fwrite remaining bytes to FILE* |
| 40d910 | `vectorPOD_insertAt` | med | std::vector insert of one 0xc-byte element at position, growing (FUN_0063ddc0) if at capacity |
| 40da70 | `dispatch_callbackChain` | med | Walks a jump/offset table invoking registered code* handlers, accumulating return offsets |
| 40f570 | `getTargetEntity` | med | Returns current target/interactable entity ptr after type checks (types 3-9) and a flag guard |
| 42c460 | `vec3i64::setFromGen` | med | Sets three consecutive int64 fields to 64-bit value from 0068d946 (init 3D fixed-point coord vector) |
| 42c6e0 | `vec6::copyAndScale` | med | Copies 6 dwords to out then scales in place via 0042c900 (fixed-point vec3 scale) |
| 42c720 | `arena::allocSlot0x11c` | med | Returns current arena pointer to param_1 and advances arena by 0x11c (bump-alloc item slot) |
| 42c890 | `int64::ltGen` | med | Returns ECX_int64 < value from 0068d946 (signed 64-bit compare) |
| 42ef10 | `GameController::clearContainers` | med | Resets three intrusive containers (trees at +0x140c/+0x1414, list at +0x1460) then FUN_0067e480 |
| 42f5a0 | `int64::subGen` | med | Writes ECX_int64 minus value from 0068d946 into param_1 (int64) |
| 42f7e0 | `world::getColumnData` | med | Resolves chunk via 004347a0 then column at height param_3; returns voxel/column ptr or fallback |
| 42f860 | `world::getColumnAtFixedPos` | med | Floors three 16.16 fixed coords via __alldiv then calls getColumnData 0042f7e0 |
| 439110 | `math::round_to_tenth` | med | round float to one decimal, recursive for negatives (game util) |
| 439fc0 | `std::wstring::erase_iter` | med | erase from iterator: compute offset then erase 1 |
| 43acb0 | `int64::gtFixed16` | med | Compares ECX int64 vs (param_1<<16); returns bool low byte |
| 43b640 | `listHead::initWithNode` | med | Zeroes 2 dwords then allocates head node via 0043c8e0 (init empty intrusive list) |
| 43bc00 | `Spawn::initNameArrays` | med | Zero-inits Spawn struct with ~14 repeated 0x100 memset blocks + string-slot headers (NPC name/attr arrays) |
| 43c020 | `struct::initWithBuf` | med | Zero-inits struct: fields + memset 0x100 buffer at +9 (SSO string member init) |
| 43c100 | `Creature::init` | med | Zero-inits large Creature struct with float defaults (0x43fa0000,0x42c80000,1.0 scales); calls 0043bc00 sub-init |
| 43c9c0 | `item::materialCategory` | med | Maps material/type id to category code (6/7/8) or -1 default via switch |
| 43dc60 | `stat::calcWeaponDamage` | med | Computes weapon damage: base 2^ terms, iterate element list or flag bonuses, ×multiplier by weapon type |
| 43e5a0 | `ability::isUsable` | med | Checks ability usable: cooldown, resource cost (00444ae0), and target lookup (0043f720); returns bool |
| 43f7c0 | `creature::generateAppearance` | med | Generates NPC/creature appearance (color, model, size) from seed/type param_3 via rand and big per-race switch |
| 443f40 | `drop::getCountRange1` | med | Outputs (min,max) count for ability/drop id via switch (defaults 1,1) |
| 444020 | `drop::getValueRange` | med | Outputs (min,max) value/price range per item type id via large switch |
| 4441a0 | `combat::rollHitChance` | med | Rolls rand vs param_1 probability, scaled down by weapon rune type (+0xaa8/+0xaa9) |
| 444270 | `combat::getStaminaCost` | med | Returns stamina/energy cost per weapon type via switch, scaled by attack speed |
| 4444a0 | `combat::rollElementProc` | med | Iterates buff list (+0x1178) for element '\v'; rolls rand vs computed proc chance 0043ea40 |
| 4445d0 | `creature::isBossType` | med | Returns 1 if creature type +0x64 in boss/special id set |
| 444680 | `ability::isChanneled` | med | Returns 1 if creature type +0x64 in large channeled-ability id set and flags +0x7e clear |
| 444db0 | `stat::calcAttackDamage` | med | Computes attack/physical damage: base 2^ terms, weapon-state multipliers, per-slot element bonuses |
| 444ff0 | `combat::getComboWindow` | med | Returns combo/timing window (0x5dc, reduced by rage +0x1a8 if in special form) |
| 4452a0 | `combat::selectAttackVariant` | med | Returns attack variant id from weapon rune/form and hand flag (+0x141) |
| 445410 | `combat::advanceAttackTimer` | med | Advances attack timer by per-weapon cost; on threshold selects next anim 00445020 and resets |
| 446bb0 | `projectile::getMuzzlePosition` | med | Computes projectile spawn world pos: rotate offset by yaw (cos/sin), add random jitter, add entity pos int64 |
| 447310 | `combat::getReloadFrames` | med | Returns reload/recovery frames per weapon type (switch), scaled by attack speed |
| 447d10 | `render::bindNodeTransformA` | med | D3D9/GL render glue: uploads 3 uniforms via device vtable (0x15c,0x170,0x1ac) from node fields |
| 448f10 | `render::uploadBoneMatrices` | med | Uploads 10-float array then transposed bone/skinning matrix to shader constants (vtable 0x178) |
| 449400 | `handle::freeMember4` | med | Frees resource at +4 via 00520620 (sqlite/handle finalize) and nulls it |
| 4497b0 | `db::openBlobStore` | med | Opens SQLite db (00525590), creates 'blobs(key TEXT PRIMARY KEY, value BLOB)' table |
| 449ba0 | `WorldInfo_allocMapNodeCopyKey` | med | Allocs RB-tree node via 0044b7b0, zeroes color, copies 6 dwords of key from param_1+0x20 to node+0x30 |
| 44b460 | `WorldInfo_mapInsertUnique` | med | WorldInfo: find (0044b880) then insert region/world entry keyed by int+string into map (00449fe0) |
| 44cdb0 | `deserializeRegionChunk` | med | Deserializes region stream: reads counts, 0x118 structs into vec, 0x14/0x148 records; validates ids |
| 44e700 | `sparseArray_setAt` | med | Set element at signed index into growable 4-byte array (0040c50), grows via 00450c50 |
| 450960 | `GameController_getHoveredTilePtr` | med | Returns pointer to hovered/targeted map tile if type byte==0x0e, else null; indexes region grid |
| 450c50 | `sparseArray_resize` | med | Reallocate/resize the 4-byte-element sparse index array to param_1, copying/offsetting entries |
| 4517d0 | `string_assign` | med | Assign string: build via 0046f170 then free temp (0040eaf0) |
| 451a60 | `heap::sift_down_16` | med | binary-heap sift-down over 0x10-byte elements (game) |
| 452260 | `node_ctor_2strings` | med | Construct node via 00630a40, then copy two strings (0040eaf0) at param+0 and +0x18 |
| 457e20 | `string_assignSwapTmp` | med | Assign string via temp local (0040c0a0 + 0064aec0) then free overflow |
| 468cf0 | `ftol64_ofFloat` | med | Convert (float)*this to int64 via FUN_0068d946 |
| 468e20 | `vec3_negateSwapYZ` | med | Copy vec3, negate x/y/z and swap y/z channels |
| 46d1f0 | `less_stringKey_map` | med | RB-tree comparator: node string key < param_1 key via FUN_00428db0 |
| 46dcb0 | `identity/getter thunk` | med | Trivial function returning its argument unchanged (identity/accessor thunk) |
| 46e250 | `std::vector<T16>::_Reallocate` | med | Reallocate 16-byte-element vector to new capacity, move+free |
| 46f450 | `GameController::acquire_render_locks` | med | EnterCriticalSection on three engine critical sections |
| 46fac0 | `findNearestEntityDistSq` | med | Iterate players tree, compute min squared distance to entities of type 5, cap 25 |
| 477280 | `GameController::release_render_locks` | med | LeaveCriticalSection on three engine critical sections |
| 4777f0 | `Zone_rbtree_eraseRange` | med | Erase RB-tree node range [param_2,param_3); clear whole tree if full range; class Zone |
| 47f030 | `hasNearbyAllyEntity` | med | Iterate players tree; true if same-faction entity within range^2=16, else scan all |
| 4c69b0 | `GameState_addOrUpdateHitEntry` | med | Adds or updates an 8-byte (id3+val) hit/damage record at +0x14; capacity 0x10 or 0x20 by type |
| 4c6a90 | `item_computeBlockValue` | med | Computes a scaled item/block stat (float) gated by item type 4-7 and subtype at +0xd |
| 4c6ba0 | `item_computeStat_regen` | med | Computes a per-item stat (float) for weapon/tool types using FUN_00445ff0 and level/rng modifiers |
| 4c79b0 | `GameState_removeHitEntry` | med | Removes an 8-byte hit/damage record matching key3, compacting the array; SEH cookie |
| 4c7a90 | `item_computeStat_ranged` | med | Returns stat*1.5 for type-1 subtype 4/6 items else 0 |
| 4c7af0 | `item_computeStat_variant2` | med | Per-item float stat for types 4-7 with subtype (+0xd) multipliers |
| 4c7e80 | `item_rerollStackCount` | med | Rerolls item stack/durability count within a level-derived range using rand(); updates +0x10 |
| 4cb5d0 | `net::Connection::write_delta_i8` | med | If byte field changed, push to change-list and set dirty bitflag (game net) |
| 4cb670 | `net::Connection::write_delta_i16` | med | If short field changed, queue delta and set dirty bit (game net) |
| 4cb710 | `net::Connection::write_delta_i32` | med | If int field changed, queue delta and set dirty bit (game net) |
| 4cb7b0 | `net::Connection::write_delta_f32` | med | If float field changed, queue delta and set dirty bit (game net) |
| 4cb850 | `net::Connection::write_delta_vec5f` | med | If 5-float(0x14) field changed, queue delta+dirty bit (game net) |
| 4cb930 | `net::Connection::write_delta_struct_ac` | med | If 0xac struct changed (cmp FUN_004cc840), queue delta (game net) |
| 4cb9d0 | `net::Connection::write_delta_struct_e38` | med | If 0xe38 struct changed (cmp FUN_004ccaa0), queue delta (game net) |
| 4cba70 | `net::Connection::write_delta_creature` | med | If 0x118 Creature struct changed, queue delta (game net) |
| 4cbb10 | `net::Connection::write_delta_vec3i` | med | If 12-byte(3-int) field changed, queue delta+dirty bit (game net) |
| 4cbbc0 | `net::Connection::write_delta_vec3f` | med | If 12-byte(3-float) field changed, queue delta+dirty (game net) |
| 4cbc80 | `net::Connection::write_delta_vec6i` | med | If 24-byte(6-int) field changed, queue delta+dirty (game net) |
| 4cbd40 | `net::Connection::write_delta_i64` | med | If 8-byte(2-int) field changed, queue delta+dirty bit (game net) |
| 4cc800 | `std_compare_float3_ne` | med | Return 1 if any of 3 consecutive floats differ between two arrays (vec3 inequality helper) |
| 4cc840 | `EntityAppearance_compareEqual` | med | Field-by-field equality compare of two ~0xA4-byte entity appearance/equipment structs |
| 4ccaa0 | `compareEqual_array13` | med | Equality compare of array of 13 elements (0x118 stride) via element comparator FUN_0042f4a0 |
| 4ccc30 | `std_list_push_serializeField_string` | med | Append serialized std::string field node (0x10) to output chunk list if changed |
| 4cccf0 | `std_list_push_serializeField_0x2C` | med | Append serialized 0x2C-byte field node to output chunk list if changed vs baseline |
| 4ce2a0 | `std__operator>>_istream_string` | med | std::operator>>(basic_istream&, basic_string&): extract whitespace-delimited token |
| 4d6c20 | `xml_malloc_thunk` | med | Allocation thunk: tail-jump to CRT malloc for parser buffers |
| 4d6c40 | `utf32le_to_utf16_alloc` | med | Count UTF-16 units for a UTF-32LE buffer, allocate output, convert (surrogate expansion) |
| 4d6cb0 | `utf32be_to_utf16_alloc` | med | Count/alloc/convert a byte-swapped UTF-32BE buffer to UTF-16 |
| 4d6d90 | `xml_memoryPool_allocateBlock` | med | Allocate block from pool arena (>0x2000 gets own arena), link into free/used list |
| 4d6e20 | `xml_node_allocate` | med | Allocate and zero a 0x20-byte XML node from pool, tag pointer with type bits |
| 4d6ea0 | `xml_memoryPool_allocateArena` | med | Allocate a new pool arena (size+0x38), 0x20-align, link into arena chain |
| 4d6f60 | `xml_attribute_allocate` | med | Allocate a 0x14-byte XML attribute node from pool and link into element's attribute list |
| 4d6fe0 | `xml_node_appendChild` | med | Allocate child node and append to parent element's child list |
| 4d7190 | `xml_transcode_dispatch` | med | Dispatch input decode by encoding id (1=UTF8,2/3=UTF16,5/6=UTF32) to proper converter |
| 4d7240 | `utf16_byteswapCopy` | med | Copy UTF-16 buffer swapping byte order of each unit (endianness normalize) |
| 4d73a0 | `utf16_countUnits_fromUtf32be` | med | Count UTF-16 code units needed to represent a UTF-32BE buffer |
| 4d79f0 | `utf16_copy_passthrough` | med | UTF-16 input passthrough: reference in-place or memcpy to owned buffer, set length |
| 4d7a60 | `xml_selectAttrValueScanner` | med | Select attribute-value scanner function by encoding/flags bits (jump table of 8) |
| 4d7ce0 | `xml_parseText_entityAndNewlineNorm` | med | Scan text run decoding entities and normalizing CRLF/CR to LF |
| 4d7e70 | `xml_parseNodeTree` | med | Core recursive XML parser: elements, attributes, PIs, comments, CDATA into node tree |
| 4d8510 | `xml_skipElement` | med | Recursively skip an element and its nested markup to matching '>' |
| 4d85c0 | `xml_skipCDATA` | med | Skip a CDATA/marked section '<![...]]>' (recursive nesting) |
| 4d8630 | `xml_skipQuotedOrPIComment` | med | Skip a quoted string, processing instruction '<?..?>' or comment '<!--..-->' |
| 4d8900 | `xml_parseBang_commentCData_doctype` | med | Parse '<!' construct: comment, CDATA[..], or DOCTYPE (optionally into node) |
| 4d8c70 | `xml_parsePI_or_xmlDecl` | med | Parse '<?' processing instruction / xml declaration, optionally build PI node |
| 4d9ae0 | `std_Tree_buynode` | med | Allocate+init a red-black tree node (via FUN_004da730), set color, construct value |
| 4da1a0 | `std_map_insert_unique_v2` | med | std::map insert-unique (second value type) using wide-string comparator |
| 4da2f0 | `std_Tree_destroy_subtree` | med | Post-order traverse+destroy a red-black tree subtree, releasing each node |
| 4dc820 | `GameController_snapshotEntityLists` | med | Snapshots two dwords + two lists from an entity into this struct (copies list via FUN_004dc470) |
| 4e2df0 | `World::map_find_or_insert_int` | med | RB-tree lower_bound by int key *param_1; if absent builds 7-cap string value and inserts new node |
| 4e2f00 | `map::insert_string_key` | med | Finds string key via FUN_004e3790; if not present constructs QuestText node and inserts into map |
| 4e5590 | `GameController::format_region_singular` | med | Builds localized region name string ('singular') from region record fields (+0x18..+0x20) |
| 4e6c00 | `vec3_divide_scalar` | med | Divides an int[3] vector (in_ECX) by scalar param_2 into param_1 |
| 4eba80 | `map::alloc_node_swap` | med | Allocates a map node (FUN_006819e0), zeroes key, moves in string/data payload from param_1 |
| 4ebd50 | `map::insert_with_hint` | med | Inserts value into map using hint iterator param_2, choosing correct position then rebalance |
| 4ebf80 | `map::insert_unique` | med | Locates insert point via lower_bound and inserts unique key, reporting whether inserted |
| 4ec1b0 | `string::assign_cstr` | med | Computes C-string length then assigns it into std::string via FUN_0040c280 |
| 4ec1f0 | `map::subscript_int` | med | map<int,T>::operator[]: finds node for key; if absent allocates+inserts new default node |
| 58e9f0 | `Struct_InitScaleDefaults` | med | Game: initializes a struct's scale field to (1,1,1) floats and mode field to 2 |
| 58eaa0 | `Struct_InitDefaults` | med | Game: initializes a struct's default fields (flag=1, several zeros, -1 handles) |
| 595a60 | `CombatBehavior::applyMeleeHit` | med | Large melee-hit resolver: applies damage/knockback/velocity to target creature, updates threat and hit-cooldowns |
| 5989d0 | `Terrain::sampleHeightAtWorldXY` | med | Converts fixed-point world X/Y (>>0xb) to chunk, and if chunk type==1 returns interpolated height via 005fa4c0 |
| 59a800 | `CombatBehavior::spawnHitParticles` | med | For each active body-part (byte>0x7f, stride 8) emits a particle/blood entry into a std::list at param_6 |
| 59aba0 | `Terrain::fillCuboid` | med | Paints a param_4[0..2]-sized voxel box via 0044e7a0, randomly extending faces at region edges |
| 59c890 | `Terrain::paintDisk` | med | Fills a 2D circular disk (radius param_4) of voxels at fixed z=param_3 with color param_5, optional blend |
| 59cbf0 | `Terrain::paintSphere` | med | Fills a 3D sphere (radius param_4) of voxels centered at param_1/2/3 with color, optional distance blend |
| 59ee90 | `Entity::stepToward` | med | Normalizes the vector between two 16.16 positions and, if within range param_4, advances via 005a35d0 |
| 59fc90 | `Terrain::sampleHeightNoise` | med | Samples layered Perlin/value noise (004c0ef0) at scaled world X/Z, writing two 16.16-scaled height doubles |
| 59fea0 | `Terrain::sampleBlockBrightness` | med | Looks up block at 16.16 world coords and returns its normalized light/opacity (byte/255) |
| 5a58e0 | `Entity::onStateChangeEmitEffect` | med | If bool state (+0xc byte) differs from param_3: reset timer +0xd, pick effect id (0x33-0x36) by type *param_1, append event to list at param_2 |
| 5a5bc0 | `terrainNoiseDensityAt` | med | Perlin-noise (FUN_004c0ef0) sampled at world pos scaled 0.008 + origin (+0x8001f4/f8), *1.2 clamped 0..1, plus secondary noise |
| 5a6270 | `randomizeVec3` | med | Fill float[3] with RNG-derived (FUN_0068d946) values through trig FUN_004c0ef0: [0],[1]=2*f, [2]=f+0.5; random direction/offset |
| 5a7a70 | `PathNodeMap::insertOrUpdate` | med | Insert/update coord-keyed node in A* RB-tree (open/closed set) with exception cleanup; compares via FUN_005a78a0 |
| 5a7b90 | `PathNode::allocFromKey` | med | operator_new(0x34) node; std::_Xbad_alloc on fail; inits first 3 dwords from key *in_ECX; RB-tree node allocator |
| 5a7c90 | `Pathfinding::reconstructPath` | med | Walks parent-chain building std::list<coord> of path steps; _Xlength_error("list<T> too long"); uses FUN_005a9da0 lookups |
| 5a9ca0 | `PathMap::probeClosedSet` | med | Builds temp 3-int coord key, lower_bound in closed-set map at +0x1414, compares via FUN_005a78a0 |
| 5a9e50 | `AStar::pushOpenNode` | med | Inserts coord node into open map (via FUN_005a7a70), copies 6-dword cost payload from param_4, updates best-front at +0x1408 |
| 5bf5b0 | `spawnRandomObject7` | med | Initializes game object at param_1 from param_2 template, then rand()%7 picks type (0x18/0x19/0x1a/0x1b/0x12/0x10/0x1c) and scale |
| 5bfd70 | `spawnRandomObject4` | med | Like 5bf5b0: inits object from template, rand()%4 picks type 0x18/0x19/0x1a/0x1b with random scale |
| 5bff10 | `spawnRandomObject3` | med | Inits object from template, sets type rand()%3+0x15 with fixed scale (6.0/2.0/3.0) |
| 5c0150 | `copyByteTripleToInts` | med | Expands 3 consecutive bytes at param_1 into 3 uints stored in in_ECX (byte->int unpack, e.g. RGB/xyz) |
| 5c4520 | `terrain_biomeColorFromNoise` | med | Computes clamped RGB terrain/biome color from two Perlin-noise (FUN_004c0ef0) layers using world seeds |
| 5c52a0 | `dungeon_splitRegion_recursive` | med | BSP-style region/room subdivision: picks split line (rand-jittered), recurses placing corridors/doors via FUN_005ef6d0 |
| 5c56e0 | `terrain_surfaceColor_blend` | med | Builds terrain surface RGBA by layering base/grass/snow/sand/water noise colors by height+moisture params |
| 5c5e20 | `terrain_generateColumnColor` | med | Multi-octave terrain color/height generation from noise (FUN_004c0ef0) + POI distance weighting |
| 5c7140 | `terrain_rockColor_blend` | med | Computes rock/cliff RGB from noise octaves then blends with humidity (FUN_005c4dd0) and moisture layers |
| 5c7730 | `creature_initBehaviorByType` | med | Initializes creature/entity combat behavior and ability set via big switch on type byte at +0x30; adds abilities (FUN_0066add0) |
| 5c8390 | `loot_generateItemTable` | med | Generates loot/item table across tiers: per-slot rand rarity rolls (1/100,1/1000,1/10000), memset 0x100 buffer, emits items |
| 5c9b30 | `World_generateMonsterSpawnList` | med | Loops 30 region levels, uses rand()+noise to build creature/spawn descriptor entries via FUN_0046ebe0 |
| 5c9f90 | `World_applyDropTableToEntities` | med | Iterates entity array (stride 0x11c) setting field0=1 and generating item drop via FUN_005f8750/FUN_00639cf0 |
| 5ca0a0 | `World_generateNpcSpawnList` | med | SEH-guarded spawn-table builder: rand-weighted level scaling, appends spawn descriptors via FUN_0040ee70 |
| 5cade0 | `World_findNearestObjectAtLevel` | med | Scans a 0x400-wide region cell grid (base+0x100000) for object minimizing squared distance to noise-offset point |
| 5cb0d0 | `World_findNearestObjectRegion2` | med | Region grid nearest-object search variant over base+0x400000 minimizing squared distance |
| 5cb3b0 | `World_computeStructurePlacement` | med | Calls FUN_005ee0f0 to get placement, writes 16.16 fixed-point position/bounds matrix into param_7 struct |
| 5cb600 | `World_carveTerrainFeatureA` | med | Large voxel terrain sculpt: noise (FUN_004c0ef0) driven ellipsoid carve using chunk/block lookups |
| 5cbe00 | `World_carveTerrainFeatureB` | med | Second voxel terrain sculpt variant (radius 20, block-type masks) painting a feature into the world |
| 5cc510 | `World_populateRegionDecorations` | med | Large decoration builder: constructs prop meshes/entities and stamps them via many gen helpers |
| 5d6040 | `World_buildStructureMesh` | med | Builds a structure/prop object (operator_new + ctors + FUN_005c7730) appended to a list |
| 5d7f60 | `World_generateFoliageBlob` | med | Draws a noise-perturbed ellipsoid of colored voxels (tree crown/rock) with color blend clamped 0..255 |
| 5d8750 | `World_generateVegetationCluster` | med | Generates a cluster of vegetation/props: noise placement, mesh build (FUN_00583cb0 vector), FUN_00668950 |
| 5d9460 | `World_generateTreeRecursive` | med | Recursive tree/branch generator (self via FUN_005d6040) with __alldiv subdivision and operator_new nodes |
| 5d9ad0 | `World_generateTreeRoot` | med | Top-level tree/structure generator driving FUN_005d8750/FUN_005d9460 with region nearest lookups |
| 5dc6e0 | `World_buildPropInstance` | med | Constructs a prop/entity instance (operator_new + FUN_00594b40 + ctors) and registers it |
| 5df600 | `World_fillVoxelColumnTyped` | med | Fills voxel cells (FUN_0044e7a0) across a param_4 range using per-cell type from param_5 byte array |
| 5df960 | `World_generateWaterOrPathFeature` | med | Large feature generator using distance (__alldiv/FUN_005f9e50) and voxel fill (FUN_005d7f60) |
| 5ee0f0 | `World_resolveStructureFootprint` | med | Computes structure footprint bounds; returns 0 on fail, writes min/max extents to param_6/param_7 |
| 5ee540 | `World_getColumnDataAt` | med | Returns pointer to per-column/cell float data at (param_2,param_3) |
| 5ee7a0 | `World_appendMeshBatch` | med | Appends a mesh/geometry batch (operator_new + FUN_00583cb0 vector grow + ctors, FUN_0043c980) |
| 5eea60 | `World_findNearestObject` | med | Wrapper computing region offset then calling grid nearest-object search FUN_005cade0 |
| 5ef040 | `World_getRegionCellPtr` | med | Returns/derives a region cell pointer or noise value for (param_1,param_2); widely shared helper |
| 5ef5a0 | `vec3_dot_or_distance` | med | Computes a scalar (dot/distance) from three double* vectors, returns float10 |
| 5ef6d0 | `World_copyCellRecord` | med | Copies/assigns a cell record from param_2 to param_1 via FUN_005c46f0 |
| 5efdb0 | `noise2d_sample` | med | Returns a noise/height sample (float10) for integer coords via FUN_005c4800 |
| 5effa0 | `World_placeObjectWithSpacing` | med | Places an object at (param_1,param_2) enforcing spacing via sqrt distance checks against neighbors |
| 5f4c30 | `World_getOrCreateEntry` | med | Retrieves or creates an entry (FUN_005c43d0 + FUN_005a7990) |
| 5f4da0 | `World_scaleFixedByLevel` | med | Scales a fixed-point value by level using __alldiv and rng (FUN_0068d946) |
| 5f6d50 | `World_emitDecalOrParticle` | med | Emits a decal/particle: memset buffer then build via FUN_005f51e0/FUN_005f8ad0 |
| 5f6e20 | `World_serializeCellData` | med | Reads/writes cell data (FUN_00639cf0, FUN_0058ea10) with vector cleanup (external:12e) |
| 5f7a60 | `World_buildParticleBatch` | med | Builds a particle/decal batch: memset + FUN_004c7830/FUN_0040ee70 + emit via FUN_005f6d50 |
| 5f8750 | `Item_generateStats` | med | Generates item stats/attributes using pow (libm_pow) scaling; called by drop-table apply |
| 5f9620 | `vec3_store4` | med | Stores/returns a vec3+scalar record into param_1 from indices |
| 5f9bc0 | `vec3_computeNoiseOffset` | med | Computes a noise-based vec3 offset into param_1 (FUN_004c0ef0) |
| 5f9e50 | `vec2_store` | med | Stores/returns a vec2 record into param_1 |
| 5fa170 | `vec3_store4_b` | med | Stores/returns a vec3+scalar into param_1 (sibling of FUN_005f9620) |
| 5fa4c0 | `GameController_entityDistanceSq` | med | Returns squared distance to an entity via FUN_005f8e10 (vfunc_10) |
| 5fa9e0 | `octree_recursiveTraverse` | med | Recursive spatial partition traversal dispatching to leaf/split helpers |
| 605950 | `vec3_lerp` | med | Interpolates/writes a vec3 into param_1 from param_2 by factor param_4 |
| 608c80 | `tree_cloneRecursive` | med | Recursively clones a tree, allocating nodes via FUN_00608a60 |
| 608f60 | `tree_build` | med | Builds a tree/map (FUN_00608b30 insert + FUN_0046d590 alloc), returns node |
| 609480 | `vec_normalize_or_distance` | med | Computes normalized/distance vector (sqrt, __alldiv, FUN_0059f0a0); called by vfunc_0 |
| 60ab30 | `direction_from_angle` | med | Computes a direction/velocity vector from angle using cos/sin/__alldiv |
| 6290d0 | `tree_eraseRecursive` | med | Recursively erases/frees tree nodes (self-call, FUN_004860b0) |
| 629140 | `tree_clear` | med | Clears a tree/map: releases root (FUN_0046d550) and recursive erase (FUN_006290d0) |
| 6291d0 | `Widget_measure` | med | Measures widget bounds via FUN_0062de60 (cookie-guarded) |
| 6294d0 | `Widget_computeBoundsFloat` | med | Computes/applies float bounds via FUN_0062d7f0 |
| 62a650 | `Widget_setScroll` | med | Sets widget scroll/position via FUN_006295a0 |
| 62de60 | `AdaptionWidget_getBoundsRect` | med | Returns pointer to widget bounds rect (float* to x,y,...); heavily shared |
| 62f600 | `Widget_measureGuarded` | med | Cookie-guarded measure via FUN_0062de60; widely shared vfunc target |
| 62f8f0 | `tree_cloneSubtree` | med | Recursively clones a subtree (self-call, FUN_0062f750 node alloc) |
| 6326d0 | `Node::clone_subtree` | med | Recursively deep-copy a scene/widget node incl attribute slots and child list, rebuilding std::map at +0xe8 |
| 633c90 | `Node::get_first_child_id` | med | Wrapper: fetch a value from node via FUN_00630ae0 then read pair into out param |
| 633dd0 | `Node::collect_matching_children` | med | Recursively append name-matching child nodes into a std::list (guards 'list<T> too long') |
| 634a70 | `Node::transform_pair_to_screen` | med | Transform two 2D points through node matrix, compute min/max screen rect (calls FUN_00634dd0) |
| 635fe0 | `Node::detach_or_remove_child` | med | If child==0 release node else find child in list and detach its transform (FUN_00635760) |
| 636040 | `Node::clone_subtree_v2` | med | Recursive deep clone of node subtree (variant of 6326d0) rebuilding attribute map at +0xe8 |
| 636190 | `Node::frustum_visibility_test` | med | Transform node AABB by matrices and test against viewport extents (+0x10c/+0x110); frustum cull |
| 637120 | `Node::detach_all_slots_recursive` | med | Recursively detach shape/style/font slots (refcount>1) and descend non-hidden children |
| 639800 | `FontCache::find_or_create_scalable` | med | Under CS, split path, find/create plasma::ScalableFont in RB-tree at +0x10 keyed by filename |
| 639b30 | `AdaptionWidget::draw_text_locked` | med | Under CS, begin/end render state (vtbl 0x40/0x44) and draw text run via FUN_0065bc70 |
| 641180 | `StaticMeshShape::build_from_buffers` | med | Release old GPU buffers (vfunc_6) and construct plasma::StaticMeshShape from vertex/index/normal buffers |
| 64bf40 | `Attribute::deserialize_int_keyframes` | med | Read tagged chunks from istream into an int/index attribute; opcode1=keyframe,2=default,3=nested |
| 64c150 | `Attribute::deserialize_keyframes_v2` | med | istream chunk-reader variant loading attribute keyframes (default ctor FUN_0042bea0) |
| 64c360 | `Attribute::deserialize_keyframes_v3` | med | istream chunk-reader variant loading attribute keyframes (default ctor FUN_0042bf80) |
| 64c570 | `Attribute::deserialize_matrix_keyframes` | med | Read tagged keyframe chunks (0x40-byte/matrix values) from istream into attribute array |
| 64c710 | `Attribute::deserialize_double_keyframes` | med | Read tagged keyframe chunks (8-byte values) from istream into attribute array |
| 64c8a0 | `Attribute::deserialize_vec3_keyframes` | med | Read tagged keyframe chunks (0xc-byte vec3) from istream into attribute array |
| 64ca40 | `Attribute::deserialize_vec4_keyframes` | med | Read tagged keyframe chunks (0x10-byte vec4/color) from istream into attribute array |
| 64cbe0 | `Attribute::deserialize_scalar_keyframes` | med | Read tagged keyframe chunks (4-byte values) from istream into attribute array |
| 64eff0 | `Widget::fit_content_and_set` | med | Compute widget content bbox (FUN_00634dd0) and forward it to current sub-widget (vtbl 0x20) |
| 64f400 | `NamedObject::find_or_create` | med | Find NamedObject by name in RB-tree at +0xac; else operator_new(0x34)+ctor_2 and register |
| 650810 | `Node::unregister_notify_release` | med | Under CS, unlink node from list at +0x9c, notify (FUN_0067eb10) and release |
| 654000 | `Button::deserialize` | med | Deserialize plasma::Button from istream chunk stream (opcode 0xf=action id) |
| 654700 | `Edit::deserialize` | med | Deserialize plasma::Edit widget from istream chunk stream |
| 654900 | `GenericShape::deserialize` | med | Deserialize plasma::GenericShape (name + two mesh refs at +0x17/+0x19) from istream |
| 654df0 | `ListWidget::deserialize` | med | Deserialize plasma::ListWidget from istream chunk stream |
| 65a890 | `Pair::constructMoveKeyString` | med | Copies 2-dword key from param_2, builds string(FUN_005a7990) into out, then fills param_1[2..4] from string temp. |
| 65b8f0 | `GameController::clearAllEntities` | med | Destructor-style teardown under CS: frees FreeType-ish subsystems (+0xd8,+0xdc), walks both entity maps freeing nodes and buffers. |
| 65bc70 | `Font::drawTextTransformed` | med | Renders a text string with matrix transform under CS: gets/pushes model matrix (vtbl+0x38/0x3c), scales, calls layout FUN_0065c040. |
| 65d530 | `Font::measureTextLine` | med | Measures glyph run producing min/max bounds (param_2/param_3): per-char glyph metrics, alignment (param_4 flags), stop at newline param_5. |
| 65ded0 | `Font::measureTextBlock` | med | Measures multi-line text extent with kerning (FUN_0068fb90) and alignment; produces width/height in param_3/param_4. |
| 65e720 | `Font::measureTextScaled` | med | Wrapper: enters CS, computes scale from char cell, optionally builds a substring, calls measure FUN_0065d530, scales result bounds. |
| 65f260 | `Font::loadByFileExtension` | med | Extracts and uppercases a filename extension, compares to known suffixes, dispatches to file vs memory font/glyph loader |
| 65fb80 | `Font::loadFaceFromFile` | med | Under critical section loads a font face by file path, fills family/style name strings and computes glyph metric ratios (FreeType-style) |
| 65fef0 | `Font::loadFaceFromMemory` | med | Same as loadFaceFromFile but loads face from an in-memory buffer (param_3=data, param_4=size) then populates name strings and metrics |
| 6619a0 | `Container::resetAndInsert` | med | Clears the object (via 6621e0) then allocates and inserts one new 16-byte tree node returning its payload |
| 6626d0 | `Spline::advanceTime` | med | Advances spline time by a delta and evaluates, guarding against an empty keyframe vector |
| 662fc0 | `vector::moveConstructBackward` | med | Backward move-helper over 0x18-stride elements, clearing/releasing string members as it walks source and dest ranges |
| 663000 | `vector::moveAssignStringRange` | med | Move-assigns a range of string elements (6-dword/0x18 stride) into a destination, stealing buffers and clearing sources |
| 6630a0 | `vector::fillDefaultStrings` | med | Constructs param_2 default (empty) string elements at 0x18 stride with exception unwinding |
| 663ee0 | `vector::erase` | med | Erases a range from a vector by move-collapsing the tail then destroying the leftover elements, updating end pointer |
| 664cf0 | `Container::updateChildren` | med | Iterates child linked-list (offset 9), calls per-child update, fires virtual callback if any changed; returns aggregate flag |
| 671450 | `AdaptionWidget::buildMeshIndices` | med | Assigns indices to adaption mesh cells via concurrent_vector segments, resizes output vectors, walks RB-tree to mark faces |
| 671750 | `AdaptionWidget::buildTopology` | med | Builds edge/face topology arrays from concurrent_vector cells: resizes and links neighbor pointers across segments |
| 67bcc0 | `Widget::setFieldAndClamp388` | med | Stores param_1 at +0x38c and clamps the int field at +0x388 into [0,1000] |
| 67bd10 | `Widget::setClampedField388` | med | Clamps param_1 to [0,100] and stores it at object offset 0x388 |
| 67fde0 | `ArrayAttribute::readInts` | med | Deserializes an ArrayAttribute from istream: reads size/frame/sequence tags, reading a 4-byte value into each vector[0x13..0x14] element |
| 6800d0 | `ArrayAttribute::readVariant2` | med | Deserializes an ArrayAttribute from istream (size/frame/sequence) applying 4-byte reads via FUN_0042bea0 per element |
| 6803c0 | `ArrayAttribute::readVariant3` | med | Deserializes an ArrayAttribute from istream (size/frame/sequence) applying 4-byte reads via FUN_0042bf80 per element |
| 6806b0 | `Attribute::readScalar` | med | Deserializes an Attribute from istream reading a 4-byte value per frame into vector[0x13]+idx*4, dispatching sequence sub-attribute |
| 6808f0 | `Attribute::readMatrix64` | med | Deserializes an Attribute reading 0x40-byte (16-float/matrix) records into vector[0x13], stride 0x40 per frame |
| 680b40 | `Attribute::readVec8` | med | Deserializes an Attribute reading 8-byte records into vector[0x13]+idx*8 per frame |
| 680d80 | `Attribute::readVec3` | med | Deserializes an Attribute reading 0xc-byte (vec3) records into vector[0x13], stride 0xc per frame |
| 680fd0 | `Attribute::readVec4` | med | Deserializes an Attribute reading 0x10-byte (vec4/quat) records into vector[0x13], stride 0x10 per frame |
| 682a80 | `Attribute::readSequence` | med | Deserializes an animation "Attribute.sequence": reads name/wname and per-key frame/time/smoothness, inserting sorted keyframes |
| 402ed0 | `signal_dispatchArg` | low | Builds a 1-element arg vector and dispatches a registered callback/handler, then cleans up |
| 40d010 | `filebuf_openInstantiate` | low | Opens filebuf (basic_filebuf::ctor_3) and constructs an abstr::Method0<Machine,int>, returns success byte |
| 411340 | `proximityCheck` | low | Game logic: gets target entity then compares its height/distance thresholds via FUN_00627ce0/d50 |
| 42be00 | `resizeChildBuffers_type8` | low | Loops (m[0x50]-m[0x4c])/4 times calling vector-resize helper 0042bea0(count) over child buffers; SEH-free wrapper |
| 4396d0 | `textBuffer::eraseSelection` | low | Clamps scroll (0043a4a0) then erases text range via 00411270 and adjusts scroll offsets |
| 43cf20 | `combat::updateBombFuse` | low | If bomb equipped/armed, advances fuse timer (+0x170) and spawns projectile via 00446af0/004460a0 |
| 43e310 | `creature::isSpecialForm` | low | Tests creature form byte +0x60 and subtype +0x64 against set; returns bool |
| 444520 | `creature::hasFireAffinity` | low | Returns 1 if in fire/element state (+0x140,+0x64,+0xaa9 checks) |
| 444610 | `creature::hasWaterAffinity` | low | Returns 1 if water/element state active (+0x140==3 or type 0x75/0x56 or rune 0xa-0xc) |
| 445f10 | `stat::diminishing_returns_pct` | low | compute diminishing-returns percentage from field 400 (game) |
| 447e10 | `Input::init_keybindings` | low | create D3D input params and register default key actions (game) |
| 449420 | `obj::init_and_load_a` | low | init object then load stream (game wrapper over decode) |
| 44a7c0 | `clearTwoFields` | low | Zeroes fields at ecx+0xc and ecx+0x10 |
| 450ab0 | `GameController_isNearTargetTile` | low | If tile 00450960 valid, checks its distance within camera near-thresholds |
| 459b10 | `T::T(const T&)` | low | Copy-ctor invoking 13 std::string copies (array of 13 strings, stride 0x118) |
| 466050 | `T::T(const T&)` | low | Copy-ctor of large game struct (~0x458 dwords) with embedded strings/arrays (Entity-like) |
| 4758c0 | `drawBillboardModelRotated` | low | Draw sprite/voxel model billboarded with Euler rotation param_3 and mode param_5 char |
| 476660 | `drawModelAtProjectedPos` | low | Project screen pos to world and render model param_5 with orientation and perspective scale |
| 4778b0 | `Zone_rbtree_eraseNode` | low | Red-black tree single-node erase with rebalance/recolor then free 2 strings and delete |
| 4c78c0 | `Item::compute_value` | low | Compute item gold value from type/rarity/level (game) |
| 4ce3f9 | `std__operator>>_istream_string_unwind` | low | Exception-unwind continuation of istream>>string (resets gcount, setstate, releases sentry) |
| 4d94e0 | `xml_appendDecodedChar` | low | Append one decoded character to entity-decode output buffer |
| 4d9520 | `xml_scanCDATA_withEntities` | low | Scan CDATA-style value applying entity decode (helper for '<!' parser) |
| 4d9600 | `xml_scanComment_withEntities` | low | Scan comment-style value applying entity decode (helper) |
| 4e31e0 | `map_string_operation` | low | Map/string operation with stack buffer and __security_check_cookie |
| 583cb0 | `IntMap_SetScalar` | low | Game/STL: inserts a key via map helper (FUN_0046d550) and stores a scalar value at node+8 |
| 58d8b0 | `MapNode_CreateXY` | low | Game/STL: allocates a map node (FUN_00594720), stores a 2-dword key and initializes payload |
| 58d930 | `MapNode_CreateB` | low | Game/STL: allocates a map node and copies two dword fields (+0x18,+0x1c) from param_1 |
| 58ea10 | `Entity_CopyState` | low | Game: copies an entity/behavior sub-struct's fields (matrix, id, +0x170..0x184) via helper copies |
| 593e80 | `Member_Destroy` | low | Game: destroys a member object at +0x48 (runs FUN_00639cf0 cleanup then operator_delete) |
| 594620 | `Float_FromRef` | low | Game: reads a value referenced by in_ECX, converts to float via FUN_0068d946, returns boxed result |
| 596d30 | `CombatBehavior::spawnProjectileHit` | low | Large routine that spawns weapon/spell hit effects & projectiles based on item type +0x68, with RNG spread |
| 59a9b0 | `Terrain::blockTypeAtTime` | low | Fixed-point world lookup combining game time (0068d946) with X/Y; returns chunk field +0x24 if within radius |
| 59aeb0 | `Terrain::spawnFallingBlock` | low | Spawns a falling-block/debris entity: random lifetime, raycasts terrain column downward to rest position |
| 59b180 | `Creature::spawnDeathEffects` | low | On creature death spawns loot/gibs/coins and status particles switched on creature type +100 |
| 5a7b50 | `AStar::coordExceedsBound` | low | Returns 1 if 64-bit value from FUN_0068d946 is below the (in_ECX[1]:in_ECX[0]) pair; a 64-bit coord/cost bound check |
| 5a9f90 | `Creature::expandNeighbors` | low | A* neighbor expansion: octile heuristic, converts pos via __alldiv/65536, world-chunk lookup FUN_00434d10, tests entity bboxes for collision |
| 5aaab0 | `Creature::runPathfindingLoop` | low | Main A* loop: pop lowest-cost open node (min at +0x1414 map, FUN_005a9d40 heuristic), collision-test world blocks, push neighbors |
| 5ad320 | `Region::scatterProps` | low | Scans 3x3 fixed-point grid around pos, tile-tests via FUN_005f4da0, randomly spawns typed props/plants (ids 0x10/0xc/0x45/0x42) via rand |
| 5af170 | `Chunk::generateObjects` | low | Very large routine (0x6884 stack) populating a world chunk: random object/prop creation and vector pushes; introsort helpers |
| 5bf7c0 | `spawnRandomObjectPositioned` | low | Creates a randomized object with type/scale switch and randomized world position offsets via FUN_0068d946; SEH-guarded |
| 5c0120 | `packWorldCoord64` | low | Packs three coordinate/count values into a 64-bit result via <<16 and <<8 shifts with carry propagation |
| 5c3820 | `copy2_helper` | low | Small assign helper: dst[0]=src2[0], dst[1]=*src3 (2-byte fields); likely swap/move fixup for sort |
| 5c3840 | `copy3_helper` | low | Small assign helper writing 3 bytes: dst[1]=src2[1], dst[0]=src2[0], dst[2]=*src3 |
| 5c3860 | `init_call_46d4b0` | low | Zeroes 2 ints then stores result of FUN_0046d4b0 into slot[0]; small object initializer |
| 5c3880 | `init_call_65ae80` | low | Zeroes 2 ints then stores result of FUN_0065ae80 into slot[0]; small object initializer |
| 5eea40 | `get_bool_flag` | low | Returns a single-byte flag/constant; trivial getter |
| 5f0c80 | `get_zero_or_stub` | low | Trivial void routine (getter/no-op stub) |
| 5f9e10 | `get_const_dword_a` | low | Returns a constant/config dword; trivial getter |
| 5f9e30 | `get_const_dword_b` | low | Returns a constant/config dword; trivial getter |
| 5fa500 | `octree_leafOp` | low | Leaf operation in a recursive spatial-tree traversal (part of FUN_005fa9e0 cluster) |
| 5fa5b0 | `octree_nodeVisitA` | low | Node visitor in recursive spatial-tree traversal |
| 5fa650 | `octree_nodeVisitB` | low | Node visitor (2-arg) in recursive spatial-tree traversal |
| 5fa750 | `octree_nodeSplit` | low | Splits/subdivides a spatial-tree node (3-ptr) |
| 5faad0 | `octree_applyLeaf` | low | Applies leaf op via FUN_005fa500 during traversal |
| 5fab40 | `octree_applySplit` | low | Applies node split via FUN_005fa750 during traversal |
| 608ba0 | `tree_insertRecursive` | low | Recursively inserts into a tree via FUN_00608c80 |
| 608e80 | `tree_insertEntry` | low | Inserts entry via FUN_00608ba0 with FUN_0043c870 pre-step |
| 608f40 | `forward_to_678520` | low | Thin forwarder to FUN_00678520 |
| 608ff0 | `tree_populate` | low | Populates a tree via FUN_00608e80 + FUN_00468790 |
| 6091b0 | `setter_stub` | low | Sets a field from param_1 (trivial) |
| 6091d0 | `get_rng_dword` | low | Returns a value derived from rng (FUN_0068d946) |
| 609280 | `compute_index_pair` | low | Computes index/value pair into param_2 from param_1 (no callees) |
| 60aa00 | `build_and_link` | low | Builds/links data via FUN_00608d40 + FUN_0067eb10 + FUN_00609280 |
| 60aa60 | `get_byte_flag` | low | Returns a byte flag (trivial getter) |
| 624790 | `codec_bitreaderInit` | low | Initializes/advances a codec bit reader (FUN_004018f0); audio decode helper |
| 6247f0 | `codec_readBits` | low | Reads bits/values from codec stream (FUN_004013a0/00401450/00401480) |
| 624c70 | `codec_decodeFloor` | low | Decodes a floor/spectral stage (float ops ext:137/138/142, FUN_006d0xxx math) |
| 625130 | `codec_decodePacketRecursive` | low | Recursively decodes an audio packet stage (self-call, __alldiv, dispatch to sub-decoders) |
| 6255d0 | `codec_setupHelperA` | low | Codec setup helper (FUN_006d1220/006d19d0 math tables) |
| 625640 | `codec_setupHelperB` | low | Codec setup helper (FUN_006d12e0/006d1920 math tables) |
| 625670 | `codec_synthesizeWindow` | low | Synthesis/windowing stage of audio decode (FUN_006d0bb0/006d0610, FUN_00624c70) |
| 625b70 | `codec_recursiveSum` | low | Recursive accumulation over codec structure (self-call); returns longlong |
| 625c00 | `codec_decodeMapping` | low | Decodes a mapping/channel-coupling stage (FUN_00625640, FUN_00625b70) |
| 6260c0 | `codec_decodeSetup` | low | Decodes codec setup/header block (FUN_00624900, FUN_00625c00, FUN_0068d946) |
| 626ab0 | `codec_windowOverlapAdd` | low | Overlap-add / PCM window into short* output (FUN_006d0b20/00625670) |
| 626e10 | `codec_decodeInit` | low | Initializes packet decode (FUN_00625c00/00624a70/00625130/00624f80) |
| 626f90 | `codec_setupHeaders` | low | Sets up codec headers (memcpy/memset, FUN_00624c70, FUN_00625a60) |
| 627120 | `codec_decodeStreamEntry` | low | Drives stream decode (FUN_00626e10 init + FUN_00626f90 headers + FUN_00625a60) |
| 62b400 | `AdaptionWidget_onContentResized` | low | Notifies/handles content resize (no callees); shared vfunc target |
| 62bb20 | `Widget_layoutChildrenGuarded` | low | Cookie-guarded child layout (FUN_0062bb90 + FUN_006295a0) |
| 62ddc0 | `Widget_updateCaption` | low | Updates caption via FUN_0062b920 + FUN_0040f680 |
| 62de20 | `get_widget_field` | low | Returns a widget field (no callees) |
| 62f2d0 | `Widget_applyBoundsAndRefresh` | low | Applies bounds (FUN_0062d7f0) and refreshes via FUN_006504c0 |
| 62f750 | `tree_allocNode` | low | Allocates a tree node via FUN_00630a40 + FUN_0040c0a0 |
| 62f820 | `tree_findOrInsert` | low | Finds/inserts a node (FUN_0040c0a0, FUN_00439600); returns node |
| 6302f0 | `tree_insertPair` | low | Inserts a key/value pair (FUN_0062f820, FUN_00633ce0, external:91) |
| 632910 | `Widget::render_subtree` | low | Recursive widget/scene render pass: builds transforms, scales, invokes vtbl draw/culling on children (huge, type-unsettled) |
| 633e70 | `Node::project_bounds_recursive` | low | Recursively transform/project child AABBs through matrices producing screen-space min/max (deadcode-restarted) |
| 634dd0 | `Node::compute_screen_aabb_recursive` | low | Recursively compute node subtree bounding rect in screen space via matrix transforms (type-unsettled) |
| 635760 | `Node::attach_transform_multiply` | low | Multiply node's local matrix by mesh (+0x1b0) and parent (+0x48) 4x4 matrices, store to +0x48/+0x88; list-append |
| 6372a0 | `AdaptionWidget::full_layout_pass` | low | Full recursive adaption/layout pass: resolve values, run child layout (6374d0), fit bounds, set dirty (big) |
| 6374d0 | `AdaptionWidget::layout_pass_child` | low | Recursive child layout variant of 6372a0: resolve +0x44, apply attributes, fit-to-children bounds |
| 63fec0 | `SmoothMeshShape::rebuild_buffers` | low | Rebuild triangle/edge adjacency and vertex/index buffers from mesh sub-arrays; uses maps & vectors (huge) |
| 64edb0 | `Widget::ensure_frame_subwidget` | low | Grow per-frame sub-widget vector at +0xe, lazily create widgets via vtbl 0x34, and forward-position them |
| 650b00 | `FontCache::load_font_by_name` | low | Find/load a Plasma or Pixel font by name+size+flags via RB-tree at +0xa4, RTTI-checked, else load from file (big) |
| 654240 | `SmoothMeshShape::deserialize` | low | Deserialize plasma::SmoothMeshShape mesh data (name, vertex arrays, attributes) from istream (big switch) |
| 654ff0 | `PopUpButton::deserialize` | low | Deserialize plasma::PopUpButton with nested menu-item widgets from istream (big) |
| 6570c0 | `FontCache::create_font_from_path` | low | Create a PixelFont from file path (or fallback lookup), applying default glyph atlas (SEH, big) |
| 661df0 | `Anim::playTrackByName` | low | Finds a named track then walks its keyframe vector (0xc stride) invoking a per-frame callback and a vtable finalize |
| 661f80 | `Anim::removeTrackReferences` | low | Removes a track: decrements frame indices in every other track's vector above the removed index and rebuilds the index list |
| 6621e0 | `Anim::removeEntryByKey` | low | Finds a named entry, erases its map subrange, then iterates its vector calling removeTrackReferences before freeing the vector |
| 662300 | `Spline::evaluateAtTime` | low | Evaluates a cubic-Bezier keyframe spline at a time value, handling 0/1/n control points, looping and callback dispatch |
| 6637a0 | `vector::insertN` | low | Inserts param_3 copies of an element into a vector<T> (T=0x18 struct with string), reallocating/growing with the three-case MSVC insert |
| 664c10 | `Widget::triggerTracksByName` | low | Frees a temp key string, iterates a list of tracks and for each matching name plays its keyframes, marking a dirty flag |

## GameController (558)

| addr | proposed name | conf | purpose |
|---|---|---|---|
| 403350 | `string_assignCStr` | high | std::string::assign(const char*): strlen then assign bytes via FUN_0040c280 |
| 4033b0 | `string_defaultInit` | high | std::string default construct: SSO empty (cap=0xf,len=0,null) |
| 403eb0 | `string_dtor` | high | std::string destructor: frees heap buffer if cap>0xf, resets to empty SSO |
| 4043f0 | `filebuf_dtor` | high | std::basic_filebuf<char> destructor: base dtor, sets vtable, ios_base dtor |
| 405060 | `string_move` | high | MSVC std::string _Move helper: transfers buffer/len/cap to in_ECX, clears source |
| 4054f0 | `string_grow` | high | std::string _Grow/reallocate: computes new capacity (1.5x), allocs, copies, frees old |
| 407d50 | `string_resize` | high | std::string::resize/_Grow(bool): grows or truncates, returns len!=0 |
| 40c0a0 | `string_assignSubstr` | high | std::string assign(str,pos,len): validates pos, copies substring, self-assign fast path |
| 40c1c0 | `string_assignFill` | high | std::string assign(count,char): grows and fills or sets single char |
| 40c4c0 | `filebuf_close` | high | std::basic_filebuf::close: flushes (405cc0), fclose, re-inits streambuf, returns this-or-null |
| 40c520 | `string_compare` | high | std::string::compare(pos,len,ptr,ptrlen): bounded memcmp, returns <0/0/>0 |
| 40cb00 | `string_erase` | high | std::string::erase(pos,count): memmove tail and shrink, or truncate |
| 40cba0 | `fabs_f` | high | Returns absolute value of float param_1 |
| 40e420 | `cosf_f` | high | Returns cosf(param_1) via libm_sse2_cos_precise |
| 40e6f0 | `wostream_insertWide` | high | operator<<(wostream, const wchar_t*): writes wide string with field-width padding via sputn/sputc |
| 40ea50 | `setPair_b` | high | Stores 2 dwords into object (assign vec2/pair) |
| 40ea70 | `setColor3b` | high | Stores 3 bytes into object (RGB color set) |
| 40ea90 | `setVec3` | high | Stores 3 dwords into object (assign vec3) |
| 40eac0 | `setVec4` | high | Stores 4 dwords into object (assign vec4/quaternion) |
| 40ef50 | `arrayElem0x11c` | high | Returns &array[param_1] with stride 0x11c (indexes 0x11c-sized structs) |
| 40f0d0 | `repeatCall` | high | Invokes code* param_4 exactly param_3+1 times |
| 40f8a0 | `std::char_traits<wchar_t>::assign` | high | copy single wchar element |
| 40f8e0 | `getField_0x3c` | high | Returns dword at object offset 0x3c |
| 411320 | `getField_0x34` | high | Returns dword at object offset 0x34 |
| 411400 | `getField_0x148` | high | Returns dword at object offset 0x148 |
| 411ab0 | `count_0x11c` | high | Returns element count of a 0x11c-stride vector: (end-begin)/0x11c |
| 411c70 | `getField_0x38` | high | Returns dword at object offset 0x38 |
| 411cf0 | `getField_0x40` | high | Returns dword at object offset 0x40 |
| 411d40 | `array_lerp` | high | Interpolates array: param_1[i] += (param_2[i]-param_1[i])*param_4 for param_3 elements (unrolled) |
| 411df0 | `vec2_copy` | high | Copies 2 dwords from param_1 into object (vec2 copy) |
| 411e30 | `vec3_copy` | high | Copies 3 dwords from param_1 into object (vec3 copy) |
| 412080 | `int_toFixed16` | high | Sign-extends param_1<<16 into 64-bit value at object (int to 16.16 fixed-point) |
| 4120a0 | `addInt` | high | Returns param_1 + object dword |
| 4120b0 | `arrayElem_stride8` | high | Returns base + param_1*8 (8-byte-stride element ptr) |
| 4120c0 | `vectorU32_at` | high | Bounds-checked std::vector<u32> element read, returns 0 if out of range |
| 4120f0 | `fixed16ToFloat` | high | Converts 16.16 fixed-point (int64) at object to float (*1/65536) |
| 412120 | `vec4_mulComponent` | high | Component-wise multiply: param_1 = param_2 * this (vec4) |
| 412170 | `vec4_scale` | high | Scales this vec4 by scalar param_2 into param_1 |
| 4121c0 | `vec3_sub` | high | param_1 = this - param_2 (vec3 subtract) |
| 412200 | `int64_sub` | high | 64-bit subtract: param_1 = this(u64) - param_2(u64) |
| 412220 | `int64_subFn` | high | 64-bit subtract of FUN_0068d946() result from this(u64) |
| 412260 | `int64_negate` | high | 64-bit negate of this into param_1 |
| 412280 | `vec3_add` | high | param_1 = param_2 + this (vec3 add) |
| 4122c0 | `int64_add` | high | 64-bit add: param_1 = param_2(u64) + this(u64), with carry |
| 4122e0 | `int64_addFn` | high | 64-bit add of FUN_0068d946() result to this(u64) |
| 412350 | `vec3_dot` | high | Returns 3D dot product of this and param_1 |
| 412390 | `vec3_cross` | high | param_1 = this x param_2 (vec3 cross product) |
| 412400 | `mat4_mulLeft` | high | 4x4 matrix multiply in place: this = param_1 * this (column ops) |
| 412780 | `vec3_scaleInPlace` | high | Scales this vec3 in place by scalar param_1 |
| 4127c0 | `vec4_mulInPlace` | high | Component-wise multiplies this vec4 in place by param_1 |
| 412850 | `vec3_addInPlace` | high | Adds param_1 to this vec3 in place |
| 412890 | `vec3_subInPlace` | high | Subtracts param_1 from this vec3 in place |
| 4128d0 | `mat_elemPtr` | high | Returns element ptr: base + (param_1 + param_2*4)*4 (matrix cell address) |
| 423f20 | `vec3_length` | high | Returns sqrt(x^2+y^2+z^2) (3D vector length) |
| 4240f0 | `vec3_normalize` | high | Normalizes this vec3 in place (divide by length) |
| 424170 | `mat4_rotateAxisAngle_v` | high | Wrapper: rotates matrix by axis vec3 (param_2) and angle via FUN_004241b0 |
| 4241b0 | `mat4_rotateAxisAngle` | high | Builds Rodrigues rotation matrix from angle(param_1) and axis(param_2..4), multiplies into this |
| 4243d0 | `mat4_rotateX` | high | Rotates this 4x4 matrix about X axis by param_1 degrees |
| 4244f0 | `mat4_rotateY` | high | Rotates this 4x4 matrix about Y axis by param_1 degrees |
| 424610 | `mat4_rotateZ` | high | Rotates this 4x4 matrix about Z axis by param_1 degrees |
| 424730 | `mat4_scaleAxes` | high | Scales matrix rows by param_1/param_2/param_3 (skips 1.0 axes) |
| 424810 | `getField_0x44` | high | Returns dword at object offset 0x44 |
| 424820 | `getField_0x48` | high | Returns dword at object offset 0x48 |
| 424830 | `vec2_lengthSq` | high | Returns squared length of this vec2 |
| 424860 | `vec3_lengthSq` | high | Returns squared length of this vec3 |
| 4248a0 | `mat4_transformPoint` | high | Transforms point param_2 by this 4x4 matrix with perspective divide into param_1 |
| 424990 | `mat4_translateVec` | high | Translates this matrix by vec3 param_1 (accumulate into last column) |
| 424a60 | `mat4_translate` | high | Translates this matrix by (param_1,param_2,param_3) |
| 424b50 | `sinf_f` | high | Returns sinf(param_1) via libm_sse2_sin_precise |
| 424b70 | `sqrtf_f` | high | Returns sqrtf(param_1) via libm_sse2_sqrt_precise |
| 4252f0 | `vec3_scaleOut` | high | param_1 = this * scalar param_2 (vec3) |
| 427870 | `vec3_normalizeOut` | high | Normalizes this vec3 into output param_1 |
| 427910 | `mat4_perspective` | high | Builds perspective projection matrix from fov(param_1),aspect(param_2),near(param_3),far(param_4) |
| 4279e0 | `getField_0x110` | high | Returns dword at object offset 0x110 |
| 4279f0 | `getField_0x10c` | high | Returns dword at object offset 0x10c |
| 4288b0 | `storeVec2At` | high | Stores vec2 param_1 into 8-byte-stride array at index +0x20, returns element end ptr |
| 4288e0 | `storeVec4At` | high | Stores vec4 param_1 into 16-byte-stride array at index +0x20, returns element ptr |
| 428920 | `copy3bytes` | high | Copies 3 bytes from param_1 into object |
| 428940 | `color3_differs` | high | Returns 1 if first 3 bytes at object differ from bytes at param_1 (color inequality) |
| 428970 | `arrayElem_stride4` | high | Returns base + param_1*4 (dword-stride element ptr) |
| 428980 | `arrayElem_stride16` | high | Returns *in_ECX + param_1*0x10 (16-byte-stride element ptr) |
| 4289e0 | `vec4_addInPlace` | high | Adds param_1 to this vec4 in place |
| 428d80 | `loadFirstElem_0x2c` | high | Reads *(*(+0x2c)) into param_1 (first element of a list/vector member) |
| 428da0 | `getField_0x2c` | high | Returns ptr/dword at object offset 0x2c into param_1 |
| 42b800 | `memberPtr_0xc` | high | Returns object base + 0xc (address of member at offset 0xc) |
| 42c500 | `vec3::set` | high | Sets three dwords ECX[0..2] from params (assign 3-component vector) |
| 42c6d0 | `getFirstDword` | high | Returns *ECX (first member/pointer) |
| 42c980 | `vec3i64::add` | high | Adds param_1 (three int64) into ECX in place (carry chains) |
| 42c9b0 | `int64::add` | high | Adds single int64 param_1 into ECX in place |
| 42c9d0 | `vec3i64::sub` | high | Subtracts param_1 (three int64) from ECX in place (borrow chains) |
| 42ca00 | `int64::sub` | high | Subtracts single int64 param_1 from ECX in place |
| 42f030 | `map::getRoot` | high | Writes *(ECX+4) (tree head/end) to *param_1 |
| 42f100 | `int64::toIntFloor` | high | Converts single 16.16 fixed int64 to int with floor (/0x10000, adjust negative) |
| 42f140 | `counter::decrementClamp` | high | Decrements *ECX; if <1 clamps to 0 and clears short at ECX+4 |
| 42f160 | `flags::setOrClear114` | high | Sets (param_2!=0) or clears bits param_1 in ushort at ECX+0x114 |
| 42f430 | `buffer::freeAt0x11c` | high | operator_delete of heap buffer at ECX+0x11c (destructor fragment) |
| 42f470 | `color::copy4` | high | Copies 4 bytes param_1->ECX (RGBA/color or 4-byte field copy) |
| 42f640 | `getTileCell32` | high | World coords->tile: validates <0x1fffff, resolves chunk via 00434d10, returns ptr into 32x32 grid at +0xac (8-byte) |
| 4347a0 | `world::getChunkCell256` | high | World coords->256-grid cell: validates <0x1000000 >>8, resolves chunk 00434d10, returns ptr at +0xa8 (32-byte) |
| 4348b0 | `getDword0x10` | high | Returns *(ECX+0x10) |
| 434a80 | `getDword0x28` | high | Returns *(ECX+0x28) |
| 434a90 | `region::getCell1024` | high | Bounds-checked (0..0x400) 2D access into region array at ECX+0xbc (1024x1024, 4-byte) |
| 434b70 | `getDword0x1c` | high | Returns *(ECX+0x1c) |
| 434c10 | `getBlockType5bits` | high | Returns byte at ECX+3 & 0x1f (block/type low bits) |
| 439600 | `list::allocNode32` | high | operator_new(0x20) self-linked list node sentinel; _Xbad_alloc on failure |
| 43a3f0 | `std::map<u16,T>::lower_bound` | high | rbtree lower_bound by ushort key at node+0xe |
| 43a490 | `getDword0xe8` | high | Returns *(ECX+0xe8) |
| 43a4a0 | `textBuffer::clampScroll` | high | Clamps scroll start (+0x188) and length (+0x18c) into [0, count(+0x178)] |
| 43abc0 | `int64::subFixed16` | high | Writes ECX_int64 minus (param_2<<16) into param_1 (subtract integer as 16.16 fixed) |
| 43abf0 | `int64::addFixed16` | high | Writes ECX_int64 plus (param_2<<16) into param_1 (add integer as 16.16 fixed) |
| 43b480 | `block::isSolidType` | high | Returns 1 if (type&0x1f) is nonzero and not 2 (solid block test) |
| 43b610 | `vec6::set` | high | Sets 6 dwords ECX[0..5] from params (assign two int64 vec3 / 6-field struct) |
| 43ca60 | `curve::level05` | high | Returns 1 - 1/((n-1)*0.05+1) level-scaling curve |
| 43e550 | `ability::matchesId0x19` | high | Returns true unless ability id 0x19 whose value (param+4) mismatches computed (+0x1164 %100) |
| 443f10 | `list::findByTypeByte` | high | Linear-searches intrusive list at +0x1178 for node whose byte at +2 == param_1; returns payload or null |
| 444820 | `weapon::isSpecialRunePtr` | high | Same test as 00444230 but on ptr arg (*ECX==3 and subtype in set) |
| 444d60 | `xp::getNextLevelCost` | high | Returns XP-to-next-level: (1-1/((lvl-1)*0.05+1))*1000+50 |
| 4460a0 | `list::pushBack` | high | Appends node (00451c70) to list at ECX, size++, throws if len==0x5555554 |
| 4462f0 | `curve::inverse20p1` | high | Returns (1/(1-x)-1)*20+1 |
| 447270 | `Player::resetPhysics` | high | Zeroes physics/transform member block (+0x24..+0x14c) |
| 447b00 | `xp::applyLevelUps` | high | While XP(+0x194) >= next-level cost, level up (+0x190), recompute regen 00444db0 |
| 4497a0 | `handle::isOpen` | high | Returns *(ECX+4) != 0 (resource/db handle open test) |
| 449810 | `db::loadBlobByKey` | high | SQLite 'SELECT value FROM blobs WHERE key=?': binds key, steps, allocates+copies blob to out |
| 4499f0 | `db::storeBlob` | high | SQLite upsert blob: SELECT existence then UPDATE or INSERT (prepared stmts); logs 'DATABASE WRITE ERROR' |
| 44a8a0 | `refcount_initTo1` | high | Init small handle: *ecx=param, [1]=1, [2]=0 (refcount/control-block style) |
| 44b770 | `allocNode_0x120` | high | Allocates 0x120 node (map/tree), self-links if params null |
| 44d620 | `stream_readBytes` | high | Stream read: memcpy param_2 bytes from buffer *ecx at cursor [3], advance cursor |
| 44e8d0 | `buffer::append_bytes` | high | append param_2 bytes to growable output buffer via memcpy |
| 450dc0 | `releaseTwoRefPtrs` | high | Releases up to two ref-counted pointers at ecx[4] via vtable+0x10 (Release) |
| 450e70 | `spawnWorkerThread` | high | Allocates 0x18 arg block, calls virtual to fill it, launches _beginthread(FUN_00450e00) |
| 450f60 | `fixedToIntVec3` | high | Divide 3 int64 components by 0x10000 (16.16 fixed to int) via __alldiv |
| 4511e0 | `floatToIntVec3` | high | Truncate 3 floats to ints |
| 451440 | `memEqual_0040c520` | high | Returns memcmp(field+0x10, param_2 buffer, len)==0 (byte-string equality) |
| 4514e0 | `wideMemCompare_ne` | high | Compare via 00428db0 (wide/ci memcmp); returns !=0 |
| 451510 | `vec3_scale` | high | Multiply vec3 param_3 by scalar param_2 into param_1 |
| 4515f0 | `string_ctorAppend` | high | std::string ctor: init SSO, reserve len(param_3)+existing via 00407d50, append range (0046ef60/0046f050) |
| 457460 | `GameController_lerpVec3` | high | Linear-interpolate vec3 param_1 toward param_2 by factor t from 004ac150 |
| 457e00 | `pair_assign_byteDword` | high | Assign pair: byte from param_2 + dword from param_3 |
| 458b90 | `storeShort` | high | Store short param_2 at *param_1 |
| 458bd0 | `strcpy16` | high | strcpy_s(dst,0x10,src) wrapper |
| 458bf0 | `swapDword` | high | Swap two dwords |
| 458ce0 | `storeDword` | high | Store dword: *ecx = param |
| 458d20 | `storeRGBA` | high | Store 4 bytes (RGBA/quad) into *ecx |
| 458de0 | `noop` | high | Empty function (no-op stub) |
| 459a90 | `Struct_reset_4Dwords` | high | Zero first 4 dwords; class GameController likely misattrib |
| 459c40 | `ctor_0` | high | cube::GameController::ctor_0 (48075 B, giant ctor). Ghidra process:timeout at 120s in full export; recovered clean via GhidraDecompileList.java 3600s window (114s). Body in gap/cube/extra_bodies.c, merged by reconstruct2. |
| 465bb0 | `Struct_reset_10Dwords` | high | Zero 9 dwords plus word at +5 |
| 465de0 | `Struct_init_defaults_off2b` | high | Zero fields, set +0x2b=1.0f, +0x2d=4000, then FUN_00423e70 |
| 4664b0 | `Struct_init_off4_defaults` | high | Set +4=-100.0f, +0x4c=7, +0x48=0, +0x38=0, +0x50=1000 (string cap + defaults) |
| 466880 | `Struct_ctor_allocListHeads` | high | Constructor allocating ~13 list/container sentinel nodes into slots 0..0x18 (SEH guarded) |
| 467f30 | `Object_dtor_composite` | high | Destructor: FUN_00661680 then clear vector member at +0x4c |
| 467fe0 | `String_freeIfNotSelf` | high | Free string param_1 via FUN_0040f680 if not self |
| 4685e0 | `Object_copyAssign_off118_vec` | high | Copy-assign: FUN_0042c5e0 base, field +0x118, vector at +0x11c via FUN_00468050 |
| 468620 | `Struct_copy_10Dwords_bytes` | high | Copy ~0xa dwords plus bytes at +5/+0x15 |
| 468670 | `Struct_copy_skipIdx1_11` | high | Copy dwords 0,2..0x11 skipping index 1, byte at 0xc |
| 468840 | `operator_eq_2ints` | high | Compare two consecutive ints for equality (memcmp-style over 2 dwords) |
| 468870 | `operator_eq_3ints` | high | Compare three consecutive ints for equality (vec3-int key ==) |
| 4688a0 | `operator_ne_2ints` | high | Compare two ints, inverted result (operator!= over 2 dwords) |
| 4688d0 | `operator_ne_int` | high | Return *this != *param_1 (single int inequality) |
| 468c80 | `iterator_prev_0xc` | high | Return *this - 0xc |
| 468c90 | `iterator_at_0x10` | high | Return *this + 0x10 |
| 468d50 | `iterator_postInc_2` | high | Return current then advance *this by 2 |
| 468d70 | `iterator_deref_advance` | high | Copy *this to out then FUN_005c3ea0 (advance/next) |
| 468d90 | `iterator_postInc_4` | high | Return current then advance *this by 4 |
| 468db0 | `iterator_postInc_0xc` | high | Return current then advance *this by 0xc |
| 468dd0 | `iterator_postDec_0xc` | high | Return current then decrement *this by 0xc |
| 468df0 | `vec2_sub` | high | param_1 = *this - param_2 over 2 floats |
| 468e70 | `Struct_copy6_thenReset` | high | Copy 6 dwords to out then FUN_0042c900(-0x10000,-1) |
| 468f50 | `vec4_add` | high | param_1 = param_2 + *this over 4 floats |
| 469000 | `vec2i_divScalar` | high | param_1 = *this / param_2 over 2 ints |
| 46d220 | `vec3_mulInPlace` | high | *this *= param_1 component-wise over 3 floats |
| 46d4e0 | `std::_Tree<>::_Buyheadnode` | high | operator new 0x1180 head sentinel node; self-link and mark nil |
| 46f430 | `iterator_backMinus4` | high | Return *(this+4)-4 (back element / end-1) |
| 46f440 | `deref_frontValue` | high | Copy *(*this) into param_1 (front element value) |
| 471910 | `getter_field80015c` | high | Return dword at +0x80015c |
| 477220 | `isZero_off10` | high | Return *(this+0x10)==0 |
| 477230 | `isZero_off4` | high | Return *(this+4)==0 |
| 4787f0 | `getter_field800164` | high | Return dword at +0x800164 |
| 47b450 | `getSelectedSlotCoords` | high | Return selected inventory (bag,slot) into param_1, or (-1,-1) if none valid |
| 47b550 | `getSelectedItemPtr` | high | Return ptr to selected inventory item entry, or 0 |
| 47b5f0 | `getter_off4c` | high | Return dword at +0x4c |
| 47f1c0 | `getter_byte3c4` | high | Return byte at +0x3c4 |
| 47f3b0 | `getter_flagBit0_f4` | high | Return bit0 of dword at +0xf4 |
| 47f9f0 | `isInteractableTileType` | high | True if tile type byte in {1,10,11,12,13,21} |
| 47fa10 | `hasActiveWorldChunk` | high | Return true if chunk data ptr (via +0x3c/+0x94/+0x68) nonzero |
| 47fa30 | `getItemTypeCategory` | high | Switch mapping item-type byte to category 0..3 |
| 47faa0 | `getChunkCellAt` | high | Return chunk cell dword at (param_1,param_2) if within 0x400 grid, else 0 |
| 480d90 | `getVelocityX` | high | Return float (+0xd4)-(+0xdc) |
| 480db0 | `getVelocityY` | high | Return float (+0xd8)-(+0xe0) |
| 480dd0 | `getPositionXY` | high | Copy floats +0xd4,+0xd8 to param_1 |
| 480df0 | `getPtr_off94` | high | Return this+0x94 |
| 484320 | `playSoundAtPlayer` | high | Wrapper: play sound param_1 at player pos (+0x140) via FUN_00484350 |
| 4861f0 | `std::list<T>::push_back` | high | Append node (elem via FUN_00451dd0), ++size |
| 4865b0 | `std::list<T>::push_back` | high | Append node (elem via FUN_004521c0), ++size |
| 487490 | `GameController_getField_b4` | high | Trivial getter: returns *(this+0xb4) |
| 487da0 | `GameController_getVoxelColumn8` | high | Bounds-checks x,y<0x2000, indexes chunk (FUN_00434a90, coords>>6) then column with 0x68 stride at +0x14018 |
| 487e60 | `GameController_getPair_18c_190` | high | Copies two dwords from +0x18c and +0x190 into out param |
| 487e80 | `GameController_set_1ec` | high | Trivial setter: *(this+0x1ec)=param |
| 487e90 | `GameController_set_b8` | high | Trivial setter: *(this+0xb8)=param |
| 487f70 | `vec2_lengthSquared_int` | high | Returns x*x + y*y from int pair at *this,this[1] |
| 487fe0 | `GameController_getSub_8000f0` | high | Returns this+0x8000f0 (address of a large embedded subobject) |
| 488030 | `GameController_interactSpecialObject` | high | 'There is nothing special.': finds special entity, sets quest/dialog state and a wchar message; interaction handler |
| 4882e0 | `GameController_interactNpc` | high | 'innkeeper': NPC/quest interaction; resolves target entity by world coords, opens trade/dialog UI |
| 4889e0 | `GameController_updateSelectedEntity` | high | Updates selected/targeted entity from screen pick (FUN_00477d90); dispatches by type 0x140 to open UIs |
| 488b80 | `GameController_get_8000bc` | high | Trivial getter: returns *(this+0x8000bc) |
| 488b90 | `GameController_asType2Object` | high | Returns param if object type (+0x48)==2 else 0 (safe cast/filter) |
| 488bb0 | `GameController_asType3Object` | high | Returns param if object type (+0x48)==3 else 0 |
| 488d60 | `mat4_transformPointProjective` | high | Transforms a 3D point by a 4x4 matrix with perspective divide (1/w) |
| 488e50 | `mat3_transformVector` | high | Transforms a 3D vector by the 3x3 rotation part of a matrix (no translation) |
| 488ee0 | `vfunc_10` | high | cube::GameController::vfunc_10 per-frame update path (77332 B, largest func). Full-export failure was 120s timeout; retry hit decompiler payload cap; recovered with 3600s + 512MB payload. Body in extra_bodies.c. |
| 49d650 | `GameController_buildCharacterList` | high | Builds CharacterPreviewWidget grid from saved characters; lays out widgets, pushes to selection list |
| 4a14c0 | `GameController_loadInventoryItems` | high | Iterates DB item list (FUN_0059cff0), classifies by type into 6 vectors, sorts and installs (FUN_004a19d0); frees temps |
| 4a19d0 | `GameController_computeCraftPrices` | high | For category param_1, computes average craft cost per recipe from ingredient lists and stores into 12-byte vector |
| 4a1e50 | `GameController_equipStarterGear` | high | Char-class switch(1-4): assigns starter equipment ids into slot arrays and appends 4 items to a list |
| 4a2300 | `GameController_rebuildCraftState` | high | Rebuilds crafting/recipe UI state; if flag copies recipe vector nodes (FUN_00486700), else pulls from selected entity |
| 4a23d0 | `GameController_buildWorldList` | high | 'online_': builds WorldPreviewWidget grid from save/online world list, filtering by 'online_' prefix |
| 4a2780 | `GameController_handleObjectAction` | high | Consumes a pending object action (count at *param): plays effect / sets cursor state by sub-type 5 |
| 4a2870 | `GameController_voxelAt3D` | high | Returns pointer to 3-byte voxel at (x,y,z) in a volume with dims at +0x44/48/4c, data at +0x30; else dummy |
| 4a6ad0 | `GameController_getField16` | high | Bounds-checks x,y<0x10000, indexes chunk (FUN_00434a90, >>6) then 16-byte cell at +0x18 |
| 4a8ef0 | `vec3_floatToByte3` | high | Converts 3 floats at param_1 to 3 bytes at this (truncating cast) |
| 4a8f20 | `int_notEqual` | high | Returns *param_1 != *param_2 (bool) |
| 4a8f40 | `vec4_scale` | high | Multiplies 4-component vector param_3 by scalar param_2 into param_1 |
| 4aba20 | `float_lerp_smooth` | high | Linear interpolates *param_1 toward *param_2 by factor from FUN_004ac150 |
| 4abc00 | `pair_zeroInit` | high | Zero-inits two dwords (*this=0, this[1]=0) |
| 4abc30 | `iter_prev_4` | high | Returns *this - 4 (previous 4-byte iterator) |
| 4abc40 | `iter_postinc_188` | high | Post-increment: returns old *this, advances by 0x188 |
| 4abc60 | `iter_postinc_10` | high | Post-increment: returns old *this, advances by 0x10 |
| 4abc80 | `iter_postinc_30` | high | Post-increment: returns old *this, advances by 0x30 |
| 4abca0 | `iter_postdec_4` | high | Post-decrement: returns old *this, moves back by 4 |
| 4ac150 | `iterated_lerp_toward1` | high | Applies x += (1-x)*t param_1 times (unrolled by 8); exponential approach used as blend factor |
| 4ac260 | `vfunc_11` | high | cube::GameController::vfunc_11 (59248 B). Same recovery route: 3600s + 512MB payload (135s). Body in extra_bodies.c. |
| 4c0ec0 | `GameController_getFlag30_bit0` | high | Returns *(this+0x30) & 1 (a boolean flag) |
| 4c0ed0 | `GameController_isTimerZero_1cc` | high | Returns 1 if float at +0x1cc == 0.0 else 0 |
| 4c0ef0 | `perlinNoise2D_cosInterp` | high | 2D value/Perlin noise with hashed lattice and cosine interpolation; returns float in ~[0,1] |
| 4c6140 | `InventoryWidget_rebuildItemList` | high | Rebuilds inventory item widgets: filters equipped items, lays out per-item widgets with callbacks |
| 4c6350 | `InventoryWidget_updateScroll` | high | Computes visible-row/scroll state for the item grid based on panel geometry |
| 4c64c0 | `InventoryWidget_drawScrollbar` | high | Draws inventory scrollbar/thumb via FUN_0062bb20 scaled to row count and viewport |
| 4c6610 | `InventoryWidget_handleSlotHover` | high | Handles slot hover/selection: on click sets selected slot (FUN_00484320 0x55) and highlights hovered cell |
| 4c6b80 | `GameController_itemCooldown` | high | Returns cooldown 10000 (or 3000 if subtype 1) for type-1 items, else 0 |
| 4c6cc0 | `GameController_avgEquippedColor` | high | Averages material colors (FUN_004c7250) of equipped items with material>=0x80; SEH cookie |
| 4c71c0 | `item_glowColor` | high | Returns emissive/glow RGB for special item types (0xb/0x12), else black |
| 4c7250 | `material_toColor` | high | Maps a material/type id to an RGBA tint (large switch), modulating base color param_3; case 0x80+ glow |
| 4c76a0 | `item_rarityScaled` | high | Returns item rarity/quality int: FUN_0043ca60(level)*100+1 |
| 4c7be0 | `item_hasSpecialAbility` | high | Returns 1 if item has a special ability (subtype +0xd in {1,0xb,0xc,0x16}) else 0 |
| 4d4de0 | `GameController_pickSpawnPoint` | high | Copies spawn coords from param, finds matching spawn index in list, then picks a random spawn position |
| 4dd5e0 | `GameController_clearListLocked_3c` | high | Under lock (FUN_00601cb0/e90) applies FUN_004544d0 to list at +0x3c then clears/frees it |
| 4dd640 | `GameController_clearListLocked_44` | high | Under lock applies FUN_00453ff0 to list at +0x44 then clears/frees it |
| 4dd6a0 | `GameController_clearListLocked_34` | high | Under lock applies FUN_004540c0 to list at +0x34 then clears/frees it |
| 4e3790 | `map::lower_bound_string` | high | RB-tree search by string key comparing via FUN_00428db0; returns nearest node (lower_bound) |
| 4e7650 | `VoxelModel::set_data` | high | Copies voxel color data into model, scans for axis-marker voxels (RGB axes) as anchors, then builds mesh |
| 4e7870 | `VoxelModel::build_mesh` | high | Builds render mesh from voxel grid: generates per-face quads with ambient occlusion, colors and normals into vertex buffers |
| 4ec400 | `GameController::item_icon_id` | high | Large switch mapping item type/subtype/material to sprite/icon resource ID, with fallback cached array lookups |
| 4ee230 | `GameController::load_game_assets` | high | Loads core game data files (data1.db, cubequest4.cub, spiribit.cub, egg1.cub, body/head/glove .cub) into sprites/DB |
| 58ce20 | `GameController_ClearSelection` | high | Game: resets the controller's selection index to -1 and clears the active-binding flag |
| 58ce40 | `GameController_ToggleSelection` | high | Game: sets selection index to +0x2ac, or -1 if it already equals that value (toggle) |
| 598840 | `World::findObjectById` | high | RB-tree/map find by int key against tree root at world+0x800154; returns node value field [5] or 0 |
| 5988a0 | `World::areEntitiesHostile` | high | Hostility test between two entities via faction byte +0x60 and aggro flag +0x124; 6=passive short-circuits |
| 59fb90 | `World::getChunkEntity` | high | Returns pointer to entity index param_1[2] in a chunk's vector (0x148 elems) if in range, else 0 |
| 5a0910 | `resolveVectorElementByHandle` | high | Look up container via FUN_00434d10(key0,key1), bounds-check index param_1[2], return element ptr (stride 0x188) or 0 |
| 5a0ed0 | `NameGen::initFirstNameTables` | high | One-time lazy init of NPC first-name/syllable wstring vectors (Wolf/Lugo/Liku...) guarded by DAT_0076b9e8 bits; _atexit cleanup |
| 5a6a70 | `vec3ToFixed64` | high | Convert int[3] to 16.16 fixed-point int64[3] (val<<16 low word, sign-extended high) |
| 5a6b60 | `allocObjectWithVec3` | high | Allocate object via FUN_0043c8e0 and store vec3 (param_3[0..2]) at +8/+0xc/+0x10 |
| 5c3d60 | `GameController::chunkMap2i_at` | high | map<vec2i,T> operator[]: cache-check nearest node vs 2D key, else insert via FUN_00639be0/FUN_005c0630 |
| 5ee4b0 | `assign_two_dwords` | high | Copies two 32-bit fields from param_2 to param_1 (POD pair assignment) |
| 601cb0 | `enter_critical_section` | high | Enters a critical section (external:00000018); trivial lock wrapper |
| 601e90 | `leave_critical_section` | high | Leaves a critical section (external:00000019); trivial unlock wrapper |
| 630a10 | `object_alloc` | high | Allocates an object via operator_new; shared factory |
| 632870 | `Node::dtor_release_children` | high | Node destructor: SEH-guarded, releases each child (FUN_006504e0) then frees child-list nodes |
| 633d70 | `Node::find_child_by_name_recursive` | high | DFS a node tree comparing name via FUN_00428db0(memcmp); returns first matching node or 0 |
| 635700 | `Node::propagate_resolved_value` | high | Recursively set node +0x44 from parent/slot then recurse children (resolve inherited value) |
| 6364f0 | `Node::any_child_active` | high | Recursively return 1 if this node or any active child has slot flag +0x2c set |
| 636870 | `Node::remove_child_from_list` | high | Remove child (matching param_1) from node's std::list at +0x2c and clear its parent link (+0x28) |
| 636990 | `Node::set_shape_slot` | high | Set attribute/shape slot at +0x34: release old (refcount==1 -> FUN_006507c0) and retain new |
| 639be0 | `Node::make_vec3_node` | high | Allocate list node (FUN_006819e0), zero header, copy 3-float vector from param_1 |
| 64eae0 | `Registry::push_node_locked_0x94` | high | Under CS, append list node to list at +0x94 (GameController variant) |
| 64ef70 | `Node::traverse_invoke_callback` | high | Recursively invoke callback param_2 on nodes that are visible/enabled (flags at +200), descend children |
| 6502e0 | `TextShape::new_instance` | high | Factory: operator_new(0x21c) + plasma::TextShape::ctor_0 |
| 6507c0 | `ShapeNode::unregister_and_release` | high | Under CS, unlink shape node from registry list at +0x74 and release |
| 6508f0 | `Widget::unregister_and_release` | high | Clear focus/hover/capture refs then under CS unlink widget from list at +0x7c and release |
| 650ae0 | `GameController::hittest_if_no_capture` | high | If no captured widget (+200==0), run hit-test at cursor position (+0xd4) |
| 6531e0 | `GameController::get_tooltip_widget` | high | Return current tooltip/popup widget pointer at +0xcc |
| 657c00 | `ScrollButton::read_field` | high | Deserialize one ScrollButton field by opcode 0x11/0x12/0x13 into +0x238/+0x23c/+0x248 |
| 657ee0 | `ScrollSlider::read_field` | high | Deserialize one ScrollSlider field by opcode 0x14/0x15 into +0x238(bool)/+0x250 |
| 658530 | `istream::read_string` | high | Read length-prefixed char std::string from istream (alloc temp buffer, copy, free) |
| 658c40 | `Texture::load_from_file_freeimage` | high | Load an image file via FreeImage (format sniff by extension), convert BGRA->RGBA and upload to texture (vtbl 8) |
| 658fa0 | `Texture::load_from_memory_freeimage` | high | Load image from memory buffer via FreeImage_LoadFromMemory, convert BGRA->RGBA and upload to texture |
| 662fb0 | `Widget::setAspectFitEnabled` | high | Simple setter storing a flag/value at offset 0x24c |
| 664ba0 | `list::pushFrontNode` | high | Inserts a new node at the head of a std::list, incrementing size and guarding the 0x15555554 length limit |
| 67d9e0 | `setField240` | high | Stores param_1 into the object field at offset 0x240 |
| 683070 | `Button::deserializeProperties` | high | Parses serialized Button object properties from istream, reads "Button.type" int into obj+0x22c, delegates rest to Widget parser |
| 683270 | `Display::deserializeProperties` | high | Deserializes Display scene node from istream: name/wname/visibility/clipping/colors/blurRadius/flags fields |
| 683750 | `deserializeWidgetOnlyObject_0064f200` | high | Loads an object (via factory FUN_0064f200) reading only shared Widget properties per token from istream |
| 683870 | `GenericShape::deserializeProperties` | high | Deserializes GenericShape from istream: name/wname/source/wsource/position/size fields via factory FUN_0064f280 |
| 683de0 | `deserializeWidgetOnlyObject_0064f300` | high | Loads an object (factory FUN_0064f300) reading only shared Widget properties per token from istream |
| 683f00 | `Node::deserializeProperties` | high | Deserializes scene-graph Node (name/wname/shape/transformation/display/widget/child/flags/variable); builds child list, links |
| 684770 | `Button::deserializeProperties_0065` | high | Parses Button object props from istream (factory FUN_006500d0): reads "Button.type" into +0x22c, else Widget parser |
| 684970 | `ScrollButton::deserializeProperties` | high | Deserializes ScrollButton: "ScrollButton.direction"->+0x238, "Button.type"->+0x22c, else Widget props |
| 684c30 | `ScrollSlider::deserializeProperties` | high | Deserializes ScrollSlider: "ScrollSlider.direction"->+0x238, "Button.type"->+0x22c, else Widget props |
| 684ef0 | `SmoothMeshShape::deserializeProperties` | high | Deserializes SmoothMeshShape mesh (name/faces/vertex flags/params/positions/texcoords/colors/stroke/extrusion arrays) |
| 685b10 | `TextShape::deserializeProperties` | high | Deserializes TextShape: name/wname/string/frame/sequence/colors/flags/pixelSize/strokeRadius/spacing |
| 686820 | `Texture::deserializeProperties` | high | Deserializes Texture: name/wname/id/pixelFormat/filters/wrap/width/height/pixels/compressedPixels |
| 686ff0 | `Transformation::deserializeProperties` | high | Deserializes Transformation node: name/wname/translation/rotation/pivot/deformation via factory FUN_00650360 |
| 687440 | `deserializeWidgetOnlyObject_006503e0` | high | Loads an object (factory FUN_006503e0) reading only shared Widget properties per token from istream |
| 687560 | `Widget::readProperty` | high | Parses one shared Widget property token (name/wname/caption/bind pos/size/matrix/alignment/flags) into widget struct |
| 687ad0 | `Widget::applyBindMatrix` | high | Copies two 16-word (4x4) matrices from src into widget at +0xa8 and +0xe8, then calls FUN_0058c440 (mark dirty) |
| 688180 | `StreamReader::readTaggedBlockAppend` | high | Reads a length int from istream, computes end offset via tellg, appends new list node (checks list-too-long) |
| 688220 | `StreamReader::readToken` | high | Reads a length-prefixed token/string from istream into param_1 (std::string), handling ref-back dedup table |
| 688490 | `StreamReader::endBlockCheckPos` | high | Verifies current istream tellg matches expected block end; if so pops/frees the tail list node, returns success byte |
| 688510 | `StreamReader::readString` | high | Reads length-prefixed narrow string from istream into std::string param_1 (empty string shortcut for len 0) |
| 6886f0 | `StreamReader::skipBlock` | high | Reads a length int then seekg's the istream forward past that block (skip unknown/unhandled property) |
| 40e030 | `ostrstream_str` | med | std::ostrstream::str(): builds std::string from strstreambuf get/put area honoring frozen flags |
| 40e140 | `ostrstream_str_wrap` | med | Wrapper returning result object after FUN_0040e030 (ostrstream::str) |
| 40ee70 | `entityState_copy` | med | Copies a 0x118-byte record (header fields + 0x20-entry array of 8-byte structs); item/equipment copy |
| 40ef70 | `ptrAt_0x4c_0x20x8` | med | Returns +0x4c + count(+0x20)*8: end pointer of an 8-byte-stride array |
| 411a90 | `setFlagAtSlot` | med | Writes bool(param_1) into array at +0x94 indexed by +0x68 (per-slot flag) |
| 411ad0 | `u16_ostrstream_str` | med | u16string variant of ostrstream::str(): builds u16string from strstreambuf area honoring frozen flag |
| 411bc0 | `u16_ostrstream_str_wrap` | med | Wrapper returning result after FUN_00411ad0 |
| 4128f0 | `Creature_drawModel` | med | Massive character/creature model+animation render: composes bone transforms, matrix math, draws parts |
| 423f70 | `computeYawFromDir` | med | Computes an angle blend using cos/sin/asin of two angle params scaled by param_3 |
| 428990 | `math::vec4_sub` | med | subtract two 4-float vectors (game math) |
| 42c580 | `int64::setFromGen` | med | Sets single int64 field ECX[0] to value returned by 0068d946 |
| 42c5e0 | `Item::copyStruct` | med | Byte-copies a ~0x118-byte item struct (header + 0x20 entries of 8 bytes + trailer at 0x114) |
| 42c6c0 | `getPtrPlus8` | med | Returns *ECX + 8 (address of embedded subobject) |
| 42c860 | `int64::ltFixed16` | med | Compares (param_1<<16 sign-extended) against ECX int64; returns bool in low byte |
| 42f000 | `map::valueAtOr0` | med | Lower-bounds key via 00477d90; returns *(node+0x18) or 0 if end |
| 42f360 | `state::initA` | med | Zero-inits state block incl memset 0x100 buffer at +0x14 and extra dwords (+0x8a..+0x92) |
| 42f3e0 | `state::initB` | med | Zero-inits state block: fields + memset 0x100 buffer at +0x14 |
| 42f4a0 | `Item::equals` | med | Compares two 0x118-byte item structs field-by-field incl 0x20-entry loop and sub-item compare 00428940 |
| 42f590 | `computeCellOffset` | med | Returns *(ECX+0x20)*0x40 + *(ECX+0x4c) (linear index/byte offset) |
| 42f730 | `array::atChecked4` | med | Bounds-checked 4-byte element access; returns global fallback (0076afc8/d0) on OOB |
| 434870 | `block::isPassableType` | med | Tests block type byte *ECX against blocked-type set; returns 1 if none match (passable) |
| 434ad0 | `mat::scaleColumns` | med | Scales matrix rows 0-3 by param_1 and rows 4-7 by param_2 (skip if factor==1.0) |
| 434b80 | `mat::translateByCols` | med | Adds col0*p1 + col1*p2 into translation column (mat[0xc..0xf]) of 4x4 float matrix |
| 439210 | `colorMap::allocNode` | med | Allocates RB node (004395c0), inits key/color fields (+0x1c=7,+0x18=0, RGB from param_3+0x18) |
| 439300 | `list::insertNodeAt` | med | Allocates node, splices into intrusive list before param_3 (prev/next fixup) |
| 43a010 | `textInput::insertChar` | med | Appends/inserts char into text buffer if len<0x1f: adjust scroll, build substring 0043a270, bump position |
| 43a500 | `text::layoutWordWrap` | med | Word-wraps a wstring into a line list: splits on space/CR/LF, measures words via 0065e720 against width, builds nodes |
| 43ac20 | `vec3i64::dotFixed` | med | 3-component 16.16 fixed dot product of param_2 and ECX (three __allmul, /0x10000, summed) |
| 43c0a0 | `struct::initSmallWithBuf` | med | Zero-inits smaller struct with memset 0x100 buffer at +6 |
| 43c3e0 | `container::destroy` | med | Destroys container via 0067eb10 then operator_delete(*ECX) (RB/map destructor) |
| 43caa0 | `combat::getAttackWindup` | med | Returns attack windup/cooldown frames per weapon type (big switch), scaled by attack-speed & material |
| 43d1a0 | `combat::getAttackTiming` | med | Two-stage switch computing attack windup and recovery frames per weapon type, scaled by speed |
| 43df60 | `equipment::getActiveElement` | med | Builds list of active element/rune from equipment slots (+0xaa8,+0x990) per weapon type; returns list |
| 43e190 | `stat::calcSpellPower` | med | Computes spell/magic power: base 2^ terms plus rune bonuses from slots (+0x990,+0xaa8) |
| 43e350 | `combat::isReadyToStrike` | med | Returns 1 if attack timer elapsed (0043d1a0) for eligible weapon type and cast timer <=0 |
| 43e420 | `combat::rollBlockSuccess` | med | Rolls level-scaled chance vs rand and shield-type check 004c6f20; returns bool |
| 43e4a0 | `quest::checkItemThreshold` | med | Sums matching item counts across bag/equipment (0042f4a0 compares) and tests against threshold for ability id |
| 43e6a0 | `ability::getManaCost` | med | Returns ability mana/spirit cost in units per ability id (switch), scaled by level factor 0043ed60 |
| 43ed60 | `ability::getPowerFactor` | med | Returns ability power factor 1-1/(rank*0.1+1); resolves rank from +0x1138 table or level if unset |
| 444760 | `weapon::isMeleeType` | med | Returns 1 for weapon/ability type ids in melee set (switch), else 0 |
| 444ae0 | `ability::getResourceCost` | med | Returns resource cost fraction per ability id; buff-list scan for '\t' gives 0.3 default |
| 444cb0 | `shield::getBlockDuration` | med | Returns block/parry duration frames by shield rune type, scaled by attack speed |
| 445020 | `combat::selectAttackAnim` | med | Decision tree selecting next attack/ability animation id from weapon+rune+form state |
| 446af0 | `statusList::upsert` | med | Upserts status/element entry in list (+0x1178): replace matching type byte, else push_back 00451d00 |
| 447110 | `Player::resetCombatState` | med | Resets combat/transform members and buffers (subset of 00446330) then FUN_0042ef10 |
| 447700 | `combat::getEffectiveHaste` | med | Computes attack-speed multiplier: base + shield fraction + element buff 004478b0 + rage-form scaling |
| 4478b0 | `stat::calcHasteBonus` | med | Sums element/rune haste bonuses across many equipment slots (004c7c00) ×0.1 |
| 447d50 | `render::bindNodeTransformB` | med | Render glue: uploads uniforms via device vtable (0x15c,0x170,0x1ac) using field +0x10 |
| 447d90 | `render::bindNodeTransformC` | med | Render glue: uploads uniforms via device vtable using field +0xc |
| 447dd0 | `render::bindNodeTransformD` | med | Render glue: uploads uniforms via device vtable using field +0x14 |
| 447fb0 | `render::setVec3Uniform5c` | med | Uploads vec4(param,0,0,0) to shader constant (device vtable 0x1b4) at register +0x5c |
| 448010 | `render::setVec3Uniform70` | med | Uploads param vec3 (w=0) to shader constant (vtable 0x178) at register +0x70 |
| 448070 | `render::setUniform34` | med | Uploads param to shader constant (vtable 0x178) at register +0x34 |
| 448090 | `render::setFogUniform64` | med | Uploads scalar (param-80)/-30 as vec4 to shader constant reg +0x64 (fog/height factor) |
| 448100 | `render::setInvUniform60` | med | If param>0 uploads vec4(1/param,0,0,0) to shader constant reg +0x60 |
| 448170 | `render::setLightDirUniform` | med | Uploads 3 constants then normalizes vec3 (sqrt) light direction into shader (vtable 0x178) |
| 448280 | `render::setUniform30` | med | Uploads param to shader constant (vtable 0x178) at register +0x30 |
| 4482a0 | `render::uploadModelViewMatrices` | med | Multiplies mat4s (model*param2, *param3) and uploads world/view matrices to shader constants (vtable 0x178) |
| 448fe0 | `render::setVec3Uniform58` | med | Uploads vec4(param,0,0,0) to shader constant (vtable 0x1b4) at register +0x58 |
| 449040 | `render::setThreeUniforms` | med | Uploads three params to shader constant registers +0x4c,+0x50,+0x54 (vtable 0x1b4) |
| 449090 | `render::setVec3Uniform48` | med | Uploads vec4(param,0,0,0) to shader constant (vtable 0x178) at register +0x48 |
| 449150 | `ostream::writePadded` | med | std::operator<<(ostream,char*): writes C-string with width/fill/adjustfield handling; SEH-guarded |
| 4498d0 | `db::getBlobInto` | med | Loads blob via 00449810 then grows out vector 005870c0 and memcpy into param_2 buffer |
| 4499c0 | `db::storeBlobVec` | med | Computes [begin,end) range from param_2 vector and stores as blob via 004499f0 |
| 44a690 | `swapElem_0x11c` | med | Swaps two 0x11c objects using 280-byte temp; ecx is likely GameController-owned but this is a value swap |
| 44a7e0 | `ctor_ObjWithListMap` | med | Constructor: zero header, alloc list sentinel (0044b740) and map/list node (0044b770), init capacity fields |
| 44aff0 | `copyCtor_ObjWithVec` | med | Copy-construct object: vector<0xc> copy (0044ad30), copy dword +0xc, string +0x10, ints +0x128/+300 |
| 44b040 | `copyCtor_EntityLike` | med | Field-by-field copy-constructor of large (~0x460+) struct incl strings, sub-array 0x118, tail bytes |
| 450b70 | `GameController_isHoveredTileType0e` | med | Returns 1 if hovered tile (00450960) exists and its type byte==0x0e |
| 450f40 | `bytesToUint2` | med | Load byte then dword into two uints |
| 4513f0 | `adjustorThunkCall` | med | Adjusts this-pointer by vtable offset then invokes function pointer param_2[0] |
| 452600 | `dtor_freePtrRange_0x128` | med | Destroy range stride 0x128 (0x4a dwords): free owned pointer at +0x11c each |
| 457930 | `GameController_collectTextShapes` | med | Recursively walk shape tree; RTTI-cast plasma::Shape->plasma::TextShape and push matches into list |
| 457ec0 | `stream_writeString` | med | Serialize a std::string to stream: reserve (005870c0), memcpy chars, flush (0040d910) |
| 458d40 | `std::list<T>::list(const&)` | med | list copy-ctor: buy head sentinel (FUN_0044b740) then copy-assign range |
| 459070 | `std::list<T>::list(const&)` | med | list copy-ctor: buy head then _Insert_range FUN_00454190 |
| 465fd0 | `T::T()` | med | Class ctor: allocate map head (FUN_0046d520) + secondary member (FUN_00630a10) |
| 466650 | `setQuadFaceFromNormal` | med | Pack float[4] color to RGBA at +4, map int[3] normal param_2 to face index 0-5 at +3 |
| 467af0 | `tree_dtor_free@unwind` | med | SEH unwind funclet: destroy tree (FUN_004777f0) then delete member at +8 |
| 4686e0 | `Object_copyCtor_withSubobjects` | med | Copy-ctor: copy scalars, sub-list at +5 via FUN_004571d0, tree at +7 via FUN_0043c920, string at +10 |
| 468ca0 | `fixedMul_16_16` | med | Fixed-point multiply: ftol64(x) * param_3 pair then /0x10000 (16.16 math) |
| 468eb0 | `fixed_sub_scaled_64` | med | param_1(int64) = param_2<<16 - param_3(int64) |
| 469060 | `int64_divScalar_double` | med | param_1 = ftol64((double)*this / param_2) |
| 46eb90 | `tree_setVisibilityFlagRecursive` | med | Recursively set/clear bit 2 of flags at +200 across child tree at +0x2c |
| 4719f0 | `GameController_disconnect` | med | Network disconnect: close socket/threads, print 'Disconnected.', add chat line, clear player list |
| 477e10 | `findNearestEntityInGrid` | med | Scan 3x3 chunk grid around world pos, return nearest entity by FUN_005eeee0 distance |
| 47ae10 | `collectFilledInventorySlots` | med | Build vector of (bag,slot) pairs for inventory items above player level, class GameController |
| 47b1b0 | `getEquipmentSlotPtr` | med | Return equipment slot base offset by matching equip type via FUN_006294c0 chain |
| 47b340 | `getTargetedItemName` | med | Return name string ptr of currently targeted/selected inventory item, else null |
| 47b3e0 | `getInteractTargetName` | med | Return name string of interaction target entity, else null |
| 486a20 | `GameController_saveKeyedString` | med | If param_2, looks up value via FUN_004498d0 and serializes a keyed std::string (FUN_00658fa0) else default path |
| 487ea0 | `GameController_emitFormattedString` | med | Builds a std::string from a source string (FUN_00424da0) and passes to FUN_00636a00; SEH+cookie |
| 4c12f0 | `vec3_rotateTowardAngle` | med | Computes angle between two 3D vectors (acos of normalized dot) and applies rotation about their cross |
| 4c6e10 | `item_computeValue` | med | Item base value: type-1 items scaled 200x or 100x by subtype via FUN_00445f60 |
| 4c70b0 | `item_computeStat_armor` | med | Computes armor/defense-like stat (x5 * mults) for block/tool item types |
| 4c76e0 | `item_valueByType` | med | Item value int by weapon type (2x/1.5x/1x/100x mults) via FUN_00445f60 |
| 4c7c00 | `item_computeStat_variant3` | med | Per-item float stat for tool/weapon types with rng and subtype 0xc bonus |
| 4c7f60 | `item_weaponDamage` | med | Computes weapon damage for type-3 items: base scaled 2x/4x/8x by subtype |
| 4df760 | `GameController_terrainStateChanged` | med | Detects if terrain/interaction state changed vs world (compares 11 ints and byte flag); reads geometry |
| 4df880 | `GameController_questStateChanged` | med | Like 004df760 plus a quest-progress score threshold check (FUN_004df9c0) gating an update |
| 4df9c0 | `GameController_computeQuestScore` | med | Sums a weighted quest-progress score over 11 counters plus a class-change bonus |
| 4e1790 | `Container::ctor_default` | med | Default-constructs container: null head/tail, allocates sentinel via FUN_00630a10, then initializes rest |
| 4e4a20 | `GameController::build_quest_text` | med | Builds quest/speech text: constructs two maps (via 0046d520/00630a10), invokes substitute_placeholders |
| 4e5320 | `GameController::show_region_name` | med | Formats world region/zone display name ('Lands of', 'Ocean') from chunk coords; picks singular form if area small |
| 4e5c10 | `GameController::show_object_name` | med | Looks up object at coords (>>8) then formats its display name via format_object_singular_name |
| 4e6530 | `GameController::speech_text_fits` | med | Returns whether measured speech text height <= available height field at +0x16c |
| 4e6550 | `GameController::measure_speech_height` | med | Computes total speech text pixel height: sums line-node counts in list[+0x170] times lineHeight(+0x1d4) |
| 4e6bd0 | `color_equals3` | med | Compares 3 consecutive bytes (RGB triple) at in_ECX against in_ECX[param_1]; returns 1 if equal |
| 4e6df0 | `GameController::draw_mesh` | med | D3D9 draw glue: sets stream source, indices and DrawIndexedPrimitive via device vtable for object at +0x58 |
| 4e71d0 | `GameController::match_transparent_color` | med | Tests whether 3-byte color at param_1 matches palette DAT_0076b340 or its axis-variants |
| 4e75c0 | `VoxelModel::allocate` | med | Sets voxel dimensions (+0x44/0x48/0x4c) and allocates zeroed w*h*d*3 color buffer at +0x30 |
| 4eb8d0 | `VoxelModel::compute_ao` | med | Computes ambient-occlusion ratio for a voxel corner by sampling neighboring filled voxels along a direction |
| 4ec370 | `GameController::class_icon_id` | med | Maps a small profession/class index to its item/icon string ID via switch (0x354,0x351...) |
| 51be60 | `GameController::item_name_string_id` | med | Switch mapping item category/material/rarity to localized name string ID |
| 59aa60 | `World::getObjectName` | med | Map find by int key at world+0x800104; on hit constructs a string(+5) into param_1, else throws via 0040eb60 |
| 59cff0 | `GameController::playItemActionSound` | med | Selects and queues sound/effect events via 005a0d80 based on item category *param_1 and subtype param_1[1] |
| 5a03d0 | `World::findNearestSpawnPoint` | med | Gathers candidate spawn/teleport points from neighboring chunk cells into a list, then selects the nearest |
| 5a35d0 | `World::raycastVoxels` | med | March a ray (fixed-pt >>16) through voxel chunks up to distance param_3, sampling block solidity vs param_4, capped 500 steps |
| 5a5240 | `WorldMap::lookupTileValue` | med | Map lower_bound by (x,y) key vs end at +0x800124; build result struct {0,0,7} from found node +0x18, else raise via FUN_0040eb60 |
| 5a5cb0 | `collectSolidBlocksInBox` | med | Loop region/block grid over box (bounds param1-4, >>8 chunk, >>6&0x3f block), gather solid entities (byte&0x1f) into temp list, process, free |
| 5a9da0 | `PathMap::findInOpenSet` | med | Builds temp coord key, lower_bound in open-set map at +0x140c, compares key; returns matching node |
| 5c4800 | `GameController::sampleTemperatureGrid` | med | Scans 0x400-stride POI/settlement grid near (x,y), finds nearest and distance-weighted value; climate/temperature sample |
| 5c4dd0 | `GameController::sampleHumidityGrid` | med | Scans 0x400-stride POI grid near (x,y) for nearest, distance-weighted; second climate channel (humidity) |
| 5eefa0 | `World_getColumnDataAt2` | med | Returns pointer to per-column float data at (param_2,param_3); sibling of FUN_005ee540 |
| 5f0720 | `World_getRegionCellPtr2` | med | Region cell pointer/value helper (sibling of FUN_005ef040) for FUN_0059d640 |
| 5f51e0 | `GameController_buildDecalMesh` | med | Allocates+inits a mesh/particle buffer (memset, FUN_004c7830, FUN_0040ee70); paired with FUN_005f8ad0 |
| 5f8ad0 | `GameController_buildDecalMesh2` | med | Allocates+inits mesh/particle buffer (memset, FUN_004c7830, FUN_0040ee70); sibling of FUN_005f51e0 |
| 5f8e10 | `vec3_distanceSquared` | med | Computes squared distance (float10) between two position vectors; shared helper (label 'itembox') |
| 5fc160 | `GameController_tryLockAndProcess` | med | Scoped lock (EnterCriticalSection ext:18/19) wrapping FUN_00602440 work |
| 5fc1b0 | `GameController_processNetworkTick` | med | Large locked update (vfunc_11): message/entity processing under critical section |
| 601cc0 | `locked_pair_update` | med | Under lock, runs FUN_005eeee0/FUN_005eefa0 (fixed-point compute) pair |
| 608f20 | `object_release` | med | Releases/decrefs an object via FUN_0046d550 (vfunc-shared) |
| 60c510 | `GameController_updateSubsystems` | med | Per-frame subsystem update (vfunc_10 sibling): drives many system updates incl. exp decay (FUN_00622d40). 92208 B span, absent from ghidra_func_map.tsv (hence AUDIT.md failed=3 vs 4 stubs). Recovered with 3600s + 512MB payload (468s); body in extra_bodies.c. Server twin: 0x5322d0 (identical top-callee call profile). |
| 622d40 | `exp_decay_factor` | med | Returns an exponential factor (libm_exp) from param_1; smoothing/decay helper |
| 6294c0 | `GameController_updateWidgetLayout` | med | Triggers widget layout pass via FUN_00629300 |
| 62dc20 | `GameController_setWidgetBounds` | med | Sets widget bounds via FUN_0062d7f0 (cookie-guarded) |
| 62dcd0 | `GameController_setWidgetBounds2` | med | Sets widget bounds via FUN_0062d7f0 (variant) |
| 630220 | `string_appendGrow` | med | Appends to a string/vector with growth (external:91, FUN_00583cb0) |
| 630be0 | `Widget_setPositionFloat` | med | Sets a float position/bound and stores via FUN_00583cb0 vector (external:91) |
| 631460 | `AdaptionWidget_rebuildLayoutRecursive` | med | Recursively rebuilds widget layout (self-call, FUN_0062baf0 layout, FUN_00630be0 pos) |
| 634940 | `Node::get_first_material_name` | med | Recursively find first child whose material/state==3 and copy its name std::string into out |
| 635550 | `Node::find_child_name_by_string` | med | DFS node tree by name string, returning associated name std::string of first match |
| 636950 | `Node::detach_from_parent` | med | Detach node: remove from parent list and, if param given, remove+release the passed node |
| 636a00 | `Node::pick_link_by_name` | med | Recursively find node whose name matches param_1; on hit-test success (FUN_004514e0) activate link target and notify (FUN_00467f60) |
| 6393e0 | `Registry::foreach_node_locked` | med | Under critical section, in-order traverse RB-tree at +0x10 invoking FUN_0065b2a0 on entries with +0x28!=0 |
| 64ac00 | `GameController::update_render_targets` | med | Refresh render-target textures (FUN_00659ef0) and push camera/light matrices+params into render passes at +0xc10/c14/c18 |
| 64f4e0 | `NamedObject::create_with_defaults` | med | Create NamedObject with default ContinuousAttribute/DiscreteAttribute if args null; optional register (SEH) |
| 650980 | `Widget::render_pass` | med | Full widget render: begin (vtbl 0x4c), layout, draw subtree (632910), end (vtbl 0x50); returns result |
| 6526b0 | `GameController::notify_all_widgets` | med | Recursively update widgets (635700) then iterate widget list at +0x7c invoking vtbl 0x1c and registry callback |
| 652a70 | `GameController::on_button2_down` | med | Handle secondary button press: clear tooltip, dispatch press callback variants |
| 652b60 | `GameController::on_button2_up` | med | Handle secondary button release: dispatch release callback |
| 657a00 | `ScrollButton::deserialize` | med | Deserialize plasma::ScrollButton from istream (fields via 657c00) |
| 657ce0 | `ScrollSlider::deserialize` | med | Deserialize plasma::ScrollSlider from istream (fields via 657ee0) |
| 659320 | `ContinuousAttributeVec3::deserialize` | med | Deserialize plasma::ContinuousAttribute<Vec3> from istream (opcodes 1=name,2/3/5/6=keyframes) |
| 659740 | `NamedObject::deserialize` | med | Deserialize plasma::NamedObject base from istream (common fields via 659940) |
| 659940 | `Widget::deserialize_common_field` | med | Deserialize one common widget field by opcode (name, pos, size, color, matrix, flags, texture) |
| 659e80 | `istream_skipRecordByLength` | med | Reads a length int from istream then seekg's forward past that many bytes (skips a sized block). |
| 65b2a0 | `GameController::rebuildEntityLists` | med | Under critical section, walks two entity maps (+0x68,+0x70), frees per-entity sub-lists/objects and rebuilds id lists; 'list<T> too long'. |
| 6612d0 | `Image::reallocFromFields` | med | Thin wrapper re-invoking setPixelData using the object's own width, height and current pixel buffer |
| 687b10 | `hashString_FNV` | med | Computes FNV-like 64-bit rolling hash (mult 0x1f) over std::string bytes; returns hi:lo pair |
| 688030 | `StreamReaderCtx::init` | med | Initializes a deserialization reader context: sets list head, stores istream ptr at +8, zeroes fields, allocates helper |
| 6880c0 | `decodeScrambledBuffer` | med | In-place decodes/unscrambles a byte buffer of length param_2 using key table param_3 (modular index subtraction) |
| 68d910 | `float_to_uint64_round_guarded` | med | Converts float10 ST0 to rounded unsigned 64-bit; if DAT_0076e2a0 set uses simple truncation |
| 40f4f0 | `computeLevelDiffBonus` | low | Game logic: gets target entity (40f570), reads its level vs a table value, accumulates pow(2,..)-scaled amount |
| 411740 | `GameController::get_field_0x8006d0` | low | return dword at large struct offset (game accessor, not lib) |
| 411750 | `GameController::get_field_ptr_0x800a1c` | low | return pointer to struct field (game accessor, not lib) |
| 42c080 | `CharCreation::refresh_model` | low | rebuild displayed character model from customization state (game) |
| 42f720 | `get_float_field_0x1000e78` | low | return float at large struct offset (game accessor) |
| 4348d0 | `get_float_field_0xd4` | low | return float field 0xd4 (game accessor) |
| 4348e0 | `get_float_field_0xd8` | low | return float field 0xd8 (game accessor) |
| 434c20 | `node::applyDamageColorFlash` | low | If model node present, scales its color vec4 by ratio of two health values (0062f600/0062d50); render tint |
| 4392d0 | `list::makeNode` | low | Allocates list node 00439600 then inits payload via 0040eaf0 unless error (-8) |
| 43a0d0 | `NameInput::handle_key` | low | process keyboard char for name/text input field (game UI) |
| 43ab30 | `text::drawColoredString` | low | Packs 3 RGB floats*255 into a color then forwards to text layout 0043a500 |
| 43b4a0 | `vec3i64::selfDotFixed` | low | Calls dot 0043ac20 with self, returns result pointer (length-squared fixed) |
| 43b660 | `state::initFields10` | low | Zeroes fields +0x10,+0x14,+0x18,+0x20,+0x24 (init sub-state) |
| 444590 | `combat::canBlockNow` | low | Returns 1 if not attacking and weapon/shield state permits block |
| 444650 | `physics::isLandingHard` | low | Returns 1 if airborne-landing conditions met (flag +0x124&0x10, vel +0x3c<0, grounded) |
| 444a90 | `quest::hasActiveItemReq` | low | Returns 1 if quest object (+0x1d28) has an item matching 0042f4a0 in its bag list |
| 4460f0 | `creature::getScaleVec4` | low | Writes a scale vec4: crouch/mount case (0.8,0,0.5,1) via flag, else all 1.0 |
| 44931a | `ostream::writeEpilogue` | low | Exception-path epilogue for 00449150: setstate, _Osfx, release streambuf sentry |
| 44cb50 | `deserialize_struct_0x28` | low | read struct fields from stream buffer (game reader) |
| 44cce0 | `deserialize_struct_small` | low | read small struct fields from stream buffer (game reader) |
| 44d790 | `GameWorld::serialize_state` | low | serialize world/entity state into growable byte buffer (game, big) |
| 450920 | `GameController_getSelectedCount` | low | Returns 0/1/half of 004c76e0 based on 00450960 pointer validity |
| 450a00 | `GameController_isInFrontRange` | low | Range check of a position (006294d0) vs camera dist thresholds 30.0 (006294d0/00627ce0/00627d50) |
| 451420 | `storeShortViaAdjust` | low | Store short at *(base+vtbl[+4]+0x40) |
| 4573d0 | `GameController_interpTimeSum` | low | Interpolates via 004ac150 then sums two int64 (0068d946) into *param_1 |
| 4574f0 | `GameController_popbackAndFormat` | low | Builds two strings, calls 00457600, then pops back element (0xc) from vector at ecx+0x30, returns dword |
| 457600 | `GameController_writeTwoStrings` | low | If field>=0 emits two serialized strings (00457ec0) via 004042e0/0040da70 |
| 465ae0 | `T::T(const T&)` | low | Copy-ctor: base vector copy (FUN_004593e0) + string (FUN_0040ee70) + POD fields |
| 465ef0 | `T::T(const T&)` | low | Class copy-ctor: string (FUN_00459070) + list member (FUN_00458d40) + string tail |
| 46b740 | `WorkerThread::run` | low | GAME (mislabeled lib): vfunc_2 background worker thread body; allocs tree head, timeGetTime, io ordinals, big stack scratch |
| 46ebe0 | `GameController_addItemToInventory` | low | Add item/coin to inventory counters; coins at +0x4a/0x4b, else find/grow item slot vector |
| 46f620 | `GameController_reloadServerList` | low | Enter CS, set server name string, rebuild remote-player list from tree, notify + cleanup temp list |
| 4709c0 | `GameController_onItemPickup` | low | Item pickup: check carry limit ('You can't carry more'), consume drops, add to inventory, rng affix, play SFX |
| 470d80 | `voxelRaycast_modelPick` | low | Traverse model voxel grid along projected ray to pick a solid voxel (matrix param_2, FUN_004e71d0 solidity) |
| 471920 | `GameController_modifyBlockAtWorld` | low | At world (x,y) resolve chunk FUN_00434d10, find column entry, adjust block height via FUN_0044e700 |
| 471b60 | `renderEntityLabelBillboard` | low | Render 3D text/label glyphs for entity: transform each char quad by matrix, FUN_004c7250 draw |
| 471d50 | `drawOrientedModelOrTrail` | low | Build orientation matrix from direction vec (sqrt/sin/cos) and render model/segment with many transforms |
| 4772b0 | `GameController::start_game_mode` | low | Init/reset gameplay state and mode-specific tutorial hints (game) |
| 47b010 | `getHoveredWorldItem` | low | Return ptr to item under cursor by projecting item world pos to screen vs mouse box (120px) |
| 47f3c0 | `testAABBvsFrustum_fixed` | low | Fixed-point AABB (param_1,param_2) vs 6 frustum planes at +0x1000fa4 intersection test |
| 47f760 | `testSphereVsFrustum_fixed` | low | Fixed-point sphere (center param_1, radius param_3) vs 6 frustum planes test |
| 47fae0 | `spawnItemAffixDrops` | low | Generate item affix/enchant list entries by rarity buckets (mod 5) via FUN_00449b70 list insert |
| 480e00 | `lookupNestedStringMap` | low | Two-level string-map lookup (FUN_004e3790 hash, FUN_00428db0 cmp) with lazy-init default entry |
| 4821a0 | `GameController::enter_edit_mode` | low | Enter world-edit mode, spawn editor Creature/camera (game) |
| 484350 | `playHitSoundAtPos` | low | Play weapon-hit SFX (hit.wav/blade1.wav/...) at world pos param_2, dist-attenuated volume |
| 487e30 | `GameController::get_selected_char_ptr` | low | Return pointer to selected character entry if index valid (game) |
| 4a6b50 | `GameController_renderCreature` | low | Large creature/model render: builds bone transforms with sin/cos, camera dist, animation; many float stack locals |
| 4bbd80 | `GameController_spawnRibbonEffect` | low | Spawns a swirling ribbon/particle strip: builds per-segment rotated transforms with sin/cos and pushes vertices |
| 4bc760 | `GameController_spawnRibbonEffect2` | low | Variant ribbon/trail effect emitter with extra twist param_9; trig-built transforms per segment |
| 4bd160 | `GameController_spawnEffectMesh` | low | Emits an animated effect mesh (sin/cos/sqrt transforms), similar to particle spawners |
| 4be760 | `GameController_renderDroppedItem` | low | Renders a dropped item/block billboard: fetches block color (FUN_0042f7e0), builds transform, submits quad |
| 4c6f20 | `item_classifyRecursive` | low | Recursively walks an item/effect tree, classifying nodes by type (2/3/4-7) and subtype at +0xd |
| 4c7660 | `Item::get_stack_or_grid_size` | low | Return 0x20 or 0x10 based on item type/subtype bytes (game) |
| 4c7d20 | `Item::get_type_color` | low | Return RGBA color for item type/subtype (game) |
| 4dc8e0 | `GameController_copyEntityState` | low | Deep-copies entity/world state: multiple list clones and field copies (FUN_004dc4e0/5b0/680) |
| 4e2d90 | `container_operation` | low | Container operation combining insert/resize helpers |
| 588250 | `GameController_MatchInputBinding` | low | Game: scans input/action bindings against the current key/button event, storing or firing a matched binding |
| 59d640 | `Terrain::computeBiomeColor` | low | Computes terrain/vegetation RGBA (param_7) by blending many constants against temperature/humidity/height noise |
| 5a0bf0 | `GameController::updateHeldObjectOnMove` | low | Map-lookup two keys (param_1,param_1+8) vs end(+4); update held-object (+0xb8) counters +0x194, copy to +0x1024/0x1030 |
| 5a7eb0 | `Creature::findPathToTarget` | low | A* pathfinding: seeds start from pos+RNG offset, distance-tests goal (0x1458 radius), builds open/closed sets and node list |
| 5eeee0 | `fixedpoint_vec_subtract` | low | Computes 16.16 fixed-point per-axis difference into param_1 from param_2..param_5 inputs |
| 602440 | `hash_or_index_compute` | low | Computes an index/hash from param_1/param_2 (no callees); used by lock wrapper |
| 6091a0 | `get_int_stub` | low | Returns an int (trivial getter) |
| 60a9f0 | `store_object_ref` | low | Stores an object reference/pointer into param_1 |
| 60aa50 | `get_int_stub_b` | low | Returns an int (trivial getter) |
| 62baf0 | `Widget_layoutChildren` | low | Lays out children via FUN_0062bb90 + FUN_006295a0 |
| 62c570 | `Widget_measureContentEntry` | low | Entry to content measure via FUN_0062bb90 |
| 62f630 | `GameController_getWidgetSize` | low | Gets widget size via FUN_0062b510 (cookie-guarded) |
| 62f660 | `GameController_getWidgetSize2` | low | Gets widget size via FUN_0062b510 (variant) |
| 62f720 | `get_widget_child` | low | Returns a child/field pointer (no callees) |
| 6303d0 | `object_buildWithRefcount` | low | Builds object with refcount (FUN_0046d550) via FUN_00630220 |
| 630ae0 | `compute_pair_field` | low | Computes/writes a pair field from param_2 into param_1 (no callees) |
| 636560 | `Node::hit_test_point_recursive` | low | Recursive pick/hit-test: transform cursor point into node space, test bounds & children, honor visibility flags |
| 6504e0 | `Node::destroy_and_unregister` | low | Full node teardown: detach from focus/capture, recursively destroy children, unregister attribute/shape/font nodes from CS lists, free (big) |
| 6527f0 | `GameController::on_mouse_down` | low | Handle mouse-press: pick widget under cursor, set capture/focus, dispatch enter/press callbacks (big) |
| 652940 | `GameController::on_mouse_up` | low | Handle mouse-release: dispatch release/click callbacks, update captured widget |
| 652c10 | `GameController::set_hover_widget` | low | Update hovered/entered widget (+0xd4/c4), dispatch leave/enter callbacks to old/new widget hierarchies (big) |
| 653360 | `GameController::position_popup` | low | Position a popup/tooltip near cursor, clamped to screen extents (+0x10c/+0x110), toggling its clip flag |
| 653770 | `GameController::load_widget_file` | low | Open a widget resource file by extension (.CUB etc), log 'read', deserialize into widget via 6555d0 or model loader (big) |
| 6555d0 | `GameController::deserialize_widget_tree` | low | Deserialize a full widget/scene tree root from istream: creates attribute maps, dispatches per-type readers, builds hierarchy (huge) |
| 657f80 | `SmoothMeshShape::deserialize_v2` | low | Deserialize plasma::SmoothMeshShape (name, vertex buffer, transforms, sub-attributes) from istream (big switch) |
| 658630 | `TextShape::deserialize` | low | Deserialize plasma::TextShape (font, text string, matrix) from istream chunk stream (big) |
| 659fb0 | `Font::advancePenX` | low | Adds param_1 to accumulator at +0xe8, stores it at +0xe4, clears +0x10, then calls FUN_006372a0. |
| 6816c0 | `SceneLoader::ctor` | low | Constructs loader/deserialization context: default-inits eight string fields (0x20..0x58), stores params, builds a pair-vector |
| 681c70 | `PlasmaGraphics::loadDisplay` | low | Main scene/display deserializer: validates "PlasmaGraphics" magic, throws plasma::Exception on mismatch, dispatches Shape/Widget types |

## sqlite (182)

| addr | proposed name | conf | purpose |
|---|---|---|---|
| 51d070 | `sqlite3_versionFunc` | high | SQL sqlite_version() implementation: result_text of library version "3.7.15.2" |
| 51e390 | `attachFunc` | high | SQLite 3.7.15.2 attachFunc: identified by compiler-independent string-anchor match (5 unique-owner string anchors, score 28.0). Anchors: attached databases must use the same text encoding as main database\|cannot ATTACH database within transaction\|database %s is already in use\|database is already attached |
| 521a60 | `sqlite3_blob_open` | high | SQLite 3.7.15.2 sqlite3_blob_open: identified by compiler-independent string-anchor match (6 unique-owner string anchors, score 30.0). Anchors: cannot open %s column for writing\|cannot open view: %s\|cannot open virtual table: %s\|foreign key |
| 525e30 | `sqlite3_errmsg` | high | sqlite3_errmsg: return UTF-8 error message string |
| 528c60 | `sqlite3FkActionName` | high | fkey actionName: map FK action code (6-9) to string RESTRICT/SET NULL/SET DEFAULT/CASCADE else NO ACTION |
| 52e230 | `blobSeekToRow` | high | SQLite 3.7.15.2 blobSeekToRow: identified by compiler-independent string-anchor match (3 unique-owner string anchors, score 15.0). Anchors: cannot open value of type %s\|integer\|no such rowid: %lld |
| 52f200 | `sqlite3_pragma_temp_store` | high | changeTempStorage: handles PRAGMA temp_store, rejects change inside a transaction ("temporary storage cannot...") |
| 52f2b0 | `sqlite3_integck_append_msg` | high | checkAppendMsg: formats and appends a message to the integrity_check StrAccum report |
| 52f410 | `checkList` | high | SQLite 3.7.15.2 checkList: identified by compiler-independent string-anchor match (3 unique-owner string anchors, score 15.0). Anchors: %d of %d pages missing from overflow list starting at %d\|failed to get page %d\|freelist leaf count too big on page %d |
| 52f610 | `checkPtrmap` | high | SQLite 3.7.15.2 checkPtrmap: identified by compiler-independent string-anchor match (2 unique-owner string anchors, score 10.0). Anchors: Bad ptr map entry key=%d expected=(%d,%d) got=(%d,%d)\|Failed to read ptrmap key=%d |
| 52f6a0 | `checkRef` | high | SQLite 3.7.15.2 checkRef: identified by compiler-independent string-anchor match (2 unique-owner string anchors, score 10.0). Anchors: 2nd reference to page %d\|invalid page number %d |
| 52f720 | `checkTreePage` | high | SQLite 3.7.15.2 checkTreePage: identified by compiler-independent string-anchor match (11 unique-owner string anchors, score 55.0). Anchors: Child page depth differs\|Corruption detected in cell %d on page %d\|Fragmentation of %d bytes reported as %d on page %d\|Multiple uses for byte %d of page %d |
| 5338d0 | `corruptSchema` | high | SQLite 3.7.15.2 corruptSchema: identified by compiler-independent string-anchor match (2 unique-owner string anchors, score 10.6). Anchors: %s - %s\|c0e09560d26f0a6456be9dd3447f5311eb4f238f\|database corruption at line %d of [%.10s]\|malformed database schema (%s) |
| 533c50 | `sqlite3_createTableStmt` | high | Synthesizes a 'CREATE TABLE ...' text from a Table's column list |
| 533f40 | `sqlite3_defragmentPage` | high | Compacts a btree page's free space, relocating cells; corrupt-checks offsets |
| 534c40 | `sqlite3_explainComposite` | high | EXPLAIN QUERY PLAN row for compound select (UNION/EXCEPT/INTERSECT), emits OP_Explain |
| 534f70 | `explainOneScan` | high | SQLite 3.7.15.2 explainOneScan: identified by compiler-independent string-anchor match (12 unique-owner string anchors, score 60.0). Anchors: %s (rowid<?)\|%s (rowid=?)\|%s (rowid>? AND rowid<?)\|%s (rowid>?) |
| 5352d0 | `sqlite3_explainTempTable` | high | Emits EXPLAIN 'USE TEMP B-TREE FOR %s' plan row |
| 539780 | `sqlite3_btree_free_space` | high | Frees a cell region on a btree page and coalesces adjacent freeblocks; 'database corruption' |
| 53d620 | `lookupName` | high | SQLite 3.7.15.2 lookupName: identified by compiler-independent string-anchor match (4 unique-owner string anchors, score 24.0). Anchors: %s: %s\|%s: %s.%s\|%s: %s.%s.%s\|ambiguous column name |
| 53e4b0 | `multiSelect` | high | SQLite 3.7.15.2 multiSelect: identified by compiler-independent string-anchor match (4 unique-owner string anchors, score 22.0). Anchors: LIMIT clause should come after %s not before\|ORDER BY clause should come after %s not before\|SELECTs to the left and right of %s do not have the same number of result columns\|UNION |
| 53ecd0 | `multiSelectOrderBy` | high | select.c: compile compound SELECT that has ORDER BY |
| 540a20 | `newDatabase` | high | btree.c: format a fresh page1 ('SQLite format 3' magic header) |
| 540ff0 | `openStatTable` | high | SQLite 3.7.15.2 openStatTable: identified by compiler-independent string-anchor match (2 unique-owner string anchors, score 14.0). Anchors: CREATE TABLE %Q.%s(%s)\|DELETE FROM %Q.%s WHERE %s=%Q\|sqlite_stat1\|tbl,idx,stat |
| 547b70 | `selectExpander` | high | SQLite 3.7.15.2 selectExpander: identified by compiler-independent string-anchor match (4 unique-owner string anchors, score 22.0). Anchors: %s.%s\|no such table: %s\|no tables specified\|sqlite_subquery_%p_ |
| 548980 | `selectOpName` | high | select.c: return operator name string for compound op |
| 5490f0 | `sqlite3AddColumn` | high | SQLite 3.7.15.2 sqlite3AddColumn: identified by compiler-independent string-anchor match (2 unique-owner string anchors, score 10.0). Anchors: duplicate column name: %s\|too many columns on %s |
| 549280 | `sqlite3AddDefaultValue` | high | build.c: set column default ('not constant' error) |
| 549420 | `sqlite3AddPrimaryKey` | high | SQLite 3.7.15.2 sqlite3AddPrimaryKey: identified by compiler-independent string-anchor match (2 unique-owner string anchors, score 10.0). Anchors: AUTOINCREMENT is only allowed on an INTEGER PRIMARY KEY\|table "%s" has more than one primary key |
| 5496d0 | `sqlite3AlterBeginAddColumn` | high | SQLite 3.7.15.2 sqlite3AlterBeginAddColumn: identified by compiler-independent string-anchor match (3 unique-owner string anchors, score 15.0). Anchors: Cannot add a column to a view\|sqlite_altertab_%s\|virtual tables may not be altered |
| 5498e0 | `sqlite3AlterFinishAddColumn` | high | SQLite 3.7.15.2 sqlite3AlterFinishAddColumn: identified by compiler-independent string-anchor match (5 unique-owner string anchors, score 25.6). Anchors: Cannot add a NOT NULL column with default value NULL\|Cannot add a PRIMARY KEY column\|Cannot add a REFERENCES column with non-NULL default value\|Cannot add a UNIQUE column |
| 549b90 | `sqlite3AlterRenameTable` | high | SQLite 3.7.15.2 sqlite3AlterRenameTable: identified by compiler-independent string-anchor match (5 unique-owner string anchors, score 27.6). Anchors: UPDATE "%w".%s SET sql = sqlite_rename_parent(sql, %Q, %Q) WHERE %s;\|UPDATE "%w".sqlite_sequence set name = %Q WHERE name = %Q\|UPDATE sqlite_temp_master SET sql = sqlite_rename_trigger(sql, %Q), tbl_name = %Q WHERE %s;\|sqlite_master |
| 549ed0 | `sqlite3AnalysisLoad` | high | analyze.c: load index stats from sqlite_stat1 into schema |
| 54abe0 | `sqlite3AuthRead` | high | auth.c: authorize column read ('ROWID' pseudo-column) |
| 54acc0 | `sqlite3AuthReadCol` | high | SQLite 3.7.15.2 sqlite3AuthReadCol: identified by compiler-independent string-anchor match (2 unique-owner string anchors, score 12.0). Anchors: access to %s.%s is prohibited\|access to %s.%s.%s is prohibited\|authorizer malfunction |
| 54b750 | `sqlite3BeginTransaction` | high | build.c: emit BEGIN transaction opcodes |
| 54b890 | `sqlite3Parser` | high | SQLite 3.7.15.2 sqlite3Parser: identified by compiler-independent string-anchor match (8 unique-owner string anchors, score 41.9). Anchors: AFTER\|BEFORE\|cannot create %s trigger on view: %S\|cannot create INSTEAD OF trigger on table: %S |
| 54d880 | `sqlite3BtreeIntegrityCheck` | high | SQLite 3.7.15.2 sqlite3BtreeIntegrityCheck: identified by compiler-independent string-anchor match (3 unique-owner string anchors, score 15.0). Anchors: Outstanding page count goes from %d to %d during this analysis\|Page %d is never used\|Pointer map page %d is referenced |
| 551270 | `sqlite3CreateForeignKey` | high | SQLite 3.7.15.2 sqlite3CreateForeignKey: identified by compiler-independent string-anchor match (3 unique-owner string anchors, score 15.0). Anchors: foreign key on %s should reference only one column of table %T\|number of columns in foreign key does not match the number of columns in the referenced table\|unknown column "%s" in foreign key definition |
| 551790 | `sqlite3CreateIndex` | high | SQLite 3.7.15.2 sqlite3CreateIndex: identified by compiler-independent string-anchor match (11 unique-owner string anchors, score 58.9). Anchors: BINARY\|CREATE%s INDEX %.*s\|INSERT INTO %Q.%s VALUES('index',%Q,%Q,#%d,%Q);\|conflicting ON CONFLICT clauses specified |
| 552ca0 | `sqlite3DropIndex` | high | SQLite 3.7.15.2 sqlite3DropIndex: identified by compiler-independent string-anchor match (3 unique-owner string anchors, score 15.6). Anchors: DELETE FROM %Q.%s WHERE name=%Q AND type='index'\|index associated with UNIQUE or PRIMARY KEY constraint cannot be dropped\|no such index: %S\|sqlite_master |
| 552e90 | `sqlite3DropTable` | high | SQLite 3.7.15.2 sqlite3DropTable: identified by compiler-independent string-anchor match (4 unique-owner string anchors, score 20.9). Anchors: sqlite_\|sqlite_master\|sqlite_stat\|sqlite_temp_master |
| 553490 | `sqlite3EndTable` | high | SQLite 3.7.15.2 sqlite3EndTable: identified by compiler-independent string-anchor match (5 unique-owner string anchors, score 27.6). Anchors: CREATE %s %.*s\|CREATE TABLE %Q.sqlite_sequence(name,seq)\|TABLE\|UPDATE %Q.%s SET type='%s', name=%Q, tbl_name=%Q, rootpage=#%d, sql=%Q WHERE rowid=#%d |
| 553e40 | `sqlite3ExprAssignVarNumber` | high | SQLite 3.7.15.2 sqlite3ExprAssignVarNumber: identified by compiler-independent string-anchor match (2 unique-owner string anchors, score 10.0). Anchors: too many SQL variables\|variable number must be between ?1 and ?%d |
| 554e20 | `sqlite3ExprCodeTarget` | high | SQLite 3.7.15.2 sqlite3ExprCodeTarget: identified by compiler-independent string-anchor match (3 unique-owner string anchors, score 15.0). Anchors: RAISE() may only be used within a trigger-program\|misuse of aggregate: %s()\|unknown function: %.*s() |
| 55b750 | `sqlite3InitOne` | high | SQLite 3.7.15.2 sqlite3InitOne: identified by compiler-independent string-anchor match (2 unique-owner string anchors, score 12.6). Anchors: SELECT name, rootpage, sql FROM '%q'.%s ORDER BY rowid\|attached databases must use the same text encoding as main database\|sqlite_master\|sqlite_temp_master |
| 55d020 | `sqlite3JoinType` | high | SQLite 3.7.15.2 sqlite3JoinType: identified by compiler-independent string-anchor match (3 unique-owner string anchors, score 15.0). Anchors: RIGHT and FULL OUTER JOINs are not currently supported\|naturaleftouterightfullinnercross\|unknown or unsupported join type: %T %T%s%T |
| 55d730 | `sqlite3LocateTable` | high | SQLite 3.7.15.2 sqlite3LocateTable: identified by compiler-independent string-anchor match (2 unique-owner string anchors, score 14.0). Anchors: %s: %s\|%s: %s.%s\|no such table\|no such view |
| 561270 | `sqlite3Pragma` | high | SQLite 3.7.15.2 sqlite3Pragma: identified by compiler-independent string-anchor match (49 unique-owner string anchors, score 247.0). Anchors: Safety level may not be changed inside a transaction\|auto_vacuum\|busy_timeout\|cache_size |
| 564800 | `sqlite3RunParser` | high | SQLite 3.7.15.2 sqlite3RunParser: identified by compiler-independent string-anchor match (2 unique-owner string anchors, score 10.0). Anchors: interrupt\|unrecognized token: "%T" |
| 5654f0 | `sqlite3Select` | high | SQLite 3.7.15.2 sqlite3Select: identified by compiler-independent string-anchor match (5 unique-owner string anchors, score 25.0). Anchors: DISTINCT\|GROUP BY\|ORDER BY\|only a single result allowed for a SELECT that is part of an expression |
| 567240 | `sqlite3SrcListAppendFromTerm` | high | SQLite 3.7.15.2 sqlite3SrcListAppendFromTerm: identified by compiler-independent string-anchor match (2 unique-owner string anchors, score 10.0). Anchors: USING\|a JOIN clause is required before %s |
| 567880 | `sqlite3StartTable` | high | SQLite 3.7.15.2 sqlite3StartTable: identified by compiler-independent string-anchor match (3 unique-owner string anchors, score 17.6). Anchors: sqlite_master\|sqlite_sequence\|sqlite_temp_master\|table %T already exists |
| 568810 | `sqlite3TwoPartName` | high | SQLite 3.7.15.2 sqlite3TwoPartName: identified by compiler-independent string-anchor match (2 unique-owner string anchors, score 10.0). Anchors: corrupt database\|unknown database %T |
| 568b40 | `sqlite3Update` | high | SQLite 3.7.15.2 sqlite3Update: identified by compiler-independent string-anchor match (2 unique-owner string anchors, score 10.0). Anchors: no such column: %s\|rows updated |
| 56c9c0 | `sqlite3VdbeExec` | high | SQLite 3.7.15.2 sqlite3VdbeExec: identified by compiler-independent string-anchor match (15 unique-owner string anchors, score 78.6). Anchors: SELECT name, rootpage, sql FROM '%q'.%s WHERE %s ORDER BY rowid\|abort at %d in [%s]: %s\|cannot change %s wal mode from within a transaction\|cannot commit - no transaction is active |
| 573170 | `sqlite3VdbeExpandSql` | high | SQLite 3.7.15.2 sqlite3VdbeExpandSql: identified by compiler-independent string-anchor match (2 unique-owner string anchors, score 11.0). Anchors: %!.15g\|'%.*q'\|zeroblob(%d) |
| 5771f0 | `sqlite3VtabFinishParse` | high | SQLite 3.7.15.2 sqlite3VtabFinishParse: identified by compiler-independent string-anchor match (3 unique-owner string anchors, score 15.6). Anchors: CREATE VIRTUAL TABLE %T\|UPDATE %Q.%s SET type='table', name=%Q, tbl_name=%Q, rootpage=0, sql=%Q WHERE rowid=#%d\|name='%q' AND type='table'\|sqlite_master |
| 57c2a0 | `sqlite3VdbeHalt` | high | SQLite 3.7.15.2 sqlite3VdbeHalt: identified by compiler-independent string-anchor match (4 unique-owner string anchors, score 20.0). Anchors: %s-mjXXXXXX9XXz\|-mj%06X9%02X\|MJ collide: %s\|MJ delete: %s |
| 524a00 | `sqlite3_backup_step` | med | sqlite3_backup_step: copy pages src->dest btree |
| 525400 | `sqlite3_backup_finish` | med | sqlite3_backup_finish: teardown backup, unlock |
| 528cb0 | `sqlite3VdbeDupErrMsg` | med | Duplicate a stored error/description string into db memory and append it to the auto-cleanup pointer array |
| 528d20 | `sqlite3DbPtrArrayAppend` | med | Grow a db-allocated pointer array (count at +0x30, ptr at +0x34) appending a pointer, freeing all on realloc fail |
| 529020 | `sqlite3ExprBuildAndAppend` | med | Build a two-operand expression node (op 0x4c), check tree depth limit, append it to an ExprList |
| 529890 | `sqlite3VdbeAllocateCursor` | med | Allocate a VdbeCursor of param_3 fields (+ optional KeyInfo/btree cursor space), zero it and link into aMem region |
| 529970 | `sqlite3WhereAllocateIndexInfo` | med | allocateIndexInfo: count usable WHERE terms/columns for a vtab cursor and allocate sqlite3_index_info, error 'out of memory' |
| 529ae0 | `sqlite3BtreeFreeSpace` | med | freeSpace: free a cell's byte range on a b-tree page, coalescing freeblocks, defragmenting if needed, corruption checks |
| 52a0c0 | `sqlite3FkGenerateChildScan` | med | Emit VDBE ops to open/scan a child table for FK enforcement (OpenRead 0x94, register setup, opcode 0x6b) |
| 52a250 | `sqlite3FkScanChildren` | med | fkScanChildren: generate VDBE bytecode probing child FK rows via index or full scan, incrementing/decrementing FK counter |
| 52b4f0 | `sqlite3FkLookupParent` | med | fkLookupParent: locate parent table index and generate FK constraint check code by delegating to scan-children |
| 52b6b0 | `sqlite3BtreeReassemblePage` | med | Rebuild a b-tree page: memcpy param_2 cells into the page body, write cell-pointer array and free/content offsets |
| 52bbb0 | `sqlite3BtreeBalance` | med | balance: driver loop dispatching to balance_quick/nonroot/deeper on the b-tree cursor page stack, with stack cookie |
| 52bd40 | `sqlite3BtreeBalanceDeeper` | med | balance_deeper: allocate a new child page, copy root cell content into it, make root point to child |
| 52be70 | `sqlite3BtreeBalanceNonroot` | med | balance_nonroot: redistribute cells among sibling b-tree pages (large arrays, reassemble, corruption checks, stack cookie) |
| 52cd80 | `sqlite3BtreeBalanceQuick` | med | balance_quick: fast append of a new cell to a rightmost b-tree page by allocating one new sibling page |
| 52e030 | `sqlite3VdbeMemReleaseIfB` | med | If statement not aborting and Mem type char is 'b', apply default and free the Mem's dynamic buffer at +0xc |
| 52e3b0 | `sqlite3BtreeAllocatePage` | med | allocateBtreePage: allocates/reuses a btree page, skipping pointer-map pages during autovacuum |
| 52e610 | `sqlite3BtreeCursor_init` | med | btreeCursor: initializes a BtCursor struct and links it into the shared btree cursor list |
| 52e690 | `sqlite3BtreeIncrVacuumStep` | med | incrVacuumStep: relocates the last database page toward the free area for incremental vacuum |
| 52eee0 | `sqlite3BtreeRestoreCursorPosition` | med | btreeRestoreCursorPosition: re-seeks a saved-state cursor to its stored key after a tree change |
| 52f080 | `sqlite3VdbeDeleteAuxData` | med | Iterates an aux-data/function object array, calling per-entry destructors and freeing the array |
| 52f130 | `sqlite3BtreeCellSizePtr` | med | cellSizePtr: computes the total on-page size in bytes of a btree cell |
| 530420 | `sqlite3VdbeCloseAllCursors` | med | Cleanup phase of a prepared statement: closes all VdbeCursors, releases pagers, frees sub-frames |
| 530e20 | `sqlite3ExprCodeInteger` | med | codeInteger: emits OP_Integer/OP_Int64/OP_Real for a numeric literal, negating when requested |
| 532120 | `sqlite3ExprCodeInt64` | med | codeInt64: parses a big integer string to i64, stores as OP_Int64 p4 blob, negating when requested |
| 532570 | `sqlite3_name_in_column_list` | med | Case-insensitively tests whether a name occurs in an IdList/column list (returns 1 if present) |
| 5325f0 | `sqlite3ColumnIndex` | med | columnIndex: returns the index of a column name within a Table's column array, or -1 if absent |
| 532740 | `sqlite3_column_type_origin` | med | columnType: resolves a result column's declared type plus origin database/table/column, recursing through subqueries |
| 532b80 | `sqlite3_computeLimitRegisters` | med | Emits VDBE ops for LIMIT/OFFSET registers of a SELECT (offsets 0x48=pLimit,0x4c=pOffset) |
| 5337c0 | `sqlite3_btreeCopyNodePayload` | med | Btree page maintenance: memcpy cell/data areas between page images then reinit page |
| 534100 | `sqlite3_destroyRootPage` | med | Emits VDBE + nested UPDATE sqlite_master SET rootpage to relocate a moved root page |
| 534210 | `sqlite3_destroyTable` | med | Walks table/index roots from largest, calling destroyRootPage for OP_Destroy codegen |
| 5342f0 | `sqlite3_vtabClearRefs` | med | After schema reset, unlinks/frees FKey or vtab back-references pointing at this schema |
| 534780 | `sqlite3_btreeDropCell` | med | Removes a cell from a leaf btree page, shifting cell-pointer array and freeing space |
| 534a60 | `sqlite3_execExecSql` | med | Autovacuum helper: runs SQL rows returned by an outer query, executing each via execSql |
| 534bc0 | `sqlite3_execSql` | med | Prepares, steps to completion, and finalizes a single SQL statement string |
| 534d70 | `sqlite3_explainIndexRange` | med | Builds '(col=? AND ...)' text describing an index range constraint for EXPLAIN |
| 5351c0 | `sqlite3_explainScanTable` | med | Legacy EXPLAIN 'SCAN TABLE %s ... (~%d rows)' row emission via OP_Explain |
| 5368e0 | `sqlite3_btreeCellPayloadPtr` | med | Returns pointer+size to a cursor's current cell payload area, parsing overflow flag |
| 536970 | `sqlite3_memjrnlFlushClose` | med | Flushes remaining in-memory journal buffer via xWrite, then resets/frees the struct |
| 536a00 | `sqlite3_memjrnlCreateChunk` | med | Allocates a sector-sized in-memory journal chunk and initializes write cursor |
| 536a90 | `sqlite3_memjrnlWrite` | med | Copies data into in-memory journal buffer, flushing full buffers to file via xWrite |
| 536b50 | `sqlite3_accessPayload` | med | Reads/writes btree cell payload spanning overflow pages, with corruption checks |
| 536ea0 | `sqlite3_vdbe_code_exprlist_helper` | med | Iterates an ExprList emitting VDBE opcodes (0x7c) into a Vdbe, growing op array as needed |
| 536fb0 | `sqlite3_find_db_by_name` | med | Resolves a database name to schema index; errors 'unknown database %s'/'out of memory' |
| 537450 | `sqlite3_fk_gen_constraint_expr` | med | Builds Expr comparison trees for a foreign-key constraint check; 'foreign key constraint failed' |
| 537e40 | `sqlite3_fk_lookup_parent` | med | Emits VDBE opcodes to look up FK parent row and enforce constraint; 'foreign key constraint failed' |
| 538be0 | `sqlite3_fk_trigger_step_delete` | med | Frees a FK trigger step: releases ExprList, SrcList, nested step and the step itself |
| 538c40 | `sqlite3_pragma_flag_handler` | med | Matches a boolean PRAGMA name ('full_column_names'/'short_column_names') and sets/reads db flag bit |
| 538dd0 | `sqlite3_flatten_subquery` | med | Attempts to flatten a subquery into its parent SELECT after checking many eligibility flags |
| 539430 | `sqlite3_btree_lazy_get_page` | med | Lazily initializes/opens a btree page pointer if currently null |
| 539ac0 | `sqlite3_generate_column_names` | med | Generates result-set column names for a SELECT ('rowid','%s.%s'); sets Vdbe column metadata |
| 539c70 | `sqlite3_generate_column_types` | med | Fills result column declared-type/decltype metadata by evaluating each result expression |
| 539da0 | `sqlite3_fk_action_codegen` | med | Emits VDBE opcodes for a FK action (SET NULL/DEFAULT/CASCADE) via switch on action type |
| 53a0f0 | `sqlite3_codegen_compare_jump` | med | Emits VDBE comparison/jump opcodes (Eq/Ne/Gt/Ge) for an operator with register allocation |
| 53a730 | `sqlite3_pragma_get_auto_vacuum` | med | Parses auto_vacuum PRAGMA argument ('none'/'full'/'incremental') to 0/1/2 |
| 53aa70 | `sqlite3_pragma_get_locking_mode` | med | Parses locking_mode PRAGMA argument ('exclusive'->1/'normal'->0/else -1) |
| 53b530 | `sqlite3_grow_array_by_5` | med | Reallocs a growable record array when count is a multiple of 5, zeroing the new slot |
| 53b7f0 | `sqlite3_ident_put_quoted` | med | Appends an SQL identifier, double-quoting it when it is a keyword or needs escaping |
| 53b8a0 | `sqlite3_dup_string_field` | med | Frees the old string at field +0xd and replaces it with a fresh db-allocated copy |
| 53bd90 | `sqlite3_btree_insert_cell` | med | Inserts a cell into a btree page, updating the cell-pointer array and defragmenting if needed |
| 53bfb0 | `sqlite3_pragma_temp_store_reset` | med | Handles temp_store change: closes temp btree if no transaction, else errors within transaction |
| 53cb90 | `isAlterableTable` | med | alter.c: reject ALTER on system (sqlite_*) tables |
| 544870 | `sqlite3PagerGet` | med | pager.c: public page-fetch wrapper |
| 5448e0 | `sqlite3ExprCodeTarget` | med | expr.c: generate VDBE code evaluating an Expr into a register |
| 545780 | `reloadTableSchema` | med | alter.c: reparse schema for a table after rename ('tbl_name=%Q') |
| 545ce0 | `analyzeAggregate` | med | select.c: register aggregate (DISTINCT aggregates must have exactly one arg) |
| 5461b0 | `resolveOrderByTermToExprList` | med | resolve.c: bind ORDER/GROUP BY term to a result column |
| 5478e0 | `sqlite3CreateColumnExpr` | med | select.c: build TK_COLUMN Expr for a result column ('rowid') |
| 548280 | `generateOutputSubroutine` | med | select.c: emit output subroutine for compound select rows |
| 549fd0 | `sqlite3EndTable` | med | build.c: finalize CREATE TABLE, write schema record |
| 54c3f0 | `sqlite3BtreeBeginTrans` | med | btree.c: begin b-tree transaction (lock+page1) |
| 54cfd0 | `sqlite3PagerOpen2` | med | pager.c: pager open/init continuation |
| 5204d0 | `sqlite3TempStoreName` | low | Return CURDIR-list entry by index if <3 |
| 522940 | `sqlite3BtreeHelper_a` | low | Btree/pager helper (0054d260/005522f0) |
| 523850 | `sqlite3_leaf_stub_e` | low | Leaf helper |
| 525c40 | `sqlite3_leaf_stub_o` | low | Leaf helper |
| 529cd0 | `sqlite3LazyInitField` | low | Lazily initialize field +0x50 by calling an allocator on field +0x20 when it is currently null |
| 5308c0 | `sqlite3_codegen_ternary_func` | low | Emits VDBE code for a 3-argument expression/function (e.g. BETWEEN/replace), releasing temp registers |
| 530be0 | `sqlite3_codegen_subroutine` | low | Emits OP_Gosub(0x34)/OP_Return-style subroutine ops, allocating/reusing a register and label |
| 530f00 | `sqlite3_expr_codegen_helper` | low | Emits a small conditional-jump/copy VDBE sequence when an Expr has an associated register/collation |
| 532250 | `sqlite3_codegen_op_list` | low | Emits a VDBE op (0x83) for each entry of an op list into a subprogram, wiring p4 collation |
| 53b940 | `sqlite3_walk_exprlist_agg` | low | Sets up a Walker with the agg callback and walks an ExprList to adjust aggregate depths |
| 53c7e0 | `sqlite3ExprAffinity` | low | expr.c: return affinity char for an Expr node |
| 53cc90 | `sqlite3ExprDup` | low | expr.c: duplicate an Expr node/tree helper |
| 53de70 | `sqlite3ErrorWithMsg` | low | main.c: format+set error message via snprintf |
| 540990 | `sqlite3ExprIsInteger` | low | expr.c: test/return integer literal value |
| 544bb0 | `sqlite3PagerGetExtra2` | low | pager.c: page extra accessor |
| 545420 | `sqlite3ValueText` | low | vdbemem.c: coerce value to text |
| 545520 | `sqlite3ValueText2` | low | vdbemem.c: coerce value to text variant |
| 545f00 | `sqlite3ExprCodeAndCache` | low | expr.c: evaluate Expr into register with caching |
| 546130 | `sqlite3CheckObjectName` | low | build.c: validate an identifier ('invalid name: %s') |
| 5467e0 | `resolveOutOfRangeError` | low | resolve.c: helper resolving positional ORDER BY term |
| 546df0 | `sqlite3ExprCodeConstants` | low | expr.c: precompute constant subexpressions into registers |
| 546f70 | `sqlite3VdbeMemRelease` | low | vdbemem.c: release Mem contents |
| 546fe0 | `sqlite3VdbeMemSetNull` | low | vdbemem.c: reset Mem to NULL (memset) |
| 547100 | `sqlite3VdbeMemShallowCopy` | low | vdbemem.c: shallow-copy Mem wrapper |
| 547260 | `sqlite3VdbeMemMakeWriteable` | low | vdbemem.c: ensure Mem buffer is writable |
| 548c40 | `sqlite3DbMallocRaw2` | low | malloc.c: db allocation wrapper |
| 548e20 | `sqlite3ExprListSetName` | low | expr.c: set list-item name |
| 548e60 | `sqlite3ExprFunction` | low | expr.c: build a function-call Expr node |
| 548ec0 | `sqlite3PExprAnd` | low | expr.c: build AND Expr node (memset+alloc) |
| 548f50 | `sqlite3PExprOr` | low | expr.c: build boolean Expr node (memset+alloc) |
| 548fe0 | `util::abs_int` | low | Returns absolute value of an int, saturating INT_MIN to INT_MAX |
| 549000 | `sqlite3ExprListAppend` | low | expr.c: append item to ExprList |
| 549060 | `sqlite3SrcListAppend` | low | build.c: append table to SrcList |
| 549230 | `sqlite3AddColumnType` | low | build.c: set type/affinity for current column |
| 54a970 | `sqlite3VtabXXX` | low | vtab.c: small virtual-table helper |
| 54ae60 | `sqlite3AttachXXX` | low | attach.c/build: emit code for a schema op |
| 54c3a0 | `sqlite3PagerXXX2` | low | pager.c: small pager wrapper |
| 54c670 | `sqlite3PagerFree` | low | pager.c: free helper |
| 54c690 | `sqlite3PagerCommit` | low | pager.c: commit-phase wrapper |
| 54c930 | `sqlite3PagerSetPagesize` | low | pager.c: set/adjust page size wrapper |
| 54cac0 | `sqlite3PagerReadFileheader` | low | pager.c: read first N bytes of db header (alloc) |
| 54cbd0 | `pagerSyncHotJournal` | low | pager.c: sync/probe hot journal helper |
| 54cde0 | `sqlite3PagerGetJournalMode2` | low | pager.c: journal-mode accessor |
| 54ce30 | `sqlite3PagerSetJournalMode` | low | pager.c: set journal mode |
| 54ce80 | `sqlite3PagerJournalSizeLimit` | low | pager.c: get/set journal size limit |
| 54cf10 | `sqlite3PagerBackupPtr` | low | pager.c: return backup pointer field |
| 54cf50 | `sqlite3PagerSetCodec` | low | pager.c: install page codec |
| 54cf70 | `sqlite3PagerVfs` | low | pager.c: return pager VFS pointer |
| 54d210 | `sqlite3PagerSetBusyhandler` | low | pager.c: install busy handler wrapper |

## crtstl (35)

| addr | proposed name | conf | purpose |
|---|---|---|---|
| 40bfc0 | `std_allocate` | high | MSVC std::_Allocate: operator_new(n), throws std::_Xbad_alloc on failure |
| 40d240 | `std_filebuf_open` | high | std::basic_filebuf<char>::open: _Fiopen, wires streambuf get/put ptrs, sets codecvt facet |
| 40f650 | `std::wstring::_Allocate` | high | allocate wchar_t buffer (n*2), _Xbad_alloc on fail |
| 43b5e0 | `std::wstring::dtor_free` | high | delete heap buffer of wstring in catch handler |
| 449720 | `db::delete_blob` | high | SQLite prepare/bind/step DELETE FROM blobs WHERE key=? |
| 449920 | `db::update_blob_key` | high | SQLite UPDATE blobs SET key=? WHERE key=? |
| 44b7f0 | `std::_Tree::_Freenode_str` | high | destroy rbtree node w/ string key then free node |
| 457900 | `std::basic_string::_Tidy` | high | Free string heap buffer if >15 cap and reset to empty SSO state |
| 46db10 | `Node_dtor_2strings` | high | Destructor: free two SSO strings (+0x28,+0x10) then delete node |
| 46dc50 | `std::list<T>::_Tidy` | high | Clear list member at this+0x10: relink head, free nodes and head |
| 630a80 | `tree_nodeFree` | high | Frees a tree node (operator_delete); called from destructors/catch handlers |
| 401ff0 | `std_ostream_insert_string` | med | MSVC STL: operator<<(ostream&,string) width/pad, streambuf sputn, sentry |
| 4030e0 | `std_locale_getfacet` | med | MSVC STL: _Getfacet/use_facet<codecvt> lookup, throws bad_cast on miss |
| 4044f0 | `std_filebuf_deleting_dtor` | med | MSVC STL: basic_filebuf<char> scalar deleting destructor |
| 405810 | `std_string_deleting_dtor` | med | Destroys std::string (frees heap buf if cap>0xf, resets SSO fields) then operator_delete(this) |
| 4578a0 | `std::_Tidy_deallocate@catch` | med | SEH cleanup funclet: operator delete of element buffer at +0x11c |
| 4578e0 | `dtor_and_free@catch` | med | SEH cleanup funclet: run member dtor (FUN_0046f990) then operator delete |
| 46daf0 | `std::_Destroy_range@catch` | med | SEH cleanup: destroy vector<string> elements (FUN_00452650) |
| 46eac0 | `std::list<T>::_Unlink` | med | Unlink one list node from doubly-linked list, decrement size |
| 46eaf0 | `std::list<T>::erase` | med | Unlink and operator_delete one list node |
| 46eb20 | `std::list<std::string>::erase` | med | Unlink node, free embedded std::string, delete node |
| 486050 | `std::list<T>::pop_back` | med | Unlink and delete node before head (pop back) |
| 4cb2c0 | `std::basic_filebuf<char>::`scalar deleting dtor'` | med | Filebuf dtor plus optional operator_delete of object |
| 4e34f0 | `node_free` | med | operator delete a container node |
| 4e3530 | `node_release_free` | med | Release node payload (FUN_004e2a00) then operator delete |
| 40217e | `std_ostream_insert_cleanup` | low | MSVC STL: SEH cleanup funclet for ostream insert (setstate/_Osfx) |
| 402350 | `std_fputc_nofail` | low | MSVC CRT: fputc wrapper returning success bool (filebuf overflow) |
| 4494b0 | `obj::init_and_inflate` | low | init object then zlib-inflate stream into it (game wrapper) |
| 44e120 | `serialize_struct_0x28` | low | write struct fields to stream buffer (game writer) |
| 44e280 | `serialize_struct_small` | low | write small struct fields to stream buffer (game writer) |
| 44e340 | `serialize_struct_creatures` | low | serialize struct with creature/id vectors to buffer (game writer) |
| 469590 | `World::streamChunksAroundPlayer` | low | GAME (mislabeled lib): stream/load region chunks in radius around player under locks |
| 47f940 | `GameController::validate_selected_zone` | low | Check selected world/zone/region indices are valid (game) |
| 4a5710 | `GameController::load_skill_tooltip` | low | Load skill description/level text from resource1.dat (game UI) |
| 4a62c0 | `GameController::load_specialization_text` | low | Load class specialization tooltip strings from resource1.dat |

## AdaptionWidget (28)

| addr | proposed name | conf | purpose |
|---|---|---|---|
| 58c440 | `Matrix4_Invert` | high | Game/math: inverts a 4x4 float matrix via Gauss-Jordan elimination with partial pivoting (thiscall in_ECX) |
| 636be0 | `Node::clear_dirty_flag_2e` | high | Recursively clear byte flag +0x2e on populated attribute slots and descend children |
| 636cb0 | `AdaptionWidget::relayout` | high | Clear dirty flags (636be0) then run recursive layout/adaption pass (636cd0) |
| 6371b0 | `AdaptionWidget::compute_local_transform` | high | Compute node world matrix (+0x88) from style matrix (+0x38 +0x1b0) and parent (+0x48), 4x4 copies |
| 637260 | `AdaptionWidget::recompute_transforms_recursive` | high | Recursively call compute_local_transform (6371b0) over node subtree when visible |
| 64ed40 | `Registry::push_node_locked_0x7c` | high | Under CS, append list node to AdaptionWidget list at +0x7c |
| 64efe0 | `Widget::set_flags_word` | high | Store param_1 into flags dword at +200 |
| 653620 | `Widget::dispatch_event_callback` | high | If widget enabled and has handler (+0x44), fetch registry callback (FUN_00468910) and invoke it |
| 659cf0 | `AdaptionWidget::clear_hover` | high | Clear captured widget (+200=0) and notify hover change (FUN_00652c10 with +0xd4/d8) |
| 6278a0 | `AdaptionWidget_clampScrollToContent` | med | Clamps scroll offset (local_10/local_c) to child content bounds, updates scrollbars, notifies (vfunc) |
| 629300 | `AdaptionWidget_layoutRecursive` | med | Recursively lays out widget subtree (self-call); returns via cookie guard |
| 6295a0 | `AdaptionWidget_applyScrollLayout` | med | Applies scroll offset param_1 and lays out children (FUN_0062b510 size, FUN_0062c5b0 bounds) |
| 62b510 | `AdaptionWidget_getContentSize` | med | Computes content/preferred size into param_1 (FUN_0062c5b0 bounds union) |
| 62b920 | `AdaptionWidget_setCaption` | med | Sets widget caption/title text ('caption'), frees old string (operator_delete) |
| 62bb90 | `AdaptionWidget_measureContent` | med | Measures content bounds recursively (FUN_0062ba50) and applies (FUN_0062c5b0) |
| 62c5b0 | `AdaptionWidget_computeBoundsUnion` | med | Computes union AABB of child bounds via FUN_0062cfd0 |
| 62cfd0 | `AdaptionWidget_accumulateChildBounds` | med | Accumulates/expands bounds rect over children (min/max float ops) |
| 62d7f0 | `AdaptionWidget_computeLayoutBounds` | med | Computes layout bounds via FUN_0062cfd0 accumulation |
| 636cd0 | `AdaptionWidget::layout_recursive` | med | Recursive layout/adaption: resolve +0x44, recompute children (FUN_00664c60), local transform, descend |
| 636f70 | `AdaptionWidget::compute_max_content_width` | med | Recursively compute max content width by querying attribute keyframe arrays (FUN_00661d90) across slots/children |
| 661d90 | `AnimMap::findValueByKey` | med | Looks up a string key in a map and returns the value stored at node+0x28, or 0 when not found |
| 662860 | `Widget::layoutAspectFit` | med | Aspect-fit layout: computes scale ratio between content and container dimensions then re-positions via setAlignmentOffset |
| 662f00 | `Widget::applyAlignmentOffset` | med | Clamps an alignment factor to [0,1] and offsets the widget along the active axis by that fraction of the size delta |
| 663eb0 | `Widget::destroyTailSlot` | med | Releases a string element unless it is the current tail slot of the vector |
| 664c60 | `Widget::updateAnimations` | med | Iterates a list of animation controllers advancing each to param time; if any changed, fires a vtable notify callback |
| 62b430 | `AdaptionWidget_getScrollFlag` | low | Returns a scroll/state flag (no callees) |
| 62ba50 | `Widget_measureChildrenRecursive` | low | Recursively measures child widgets (self-call, FUN_006371b0) |
| 630970 | `get_widget_state` | low | Returns a widget state/int field (no callees) |

## Speech (23)

| addr | proposed name | conf | purpose |
|---|---|---|---|
| 4e03c0 | `QuestText_copyTree_b` | high | Copies a QuestText red-black tree (nodes via FUN_004e0440), fixing leftmost/rightmost |
| 4e3900 | `Speech::map_erase_node` | high | Removes one map/set node with red-black rebalance and frees it; throws on invalid iterator |
| 4e4000 | `Speech::map_erase_node_qt` | high | Erase single map node with RB rebalance, runs QuestText::ctor_2, frees string(+4/+9) and node |
| 4d6d10 | `xml_memoryPool_ctor` | med | Initialize parser memory pool object then allocate first arena (FUN_004d72f0) |
| 4d7020 | `xml_node_findChildByName` | med | Search element's child list for a node whose name matches wide-string key |
| 4d70d0 | `xml_node_findAttributeByName` | med | Search element's attribute list for attribute whose name matches wide-string key |
| 4d72f0 | `xml_memoryPool_initArena` | med | Reset pool and allocate/link the initial 0x8000 arena |
| 4d77d0 | `xml_memoryPool_freeAll` | med | Free all pool arenas and buffers back to CRT free (PTR_free) |
| 4d7b00 | `xml_document_parseWithEncoding` | med | Parse XML document: detect encoding, transcode input, run node-tree parser |
| 4d8410 | `xml_parse_setjmpWrapper` | med | setjmp3 error frame around node-tree parse; returns {errcode,offset} |
| 4e16b0 | `std_list_resize_insert` | med | Resize/insert into list with element allocation (FUN_004e42c0 cleanup) |
| 4e3060 | `map::insert_string_key2` | med | Variant of insert_string_key using FUN_0040f680 to build key; inserts node if absent |
| 4e3480 | `node_alloc` | med | Allocate a container node (operator new) |
| 4e3840 | `Speech::map_erase_range` | med | Erases all nodes in [param_2,param_3); if whole tree clears to sentinel, else per-node erase |
| 4e3f40 | `Speech::map_erase_range2` | med | Erase range variant using FUN_004e4000 node-erase with QuestText dtor |
| 4d6d40 | `xml_iterator_notEqual` | low | Compare two 8-byte iterator/cursor pairs for inequality |
| 4d6d60 | `xml_iterator_isValid` | low | Return whether iterator/pointer is non-null (0 or -1) |
| 4d6d70 | `xml_iterator_deref_advance` | low | Load current node into out and advance pool iterator to next (+0x18) |
| 4d70a0 | `xml_node_firstChild` | low | Return first child node of element (or nulls) |
| 4d7150 | `xml_document_firstElementNode` | low | Return first element/data node in document, else default sentinel PTR |
| 4d7840 | `xml_node_ctor_setParent` | low | Init node: value=0, parent=current pool node |
| 4d7860 | `xml_document_firstNode` | low | Return first node of document root (or null) |
| 4d7bc0 | `xml_document_root` | low | Return document root node pointer, else default sentinel |

## World (20)

| addr | proposed name | conf | purpose |
|---|---|---|---|
| 455d80 | `std::_Sort<0x10>` | high | Introsort for 16-byte elements, int key |
| 456010 | `std::_Sort_heap<0x10>` | high | Heapsort finalize for 16-byte elements (via _Adjust_heap) |
| 4563d0 | `std::_Unguarded_partition<0x10>` | high | Hoare partition, 16-byte elements, int key |
| 46e780 | `std::vector<T16>::reserve` | high | Grow 16-byte-element vector capacity if below requested |
| 58d6f0 | `Pair_CopyFromRefs` | high | Game: copies two dword values dereferenced from param_1/param_2 into a 2-field pair at in_ECX |
| 58e9e0 | `Identity_ReturnArg` | high | Game: identity accessor returning its argument unchanged |
| 59fe70 | `Terrain::sampleBlockAt_fwd` | high | Thin wrapper forwarding first two fields of param_2 to FUN_005a64b0 |
| 458df0 | `std::list<T>::list(const&)` | med | list copy-ctor: buy head (node 0x30) then _Insert_range FUN_004544d0 |
| 458f30 | `std::list<T>::list(const&)` | med | list copy-ctor: buy head (node 0x78) then _Insert_range FUN_00453ff0 |
| 458fd0 | `std::list<T>::list(const&)` | med | list copy-ctor: buy head (node 0x50) then _Insert_range FUN_004540c0 |
| 477d20 | `std::list<std::string>::_Erase_node` | med | Unlink node, free embedded string(+0x8), delete |
| 4cdaa0 | `EntityState_serializeToBuffer` | med | Master: serialize changed entity fields into a chunk list then flatten to output buffer |
| 4e5a20 | `format_object_singular_name` | med | Formats singular localized name for creature/object from record ('singular'); handles name-vs-generic |
| 5a64b0 | `WorldMap::lookupTileValue2` | med | Map lower_bound by (x,y) vs end at +0x80012c; return value struct {0,0,7} from node +0x18 or raise error; twin of 5a5240 |
| 5a6550 | `NameGen::generateRegionName` | med | Lazily init syllable tables (reon/mala/rion...) guarded by DAT_0076dbb8, then build random region/place name indexing tables at +0x80028c/+0x800290 |
| 4690a0 | `World::updateNearbyEntities` | low | GAME (mislabeled lib): spatial scan of chunk grid under lock, sort candidates, dispatch; timeGetTime/CriticalSection |
| 469c10 | `World::updateActiveChunks` | low | GAME (mislabeled lib): large per-frame chunk/entity update (alloca, timeGetTime, sort) |
| 46f490 | `GameController::check_tile_walkable` | low | Grid adjacency/walkability test via FUN_00434d10 (game logic) |
| 5943b0 | `World_MapInsertChunk` | low | Game/STL: inserts a chunk record into a World map keyed by (x,y), building the node and rebalancing (SEH) |
| 5944c0 | `World_MapInsertKeyed` | low | Game/STL: inserts a keyed record into a World map using string/blob comparison (FUN_00428db0) |

## WorldInfo (13)

| addr | proposed name | conf | purpose |
|---|---|---|---|
| 5a4780 | `WorldGrid::freeCellPtr` | high | In 1024x1024 pointer grid (base +0x10002f), if cell non-null: lock two CS, null entry, operator_delete the object |
| 5a4800 | `WorldGrid::destroyCellObject` | high | Grid cell (base +0x2f) removal: run cleanup ctor_17, lock CS, null entry, then virtual destructor call (**vt)(1) |
| 5a4890 | `WorldGrid::destroyBlockObjectAt` | high | Two-level world grid: region idx (coord>>6) at +0xbc, block idx (coord&63) at +0x10018; null cell under locks, virtual-destroy object |
| 44b880 | `WorldInfo_mapLowerBound` | med | RB-tree lower_bound by int+string key (memcmp 0040c590) returning candidate node |
| 5e4850 | `WorldInfo_generateBiomeContent` | med | WorldInfo build entry (ctor-called): populates biome with spawns, terrain features and decorations |
| 5f0ce0 | `WorldInfo_placeStructure` | med | Places a building/structure: allocates object, computes footprint, appends via vector grow + ctors |
| 5f4b50 | `WorldInfo_mapInsertEntry` | med | Inserts an entry into a WorldInfo map/list via FUN_00608a20 |
| 5f4ba0 | `WorldInfo_lookupCell` | med | Looks up/updates a cell via FUN_005c4320/FUN_005c3950 |
| 5f56c0 | `WorldInfo_scatterObjectsInArea` | med | Scatters objects across an area using sqrt spacing and FUN_005effa0 placement |
| 5f8530 | `WorldInfo_vectorElementAt` | med | Returns/accesses a WorldInfo vector element by index/flag (external:12e copy) |
| 5f8590 | `WorldInfo_vectorAppend` | med | Appends/moves a vector element (external:12e) |
| 5f9340 | `WorldInfo_sampleTerrainHeight` | med | Returns terrain height/noise (float10) at coord with FUN_005eea60 nearest and FUN_00487da0 |
| 5f9f70 | `WorldInfo_rotateAndPlace` | med | Computes a rotated position (cos/sin via FUN_0059fc90) and places/samples at it |

## XAudio2Engine (11)

| addr | proposed name | conf | purpose |
|---|---|---|---|
| 623100 | `riff_findChunkInMemory` | high | Scans an in-memory RIFF/WAV buffer for a chunk id (param_2), returns data ptr/size |
| 6231e0 | `riff_findChunkInFile` | high | Seeks a WAV file (SetFilePointer/ReadFile) for RIFF chunk param_2, returns offset/size |
| 623340 | `riff_readFromMemory` | high | Copies param_3 bytes from in-memory RIFF stream at offset param_4 (memcpy, bounds-checked) |
| 6233a0 | `riff_readFromFile` | high | Seeks file to param_4 and reads param_3 bytes (SetFilePointer/ReadFile) into param_2 |
| 623710 | `XAudio2_loadSound` | med | Loads/parses a WAV/audio asset (vfunc_1): reads headers and inits decoder via FUN_006271b0 |
| 623ee0 | `XAudio2_decodeStream` | med | Decodes/streams audio (vfunc_2) via FUN_00626740 into memset buffer |
| 625a60 | `XAudio2_resetDecoder` | med | Resets/clears decoder state buffers (memset, FUN_006d12e0/006d0290 tables) |
| 626740 | `XAudio2_decodeFrame` | med | Decodes one audio frame (FUN_006260c0 setup + FUN_00625670 synth), 64-bit shifts |
| 626de0 | `XAudio2_initDecodeState` | med | Initializes decode state via FUN_00626ab0 |
| 6271b0 | `XAudio2_setupDecoder` | med | Decoder setup entry forwarding to FUN_00627120 |
| 626a70 | `codec_readHeaderFields` | low | Reads/parses two header fields (no callees) |

## QuestText (10)

| addr | proposed name | conf | purpose |
|---|---|---|---|
| 4d9b10 | `QuestText_copyTree` | high | Copies a QuestText std::map red-black tree, then fixes leftmost/rightmost pointers |
| 4d9b90 | `QuestText_copyTreeNode` | high | Recursively copies a red-black tree subtree (left/right) into destination map |
| 4e0fe0 | `QuestText_insertHint_str` | high | QuestText std::map insert-with-hint for string key; compares and rebalances via FUN_004e0940 |
| 4e1480 | `QuestText_insertUnique_str` | high | QuestText std::map insert-unique for string key; finds slot, checks duplicate, rebalances via FUN_004e0940 |
| 4da050 | `std_map_insert_unique` | med | std::map lower_bound + insert-unique using wide-string comparator (FUN_00428db0) |
| 4da770 | `cube_QuestTextNode_destroyTree` | med | Recursively destroy QuestTextNode tree: free child maps and node lists |
| 4da800 | `QuestText_isPunctuation` | med | Return 1 if wide char is punctuation (. : - , ; ! ? / ( )) |
| 4da850 | `cube_QuestText_parseTemplate` | med | Parse quest-text template string into QuestTextNode tree, splitting {..}/[..]/word tokens |
| 4e1830 | `QuestText::member_ctor` | med | Constructs a QuestText container member: allocs sentinel via FUN_0046d520, then FUN_004d9b10 init |
| 4e3550 | `QuestText::delete_node` | med | Destroys one QuestText tree node: runs dtor, frees string if cap>7, operator_delete node |

## ChatWidget (8)

| addr | proposed name | conf | purpose |
|---|---|---|---|
| 660b60 | `TextRender::computeScaledSize` | high | Computes clamped scaled glyph width/height (max 1000) and derived spacing from a transform matrix and scale factor |
| 68f1b0 | `ChatWidget::setBindTransform` | high | Sets bind pos/size (param_2, default identity 0x10000) and offset (param_3) into widget layout obj+0x80, sets dirty flags |
| 439530 | `ChatWidget::clearText` | med | Frees SSO string at +0x168 (cap>7) and clears, then list::clear 00439680, deletes buffer +0x160 |
| 439680 | `list::clear` | med | Clears intrusive list: unlink nodes, reset head self-links, size=0, free node buffer |
| 65e8d0 | `ChatWidget::measureChatText` | med | Wrapper: under CS measures a text block (FUN_0065ded0) with optional truncation, scales returned min/max by cell width/height. |
| 6605c0 | `TextRender::configureSize` | med | Chooses fixed vs scaled text sizing: computes scaled size then applies, or falls through to transform path; stores render params |
| 6606f0 | `TextRender::setTransform` | med | Builds a 16.16 fixed-point 2x2 transform from a matrix, computes sqrt scale, sets FT transform and caches transformed glyphs |
| 660d50 | `TextRender::layoutAndWrap` | med | Walks a UTF-16 string measuring per-glyph advances/kerning, handles space/newline/CR word-wrap by inserting break chars |

## Creature (7)

| addr | proposed name | conf | purpose |
|---|---|---|---|
| 43c8a0 | `list::allocNode0x134` | high | operator_new(0x134) self-linked node (Creature-sized list node); _Xbad_alloc on fail |
| 411e50 | `Creature_init` | med | Zeroes a large Creature/entity struct (fields up to +0x223*4), sets base ptr at [0] |
| 43c790 | `Creature::partialDtor` | med | Frees SSO string at +0x28 (cap>0xf) then RB-tree range 0043f040 at +0x1c, deletes buffer |
| 446330 | `Player::resetFull` | med | Full player/controller reset: destroys/reinits all containers, timers, transforms, buffers |
| 4465c0 | `Player::resetState` | med | Resets player physics/stat members and memsets large regions (+0x2f0 0xe38, +0x1128) |
| 449b70 | `list::makeNodeWrapper` | low | Creates list node via 0044b770 then inits payload 0040ee70 unless error (-8) |
| 44be40 | `GameWorld::deserialize_state` | low | deserialize world/entity state from packet buffer (game, big) |

## Interface (6)

| addr | proposed name | conf | purpose |
|---|---|---|---|
| 40f4a0 | `std::wstring::_Tidy` | high | free heap wstring buffer if cap>7, reset to SSO |
| 43cff0 | `stat::calcArmor` | med | Computes armor/defense: base ×2^rand terms plus per-slot element bonuses (0x530/0x648/0x760/0x878) |
| 43ea40 | `stat::calcManaRegen` | med | Computes mana/spirit regen: base 2^ terms /0.1 plus per-slot rune bonuses (0x530..0xcd8) |
| 4467a0 | `stat::calcSpirit` | med | Computes spirit/magic stat: base 2^ terms + per-slot rune bonuses (004c7af0) |
| 43e9e0 | `Creature::compute_scale_factor` | low | compute float scale from status-effect list (game) |
| 446150 | `Equipment::sum_slot_values` | low | sum float contributions across equipment slots by type tag (game) |

## CharacterStyleWidget (6)

| addr | proposed name | conf | purpose |
|---|---|---|---|
| 642a20 | `CharacterStyleWidget::rebuild_mesh` | high | Rebuild smooth mesh (FUN_0063fec0) then notify refcount if flag set |
| 642a50 | `CharacterStyleWidget::set_lod_level` | high | Clamp LOD/quality level to [0,6], store at +0x2c9, optionally rebuild |
| 650260 | `SmoothMeshShape::new_instance` | high | Factory: operator_new(0xc34) + plasma::SmoothMeshShape::ctor_0 |
| 6503e0 | `NamedObject::new_instance_0x160` | high | Factory: operator_new(0x160) + plasma::NamedObject::ctor_4 |
| 427b40 | `Widget_connectRecursive` | med | Recursively traverses widget child tree; where key matches, wires a CharacterStyleWidget member-function callback |
| 66b200 | `CharacterStyleWidget::buildEdgeGraph` | low | Rebuilds widget geometry: clears vertex/index vectors (0x158/0x100/0x1b0/0x2b8), walks polygon list at 0x86c inserting edges into maps |

## CombatBehavior (6)

| addr | proposed name | conf | purpose |
|---|---|---|---|
| 596ca0 | `CombatBehavior::isHostileTo` | high | Returns whether two creatures may fight based on faction byte +0x60 and flags +0x124 (0x20 bit) |
| 444bf0 | `combat::findTopThreat` | med | Traverses threat RB-tree (+0x13a4) returning (id,val) pair with highest weight (+6) |
| 4456a0 | `CombatBehavior::chooseAttack` | med | Core combat AI: computes windup/variant, checks resources/target, picks next attack id and sub-costs |
| 5957c0 | `CombatBehavior::pushHitEntry` | med | Builds a positional record from param_2/param_1 and appends node to a std::list at param_3 (count +0x5c) |
| 5a0970 | `CombatController::acquireNearbyTargets` | med | Insert self into list then iterate entities; distance<8 (64.0=8^2) test, mark aggro/interest (0.5=0x3f000000) |
| 42c520 | `struct::clearFields` | low | Zeroes fields at +0,+4,+8,+0x10,+0x14 (init small struct/state block) |

## ChunkBuffer (6)

| addr | proposed name | conf | purpose |
|---|---|---|---|
| 42c900 | `vec3i64::scaleFixed` | high | Scales three int64 members by (p1,p2) 64-bit then /0x10000 (16.16 fixed-point vec3 multiply) |
| 59aaf0 | `VoxelColumn::at` | high | Bounds-checked indexed accessor into an array at in_ECX+0x18 (4-byte elems, count +0x1c); returns dummy on OOB |
| 46eeb0 | `ChunkBuffer_pushQuadFaces` | med | Push 6 face/vertex indices (param_2, +1,+2,+2,+3) via FUN_0066add0 |
| 59a0e0 | `VoxelChunk::propagateSunlight` | med | Flood light/AO pass over a voxel column region: seeds sky light 0xff then spreads to neighbor cells |
| 4c1510 | `ChunkBuffer_sampleVoxelColorAO` | low | Samples smoothed voxel color+ambient-occlusion over a 3x3x3 neighborhood; tone-maps and blends base color |
| 5c03f0 | `ChunkBuffer::loadAndNotify` | low | Calls FUN_00688b20(p1,p2); if result != -8 invokes FUN_00459ab0(p3); returns the code |

## Global (5)

| addr | proposed name | conf | purpose |
|---|---|---|---|
| 4c8ae0 | `WinMain` | high | Entry: RegisterClass/CreateWindow 'Cube World', init D3D/audio/input, run loop |
| 4ce6e0 | `Options_loadFromCfg` | high | Load game settings from options.cfg: parse key/value lines (fullscreen,resolutionX/Y,volumes,language...) |
| 4c8720 | `App::init_direct3d` | med | Create Direct3D9 device, D3D9Engine and CubeShader (game) |
| 4c85f0 | `App::render_frame` | low | Per-frame tick: update timing, handle resize, Present (game) |
| 4c8940 | `App::reset_device` | low | Reset/resize D3D device and swap chain on resolution change (game) |

## SmoothMeshShape (4)

| addr | proposed name | conf | purpose |
|---|---|---|---|
| 428ac0 | `vectorReserve8` | high | std::vector reallocate to param_1 capacity, 8-byte elements: new/copy/free |
| 428ba0 | `vectorReserve16` | high | std::vector reallocate to param_1 capacity, 16-byte elements: new/copy/free |
| 6504c0 | `Object::release_if_nonnull` | high | Call virtual release/destructor (vtbl[0]) on object if pointer non-null |
| 411be0 | `math::mat3_transform_point2d` | med | 2D projective transform of point by 3x3-ish matrix (game math) |

## SpeechWidget (3)

| addr | proposed name | conf | purpose |
|---|---|---|---|
| 4e5ec0 | `SpeechWidget::dtor` | high | SpeechWidget destructor (vfunc_0): frees text string at +0x1a8, sub-widget at +0x178, calls Widget base dtor |
| 4e65a0 | `SpeechWidget::render_text` | high | Renders speech-bubble text with typewriter reveal: measures glyphs, advances counters, draws lines via FUN_0065bc70 |
| 627c00 | `SpeechWidget_setBounds` | med | Sets widget bounds/anchors (offsets 0x48..0x54) from param_3/param_4 rects |

## InventoryWidget (2)

| addr | proposed name | conf | purpose |
|---|---|---|---|
| 4c1a10 | `InventoryWidget_dispatchEvent` | high | Recursively walks child widgets, matches focus (FUN_00428db0) and fires a MemberFunctionConnection callback |
| 4c1f80 | `InventoryWidget_dtor` | high | Destructor: frees buffer at +0x198 and intrusive list at +0x17c |

## OptionsWidget (2)

| addr | proposed name | conf | purpose |
|---|---|---|---|
| 4ce660 | `OptionsWidget_initDefaults` | high | Initializes OptionsWidget config fields to defaults (0x32,100,0x50,9,...) |
| 4cf220 | `OptionsWidget_dispatchEvent` | high | Recursively walks child widgets matching focus and fires a MemberFunctionConnection callback |

## Sprite (2)

| addr | proposed name | conf | purpose |
|---|---|---|---|
| 4e6f20 | `Sprite::map_erase_node` | high | Removes one sprite-map node with RB rebalance and frees embedded list(+5) and node |
| 4e6e60 | `Sprite::map_erase_range` | med | Erases sprite map nodes in [param_2,param_3); clears whole tree or per-node via FUN_004e6f20 |

## Spawn (1)

| addr | proposed name | conf | purpose |
|---|---|---|---|
| 428750 | `Spawn_initDefaults` | med | Initializes a Spawn/creature-appearance struct with default color/scale/offset float constants |

## PreviewWidget (1)

| addr | proposed name | conf | purpose |
|---|---|---|---|
| 4d5010 | `PreviewWidget_dtor` | high | Destructor: destroys intrusive list at +0x174 and frees its storage |

## Zone (1)

| addr | proposed name | conf | purpose |
|---|---|---|---|
| 58d970 | `Zone_DestroyObjectRange` | med | Game/STL: destroys a range of Zone objects (stride 0x188 bytes = 0x62 dwords), freeing nested container storage |

## RandomInteractionBehavior (1)

| addr | proposed name | conf | purpose |
|---|---|---|---|
| 59ed30 | `RandomInteractionBehavior::pickObjectAt` | med | Scans a chunk's object list for one whose voxel cell at (param_1,2,3) is solid and AABB contains the point |

## WorldMap (1)

| addr | proposed name | conf | purpose |
|---|---|---|---|
| 601f80 | `WorldMap_ctor` | med | Constructs/initializes WorldMap: allocates discovered-flags arrays and sub-objects ('discovered') |

