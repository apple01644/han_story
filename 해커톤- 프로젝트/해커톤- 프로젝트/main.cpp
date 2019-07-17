#include "HanStorySystem.hpp"

void Load(EventManager& evt_mng)
{

	//���� ����
	{
		EventMaker e("��������", EventPriority::Highest);

		e->content = "������ ������ �ּ���. �������� �پ��� �������� ������ �����ϰ� ���� �մϴ�.";

		e->CanStart = [&](Gamedata& data) {
			return data.dict["�÷��̾�"] == "";
		};

		{
			EventSelectItemMaker s(e, "����");
			s->content = "������ ������ �������� �پ��� ���͵��� ������ �ֽ��ϴ�.\
�׸��� �ѹݵ��� ������ �����κ��� �����ϰ� �ֽ��ϴ�.";

			s->Effect = [&](Gamedata& data) {
				data.dict["�÷��̾�"] = "����";
				PlayerGive(7, 5, 4, 6, 3, 2);
			};
		}

		{
			EventSelectItemMaker s(e, "�Ŷ�");
			s->content = "�Ŷ�� �ݵ��� ����� ���� �־ �� �����մϴ�.";

			s->Effect = [&](Gamedata& data) {
				data.dict["�÷��̾�"] = "����";
				PlayerGive(4, 4, 3, 4, 6, 4);
			};
		}

		{
			EventSelectItemMaker s(e, "����");
			s->content = "������ �⸧�� �ο����� ������ ������ ��Ը�� ���� �Ʒ��� �� �ִ� ū ��߸� ������ �ֽ��ϴ�.";

			s->Effect = [&](Gamedata& data) {
				data.dict["�÷��̾�"] = "����";
				PlayerGive(6, 4, 4, 3, 7, 2);
			};
		}
	}

	//������ �ӻ���
	{
		EventMaker e("������ �ӻ���", EventPriority::Normal);

		e->content =
			"�ֱ� �ֱ��� �ϳ��� ����� ���ϵž���\n\
�� �������� �ֱ��� ħ���� �������̰� ��ȭ�Ͽ����ϴ�.\n\
�׿� ���� �츮�� ������ �ֱ��� ���������� �ڸ��� \n\
�� �߰� ���Ѻ� �� �ۿ� �����ϴ�.\n\
�츮�� �̸� �������� ��å�� ������ �մϴ�.";

		e->CanStart = [&](Gamedata& data) {
			if (data.dict["�����ֶ�"] == "")
			{
				data.dict["�����ֶ�"] = "���۵�";
				return true;
			}
			else
				return false;
		};

		{
			EventSelectItemMaker s(e, "���� ������� �����϶�!");
			s->content =
				"��������� �����մϴ�.\n\
�ڱ�-3";
			s->CanRun = [&](Gamedata& data) {
				return data.player.res.money >= 3;
			};

			s->Effect = [&](Gamedata& data) {
				data.dict["�����ֶ�"] = "�������";
			};
		}
		{
			EventSelectItemMaker s(e, "�ؾȰ��� ����� ���� �� �ϵ��� �ض�!(�رݷ�)");
			s->content =
				"�رݷ��� ����մϴ�.\n\
�ڱ�-1\n\
�ķ�-2";
			s->CanRun = [&](Gamedata& data) {
				return (data.player.res.money >= 1 && data.player.res.food >= 2);
			};

			s->Effect = [&](Gamedata& data) {
				data.dict["�����ֶ�"] = "���ﵹ��";
				data.dict["�رݷ�"] = "��";
			};
		}
		{
			EventSelectItemMaker s(e, "��ư �Ҹ� ����!");
			s->content =
				"�ƹ� ��� ���� �ʽ��ϴ�.";
			s->Effect = [&](Gamedata& data) {
				data.dict["�����ֶ�"] = "���ﵹ��";
			};
		}
	}

	//�������
	{
		EventMaker e("������ ���� �����", EventPriority::Normal);

		e->content =
			"����������� �ֱ��� ���� ��å�� ����� ���� �Ѿ翡 �𿴽��ϴ�\n\
���� �ڽ��� �ǰ��� �����ϰ� �ֽ��ϴ�. �׷��� ���� ���ָ� ���� �Ǵ��� �ϴ°� ����Դϴ�.";

		e->CanStart = [&](Gamedata& data) {
			if (data.dict["�����ֶ�"] == "�������")
			{
				data.dict["�����ֶ�"] = "���ﵹ��";
				return true;
			}
			else
				return false;
		};

		{
			EventSelectItemMaker s(e, "������ ������ �����ϰ� �Ѵ�.");
			s->content =
				"�״� ��ҿ� ������ ���� ������ ���ĿԽ��ϴ�.\n\
���� �������� �������մϴ�. �׷��� ���� �������� �׷��� ���� ���� �ֽ��ϴ�.\n\
�ڱ�+3\n\
����-3\n\
�η�-1";
			s->CanRun = [&](Gamedata& data) {
				return data.player.res.milli >= 3 && data.player.res.human >= 1;
			};

			s->Effect = [&](Gamedata& data) {
				data.dict["�����ֶ�"] = "���ﵹ��";
				data.player.res.money += 3;
				data.player.res.milli -= 3;
				data.player.res.human -= 1;
			};
		}
		{
			EventSelectItemMaker s(e, "�̼����� ������ �����ϰ� �Ѵ�.");
			s->content =
				"�״� �Ƿӱ�� �ҹ��� ����Դϴ�. �׷��� ���� �Ƿ��� ������� �ʾҽ��ϴ�.\n\
�ڱ�-1\n\
����+2\n\
�η�+1";
			s->CanRun = [&](Gamedata& data) {
				return data.player.res.money >= 1;
			};

			s->Effect = [&](Gamedata& data) {
				data.dict["�����ֶ�"] = "���ﵹ��";
				data.player.res.money -= 1;
				data.player.res.milli += 2;
				data.player.res.human += 1;
			};
		}
		{
			EventSelectItemMaker s(e, "�����ڰ� ���⿡ ���°� ����!");
			s->content =
				"�� �������Ե� �ñ� ���� ����. ���� ���� �����ϰڴ�.";
			s->Effect = [&](Gamedata& data) {
				data.dict["�����ֶ�"] = "���ﵹ��";
			};
		}
	}

	//���ﵹ��
	{
		EventMaker e("���ﵹ��", EventPriority::Normal);

		e->content =
			"�ֱ��� �������� ����ߴٰ� ������ �Խ��ϴ�. �ֱ��� �������� ���� ���� ���� ġ���� �ϴ� \n\
�游 �����ָ�. �ƹ� ���ص� ������ �ʰڴٰ� ����߽��ϴ�.";

		e->CanStart = [&](Gamedata& data) {
			return data.dict["�����ֶ�"] == "���ﵹ��";
		};

		{
			EventSelectItemMaker s(e, "�׵��� ���ƶ�! ���� �� ������ ���°� �и��ϴ�!");
			s->content =
				"���� �ĺ��մϴ�.\n\
����-3\n\
�η�-3\n\
�ķ�-2\n\
��-1";
			s->CanRun = [&](Gamedata& data) {
				return
					data.player.res.milli >= 3 &&
					data.player.res.human >= 3 &&
					data.player.res.food >= 2 &&
					data.player.res.money >= 1;
			};

			s->Effect = [&](Gamedata& data) {
				data.dict["�����ֶ�"] = "�ֿ� ����";
				data.player.res.milli -= 3;
				data.player.res.human -= 3;
				data.player.res.food -= 2;
				data.player.res.money -= 1;
			};
		}
		{
			EventSelectItemMaker s(e, "���� �����ִ� ������ �� ������� ������?\n\
���ص� �� �����ڴٰ� ������� �ʾҴ°�?");
			s->content = "�ֱ����� ���� ���� �ݴϴ�.\n\
�й��մϴ�.";

			s->Effect = [&](Gamedata& data) {
				data.dict["�����ֶ�"] = "��";
			};
		}
		{
			EventSelectItemMaker s(e, "�߱����� �� ���� ��Ű�ڴ�! ������� ���� �˾Ƽ� �غ��ƶ�!");
			s->content =
				"�߱����� �����մϴ�.\n\
";
			s->Effect = [&](Gamedata& data) {
				data.dict["�����ֶ�"] = "���� ����";
			};
		}
	}
}

int main()
{
	EventManager evt_mng;

	Load(evt_mng);

	evt_mng.DefaultRun();
	
	return 0;
}