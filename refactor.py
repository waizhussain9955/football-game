import os
import glob
import re

plugins_dir = r"d:\football-game\Plugins"

# Mapping of module names to their API macro
module_api_map = {
    "ProjectStrikerCore": "PROJECTSTRIKERCORE_API",
    "ProjectStrikerGameplay": "PROJECTSTRIKERGAMEPLAY_API",
    "ProjectStrikerAI": "PROJECTSTRIKERAI_API",
    "ProjectStrikerPhysics": "PROJECTSTRIKERPHYSICS_API",
    "ProjectStrikerAnimation": "PROJECTSTRIKERANIMATION_API",
}

for root, dirs, files in os.walk(plugins_dir):
    for file in files:
        if file.endswith(".h") or file.endswith(".cpp"):
            filepath = os.path.join(root, file)
            
            # Determine which module this file belongs to
            module_name = None
            for mod in module_api_map.keys():
                if f"\\{mod}\\" in filepath or f"/{mod}/" in filepath:
                    module_name = mod
                    break
            
            if module_name:
                api_macro = module_api_map[module_name]
                
                with open(filepath, "r", encoding="utf-8") as f:
                    content = f.read()
                
                # Replace PROJECTSTRIKER_API with the specific module API
                new_content = re.sub(r'PROJECTSTRIKER_API', api_macro, content)
                
                if new_content != content:
                    with open(filepath, "w", encoding="utf-8") as f:
                        f.write(new_content)

print("Refactoring complete.")
