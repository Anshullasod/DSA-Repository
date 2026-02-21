import os

def count_cpp_files():
    total_count = 0
    # Ye "." puri repository ko scan karega
    for root, dirs, files in os.walk("."):
        # In folders ko ignore karenge taki galat counting na ho
        if any(ignored in root for ignored in [".git", ".github", ".vscode"]):
            continue
        for file in files:
            if file.endswith(".cpp"):
                total_count += 1
    return total_count

def update_readme(count):
    with open("README.md", "r", encoding="utf-8") as f:
        content = f.read()

   # Script ke andar ye likho
start_marker = ""
end_marker = ""
    
    start_idx = content.find(start_marker) + len(start_marker)
    end_idx = content.find(end_marker)
    
    if start_idx != -1 and end_idx != -1:
        # Naya text jo README mein dikhega
        stats_text = f"\n### 🚀 Total Problems Solved (LeetCode + Local): **{count}**\n"
        new_content = content[:start_idx] + stats_text + content[end_idx:]
        
        with open("README.md", "w", encoding="utf-8") as f:
            f.write(new_content)

if __name__ == "__main__":
    count = count_cpp_files()
    update_readme(count)
    
