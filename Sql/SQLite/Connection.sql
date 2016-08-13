CREATE TABLE "main"."Connection" (
	"ID" INTEGER PRIMARY KEY,
	"Name" TEXT UNIQUE,
	"Hash" TEXT UNIQUE,
	"Active" BOOLEAN DEFAULT 1 CHECK ("Active" IN (0, 1)),
	"Created" UNSIGNED BIGINT DEFAULT (strftime('%s', 'now'))
);
