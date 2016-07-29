CREATE TABLE "main"."Authorization" (
	"ID" INTEGER PRIMARY KEY,
	"Hash" TEXT UNIQUE,
	"Admin" BOOLEAN DEFAULT 0 CHECK ("Admin" IN (0, 1)),
	"SuperAdmin" BOOLEAN DEFAULT 0 CHECK ("SuperAdmin" IN (0, 1)),
	"Active" BOOLEAN DEFAULT 1 CHECK ("Active" IN (0, 1)),
	"Created" UNSIGNED BIGINT DEFAULT (strftime('%s', 'now'))
);
