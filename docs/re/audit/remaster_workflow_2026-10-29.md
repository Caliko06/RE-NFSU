# Remaster workflow audit, 2026-10-29

## Scope and verdict

Requested by the OWNER through Hermes: launch an independent auditor, identify stale documentation, blockers, bloat and excessive rigidity, write a brief grounded report, and give it to the active Claude lead for comparison and challenge.

The OWNER likes the existing Remaster. Preserve that aesthetic as the product baseline; use the original binary as technical evidence, not as a mandate to remove approved differences. The inspected mode code agrees: `web/mode.js:1-20` keeps Remaster as the default and original as an A/B reference.

Independent subagent: Codex CLI, read-only sandbox, medium reasoning. Audit window: 2026-10-29 21:46:51-21:48:06 UTC, commit `508971f9e053edb7cf5ab1d19a058747980c04a5` at both boundaries. The subagent inspected 29 files; its initial/final working-tree status matched. Hermes independently checked the strongest evidence below. No game, build, tests, exporter, rule edits, commits or session control were performed for the audit. The only repository write by Hermes is this requested report. Current workers may continue changing their own artifacts.

## Five findings for the lead to contrast

### 1. FACT: explicit uncertainty can be counted as verified

Evidence: `census/names_sound.tsv:149`, address `0x53b220`, has `confidence=high` but evidence starts `I:` and expressly says demoted for no second-tool agreement. `tools/census/scoreboard.py:49-53` treats high as named V; `tools/census/names_merge.py:8-13` likewise promotes high to V. This contradicts the meaning of V in `docs/re/RESULTS.md:13` and `docs/re_scoreboard.md:87`.

Impact: confidence in a proposed name and independent verification are being collapsed. At least this concrete row defeats an unqualified verified-total claim. It does not establish that all high rows are wrong.

Minimal proposal, not implemented: give explicit evidence status precedence and keep confidence separate. Determine the affected population before restating V totals. Preserve negative evidence, second-tool qualifications and aliases.

### 2. FACT: active navigation includes stale instructions, not just old statistics

Evidence: `AGENTS.md:9-10` -> `docs/PLAN.md:5-8` -> scoreboard. `docs/re_scoreboard.md:22-24` still says the registry is missing, while `docs/re/canon_db.md:3-6` describes its implementation. Scoreboard section 5 and `docs/re/RESULTS.md:41-43` retain the 1,464-name snapshot. The auditor found the merged `census/names.tsv` still at 1,649 addresses, while component ledgers and `HANDOFF.md:4` have later naming work.

Stronger operational example independently checked by Hermes: `HANDOFF.md:4` says round 9 completed, but its title says three rounds, `:5` lists only early commits, and `:16-18` says next is round 4. `docs/re/NIGHT_BRIEF.md:36-38` retains the quota stop overridden in `docs/re/night_log.md:88,92`. `docs/OPENWORLD.md:103` retains a barricade phase closed by its own OWNER decision at `:150-151`.

Impact, INFERENCE: a fresh session can redo completed work, stop under obsolete guidance or revive a closed phase. Historical snapshots are useful; presenting them through active routing without a supersession marker is the problem.

Minimal proposal: update the current entry points and HANDOFF when authorized, mark snapshots historical, retain the audit trail. Do not create another permanent status hierarchy.

### 3. FACT: batch ownership is not output-file ownership

Evidence: `docs/re/canon_wave.md:8-12` splits work by GC source file but explicitly permits two workers to append to the same system ledger. Its duplicate-address check at `:32-33` is not a serialization mechanism.

Impact, INFERENCE: independent source batches can still share an output file and race a check-before-write or whole-file edit. UNKNOWN: no actual lost append or corruption was established.

Minimal proposal: exclusive output ownership or sequential integration by the orchestrator, reusing existing conventions. Preserve the single writer for apply/export, bounded batches and exact-path staging (`:13-15,34`).

Qualification by Hermes: the subagent also compared three workers with a two-worker rule in the instructions supplied to it. Hermes verified that rule in its Codex/global context, but did not establish that it is a governing rule for the existing Claude sessions. Do NOT present reducing Claude to two workers as a proven requirement without checking applicable authority. Shared-file ownership is the independently grounded concern.

### 4. FACT: current gates prove narrower claims than the prose sometimes gives them

Evidence: `docs/re/RESULTS.md:7-10` calls byte-identical repacking exact format understanding, while `:30,32,39,49` still has inferred semantics. `tools/verify_re.py:63-119` checks selected predicates and reader success. `tools/remaster/score.py:1-5,19-23` measures PSNR and gradient energy, not OWNER preference. A timing gate does not establish good appearance or handling.

Impact, INFERENCE: technical PASS can be mistaken for semantic completeness or product approval. More sharpness can score differently without being a better remaster.

Minimal proposal: label each gate by what it proves and retain OWNER same-scene A/B/play as the visual/feel decision. Preserve tests, binary evidence and timing measurements. Counterevidence worth retaining: `docs/PLAN.md:123-124` already requires inspecting actual output, and `docs/night_re.md:57-60` records an OWNER rejection despite steady timing. Do not add a new comprehensive test prerequisite merely because this audit exists.

### 5. FACT: authorized 100%-RE scope and Remaster delivery are different accounting questions

Evidence: `docs/PLAN.md:5-8` and `docs/re/NIGHT_BRIEF.md:7-16` explicitly authorize RE toward 100%, with 13,739 lifted starts as denominator. `docs/re/canon_db.md:61-62` excludes 888 fragments from naming work through parent accounting. `tools/census/scoreboard.py:18-20,98-108` counts lifted address membership without consulting that parent ledger. `tools/census/names_merge.py:7,30` labels non-Hopper starts as data, which is not proof that every such address is data.

Impact: named, parent-covered, translated, executed and independently checked populations are not interchangeable completion percentages. Source-file placement and inferred system names are also not verified ownership of every mechanism.

Minimal proposal: retain the frozen denominator but make fragment/parent and inferred classification explicit. Maintain two clear questions within existing docs: what RE is accounted for, and what observable Remaster outcome the work enables. No inspected rule requires finishing all executable RE before keeping the current aesthetic. The RE-only freeze limits implementation authority; it does not reject the Remaster.

## Preserve; do not call this bloat

The authorized RE scope, existing Remaster baseline and original A/B mode; bounded/muted runs and save isolation; read-only game/reference data; publishing approval; binary addresses, rejected hypotheses, aliases, coverage bitmaps and honest FAIL results. No evidence here justifies deleting exports, tools or documents wholesale. The demonstrated documentary cost is contradictory active guidance, not file count alone.

## Requested response from Claude lead

Read the cited source lines and compare against current state. For each finding, accept, refute or narrow it, with evidence and reasons. Distinguish recommendations that require the OWNER's decision from straightforward factual documentation corrections. Do not treat this report as authority to stop workers, edit protected rules, change the frozen scope or modify game behavior. The OWNER authorized delivery and critical comparison, not automatic implementation of the audit.

## Complete inventory: independent auditor

Ranges inclusive; full summaries mean the file was parsed for the stated aggregate, not independently validated line by line. These are the 29 files actually content-inspected, not every discovered filename:

| File | Inspection |
|---|---|
| `AGENTS.md` | 1-61 |
| `HANDOFF.md` | 1-20 |
| `docs/PLAN.md` | 1-147 |
| `docs/re/NIGHT_BRIEF.md` | 1-47 |
| `docs/re_scoreboard.md` | 1-110 |
| `docs/re/RESULTS.md` | 1-49 |
| `docs/re/canon_db.md` | 1-69 |
| `docs/re/canon_wave.md` | 1-36 |
| `docs/re/night_log.md` | 1-104 |
| `CLAUDE.md` | 1, instruction indirection |
| `docs/re/audit/external_opus.md` | 1-110 |
| `docs/re/proposals.md` | 1-18 |
| `docs/OPENWORLD.md` | 1-151 |
| `docs/re/coverage_method.md` | 1-44 |
| `docs/driving_patches.md` | 1-21 |
| `docs/night_re.md` | 1-78 |
| `docs/coverage.md` | 1-80, partial |
| `tools/census/scoreboard.py` | 1-122 |
| `tools/verify_re.py` | 1-138 |
| `tools/census/names_merge.py` | 1-32 |
| `tools/remaster/score.py` | 1-33 |
| `web/tune.js` | 1-68 |
| `web/mode.js` | 1-55 |
| `census/names.tsv` | full, 1-1650, aggregate counts |
| `census/names_render.tsv` | full, 1-206, aggregate and qualifying rows |
| `census/names_sound.tsv` | full, 1-400, aggregate and qualifying rows |
| `census/cov/union.json` | full JSON, scalar/list counts |
| `census/difftest.json` | full JSON, scalar/list counts |
| `census/canon/fragments.tsv` | 1-8, schema/sample only |

Root `README.md` was requested but absent. No contents were read. The auditor did not inspect global private instructions or local Claude settings.

## Hermes review and operational provenance

Hermes independently reread `docs/re/canon_wave.md:1-36`, `tools/census/names_merge.py:1-32`, `census/names_sound.tsv:144-155`, `web/mode.js:1-25`, and `HANDOFF.md:1-20`, plus the full auditor return. The scoreboard predicate had already been inspected in the preceding reconciliation; no merge or project-writing script was executed for this audit.

Operational references read to perform delegation/delivery, not audited as project artifacts: the relevant global Codex `AGENTS.md`; Claude global `CLAUDE.md` supplied by automatic discovery; Hermes `SKILLS_CATALOG.md`; `codebase-audits/SKILL.md:1-200`; `codex/SKILL.md:1-151`; account launcher `cli.mjs:1-100`; local Claude changelog search matches concerning ListAgents/SendMessage; recent assistant text in lead session `8b1aeb34-d2c9-4429-ab3f-1b6022a01546`; generated auditor prompt and final response. Private portions of operational references are not reproduced or shared.

Read-only evidence commands: boundary `date -u`; `git rev-parse HEAD`, `git --no-optional-locks rev-parse HEAD`, `git status --short`, `git --no-optional-locks status --short`; targeted `git --no-optional-locks log` for active docs/latest commits; numbered file reads and filename-only discovery; Python `-B` CSV/JSON aggregates and the address-specific `0x53b220` evidence check. No binary claims were independently re-derived. The sandbox denied Git launcher temporary-cache creation and one shell here-document temporary-file operation; the auditor continued without escalation.

Complete raw auditor response, with the expanded command/discovery inventory, is retained as the session's `nfsu-remaster-audit-20261029.raw.md` artifact. Discovery alone is not counted as content review.
