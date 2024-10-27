CREATE TABLE IF NOT EXISTS "login_info" (
  "id" INTEGER NOT NULL,
  "name" TEXT NOT NULL,
  "secret_id" TEXT NOT NULL,
  "secret_key" TEXT NOT NULL,
  "remark" TEXT,
  "timestamp" integer NOT NULL,
  PRIMARY KEY ("id"),
  CONSTRAINT "uk_secret_id" UNIQUE ("secret_id"),
  CONSTRAINT "uk_name" UNIQUE ("name")
);
