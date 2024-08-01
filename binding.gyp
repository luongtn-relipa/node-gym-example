{
  "targets": [
    {
      "target_name": "addon1",
      "sources": ["src/addon_1.cc"],
    },
    {
      "target_name": "addon2",
      "sources": ["src/addon_2.cc"],
      "dependencies": [
        "<!(node -p \"require('node-addon-api').targets\"):node_addon_api",
      ],
    },
    {
      "target_name": "addon3",
      "sources": ["src/test.cpp", "src/addon_3.cc"],
      "dependencies": [
        "<!(node -p \"require('node-addon-api').targets\"):node_addon_api",
      ],
    },
    {
      "target_name": "addon4",
      "sources": ["src/addon_4.cc"],
      "dependencies": [
        "<!(node -p \"require('node-addon-api').targets\"):node_addon_api",
      ],
    },
    {
      "target_name": "addon5",
      "sources": ["src/test.cpp", "src/addon_5.cc"],
      "dependencies": [
        "<!(node -p \"require('node-addon-api').targets\"):node_addon_api",
      ],
    },
    {
      "target_name": "addon6",
      "sources": ["src/test.cpp", "src/addon_6.cc"],
    }
  ]
}
