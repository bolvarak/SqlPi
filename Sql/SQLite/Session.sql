CREATE TABLE "main"."Session" (
	"ID" INTEGER PRIMARY KEY,
	"Hash" TEXT UNIQUE,
	"Expires" UNSIGNED BIGINT DEFAULT 600,
	"Active" BOOLEAN DEFAULT 1 CHECK ("Active" IN (0, 1)),
	"Created" UNSIGNED BIGINT DEFAULT (strftime('%s', 'now'))
);
