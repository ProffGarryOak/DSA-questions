

import requests
import re
import os
from datetime import datetime

# Calculate day number based on start date
START_DATE = datetime.strptime('21-07-2025', '%d-%m-%Y')
TODAY = datetime.now()
day_num = (TODAY.date() - START_DATE.date()).days + 1
FOLDER = os.path.join(os.path.dirname(__file__), f'Day{day_num}')

def sanitize_filename(title):
    return re.sub(r'[^\w\s-]', '', title).replace(' ', ' ') + '.cpp'

def get_slug_from_url(url):
    match = re.search(r'/problems/([\w-]+)/', url)
    return match.group(1) if match else None

def fetch_leetcode_question(url):
    slug = get_slug_from_url(url)
    if not slug:
        return 'LeetCodeQuestion', 'Invalid LeetCode URL.'
    graphql_url = 'https://leetcode.com/graphql'
    query = {
        "query": "query getQuestionDetail($titleSlug: String!) { question(titleSlug: $titleSlug) { title content } }",
        "variables": {"titleSlug": slug}
    }
    resp = requests.post(graphql_url, json=query, headers={"Referer": url, "Content-Type": "application/json"})
    if resp.status_code != 200:
        return 'LeetCodeQuestion', 'Failed to fetch question.'
    data = resp.json()
    q = data.get('data', {}).get('question', {})
    title = q.get('title', 'LeetCodeQuestion')
    content_html = q.get('content', '')
    # Remove HTML tags for plain text
    content_text = re.sub('<[^<]+?>', '', content_html)
    return title, content_text.strip() or 'Description not found.'

def main():
    url = input('Enter LeetCode question URL: ').strip()
    title, description = fetch_leetcode_question(url)
    filename = sanitize_filename(title)
    filepath = os.path.join(FOLDER, filename)
    os.makedirs(FOLDER, exist_ok=True)
    with open(filepath, 'w', encoding='utf-8') as f:
        f.write('// ' + title + '\n')
        f.write('// ' + url + '\n')
        f.write('//\n')
        for line in description.split('\n'):
            f.write('// ' + line + '\n')
        f.write('\n')
    print(f'Created {filepath}')

if __name__ == '__main__':
    main()
