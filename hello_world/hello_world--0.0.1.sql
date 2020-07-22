CREATE FUNCTION hello_world()
RETURNS text
LANGUAGE plpgsql IMMUTABLE STRICT
  AS $$
    BEGIN
    RETURN('Hello, world!');
    END;
  $$;
