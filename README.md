# JSON for C++23

## Dependencies

No external Dependencies!

## Adding to your project

```cmake
add_subdirectory(json)
include_directories(json/include)
```

## Creation

```c++
Json json = JsonObject();

json["hello"] = 123.0;
json["json"] = true;
json["for"] = "modern C++";

json["nested"] = JsonObject();
json["nested"]["objects"] = JsonArray();
json["nested"]["objects"].push_back(JsonObject());
json["nested"]["objects"][0] = "and arrays";
```

## Output

```c++
Writer writer("output.json");
writer.Write(json);
```

## Input

```c++
Parser parser("input.json");
Json json = parser.Parse();
```

