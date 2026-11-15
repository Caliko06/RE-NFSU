# Remaster texture foundation check (2026-11-14, OWNER: full remaster quality, much lighter, widest device range)
Same 50 textures (47 distinct; 20 cars2, 15 world2, 15 fe2), sample in web/lab/sample50.tsv.
| Path | Download | GPU memory | Phones | Quality (PSNR vs the webp v2 source) | Load cost |
|---|---|---|---|---|---|
| Today: BC7 .dds.gz (web/remaster/bc, world_bc) | 7.04 MB | BC7 (1 B/px) | no (BC7 is desktop only) | 40.6 dB global (cdx angel, census/texlab/ktx2_result.tsv) | none |
| KTX2 UASTC RDO 1.0 + zstd (basisu 2.50) | 6.69 MB (-12 %) | BC7/ASTC | yes | 45.4 dB global | transcode on CPU |
| webp v2 + spark.js 0.1.6 GPU encode (web/lab/spark.html) | 1.24 MB (5.7x less) | BC7 here, ASTC on phones | yes (bc=true astc=true on the Mac) | 44-76 dB per texture, mostly 44-50 | ~1 ms per texture on the M4, 663 ms one-time first use |
Sizes: census/texlab/sizes.tsv (Haiku). Shot: web/plan/shots/spark_lab.png (left source, right after BC7 encode).
Verdict (INFERENCE from 50 textures, one machine): the BC7 pack is the wrong foundation for the public build; KTX2 does not change the weight; webp + GPU encode does.
Open: spark.js license (free for non-commercial use), encode speed on phones, keep the one-time 663 ms out of a race (warm it at boot), the webp has no mips (spark makes them), full-pack sizes not measured.
